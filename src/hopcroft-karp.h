#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#ifndef HK_H
#define HK_H

const int NUL       = 0;
const int MAX_SIZE  = 100000;
const int INF       = 1000000;

class HopcroftKarp {
 private:
    std::vector<int> graph[MAX_SIZE];
    int l, r;
    int m[MAX_SIZE];
    int dist[MAX_SIZE];

    bool bfs();
    bool dfs(int);

 public:
    void reset();
    void set(int _nodes_left, int _nodes_right, std::vector<std::pair<int, int> > _edge_indices);
    void run();
};
#endif
