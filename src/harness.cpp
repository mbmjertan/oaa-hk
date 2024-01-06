#include <vector>
#include <utility>
#include <cmath>
#include "harness.h"

long long int benchmark(HopcroftKarp &hk, bool useNanoseconds)
{
    auto start = std::chrono::high_resolution_clock::now();
    hk.run();
    double time = 0;
    auto stop = std::chrono::high_resolution_clock::now();
    if (useNanoseconds)
    {
        time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
        //std::cout<<time<<std::endl;
    }
    else
    {
        time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    };
    return time;
}

void generateTestingData(HopcroftKarp &hk, int leftNodes, int rightNodes, int edgeLogic)
{
    std::vector<std::pair<int, int> > edges;
    int totalNodes = rightNodes + leftNodes - 1;
    int iterations = 0;
    for (int i = 0;
         i < leftNodes && ((edgeLogic == 1 && iterations < floor(sqrt(totalNodes))) || (edgeLogic == 0)); 
         i++)
    {
        for (int j = leftNodes;
            j < totalNodes && ((edgeLogic == 1 && iterations < floor(sqrt(totalNodes))) || (edgeLogic == 0));
            j++)
        {
            std::pair<int, int> edge{i, j};
            edges.push_back(edge);
            iterations++;
        }
    }
    hk.reset();
    hk.set(leftNodes, rightNodes, edges);
}
