#include "hopcroft-karp.h"

/**
 * Resetira interne strukture algoritma.
*/
void HopcroftKarp::reset() {
    for (int i = 0; i < MAX_SIZE; i++) {
        dist[i] = NUL;
        m[i] = NUL;
    }
}

/**
 * Postavlja graf za zadan broj lijevih i desnih čvorova te vektor bridova reprezentiranih kao par indeksa bridova.
 * Ova funkcija smatra da bridovi i na lijevoj i desnoj strani su indeksirani od 1. Lijevom odnosno desnom stranom
 * bipartitnog grafa podrazumijevamo particije čvorova iz definicije.
 * @param int _nodes_left Broj čvorova na lijevoj strani.
 * @param int _nodes_right Broj čvorova na desnoj strani.
 * @param std::vector<std::pair<int, int>> _edge_indices Vektor parova indeksa čvorova na lijevoj ([0]) odnosno desnoj ([1]) strani grafa.
*/
void HopcroftKarp::set(int _nodes_left, int _nodes_right, std::vector<std::pair<int, int> > _edge_indices) {
    l = _nodes_left;
    r = _nodes_right;
    int total_edges = _edge_indices.size();
    
    for(int i = 1; i<=total_edges; i++) {
        std::pair<int, int> edge = _edge_indices[i];
        int lhs = edge.first;
        int rhs = edge.second;
        rhs += l;
        graph[lhs].push_back(rhs);
        graph[rhs].push_back(lhs);
    }

}

/**
 * Provodi BFS korak algoritma, tražeći postoji li augmentirajuć put za trenutno sparivanje i generirajući udaljenosti.
 * Inicijalno prolazi kroz sve nesparene čvorove i = 1, ..., l na lijevoj strani grafa i dodaje ih u red obilaska.
 * Uparene čvorove označi kao beskonačne udaljenosti.
 * Prolazi kroz red obilaska BFS-om tako da:
 * - počne od iz reda obilaska dohvaćenog nesparena čvora i (na lijevoj strani)
 * - prolazi kroz sve njegove susjede (na desnoj strani) j
 * - ako mu je neki susjed j (na desnoj strani) sparen s nekim čvorovom h na lijevoj strani
 * - - ažurira udaljenost h
 * - - dodaje h u red obilaska
 * - vraća kao povratnu vrijednost postoji li za trenutno sparivanje augmentirajuć put u grafu
 * @return bool postoji li augmentirajuć put u grafu za trenutno sparivanje?
*/
bool HopcroftKarp::bfs() {
    std::queue<int> queue;
    for(int i = 1; i <= l; i++) {
        if(m[i] == NUL) {
            dist[i] = 0;
            queue.push(i);
        } else {
            dist[i] = INF;
        }
    }
    
    dist[NUL] = INF;

    while(!queue.empty()) {
        int left = queue.front();
        queue.pop();
        if(left != NUL) {
            for (auto right : graph[left]) {
                if (dist[m[right]] == INF) {
                    dist[m[right]] = dist[left] + 1;
                    queue.push(m[right]);
                }
            }
        }
    }
    return (dist[NUL] != INF);
}

/**
 * Provodi DFS korak algoritma, provodeći sparivanja za dani čvor i na lijevoj strani.
 * Prolazi kroz sve čvorove j susjedne čvoru i (svi su na desnoj strani), nalazi
 * neki najkraći (prema udaljenosti iz BFS-a) vrhovno disjunktan put i sparuje čvorove.
 * @param int left Indeks čvora na lijevoj strani.
 * @return bool Prihvat ili odbacivanje kandidata za sparivanje.
*/
bool HopcroftKarp::dfs(int left) {
    if (left != NUL) {
        for (auto right : graph[left]) {
            if (dist[ m[right] ] == dist[ left ] + 1) {
                if (dfs(m[right])) {
                    m[left] = right;
                    m[right] = left;
                    return true;
                }
            }
        }
        dist[left] = INF;
        return false;
    }
    return true;
}

/**
 * Provodi sami algoritam na klasnim svojstvima definiranom grafu.
*/
void HopcroftKarp::run() {
    int matching_length;
    while(bfs()) { // dok god BFS daje da postoji augmentirajuć put
        for(int i = 0; i <= l; i++) {
            if(m[i] == NUL && dfs(i)) { // DFS-om pronađi put i provedi sparivanja
                matching_length++;
            }
        }
    }
}
