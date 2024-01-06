#include <vector>
#include <utility>
#include <cmath>
#include "hopcroft-karp.h"
#ifndef HARNESS_H
#define HARNESS_N
long long int benchmark(HopcroftKarp &hk, bool useNanoseconds = false);
void generateTestingData(HopcroftKarp &hk, int leftNodes, int rightNodes, int edgeLogic);
#endif
