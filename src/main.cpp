#include <stdio.h>
#include "hopcroft-karp.cpp"
#include "harness.cpp"
int main(int argc, char **argv)
{
    if (argc != 6)
    {
        printf("[prvi test - broj vrhova] [prvi test - broj iteracija] [prvi test - koje logike? 0, 1, 2 - obje] [drugi test - broj iteracija] [drugi test - logika]");
        return 1;
    }
    int firstTestVertexCountMax = atoi(argv[1]);
    int firstTestIterationCount = atoi(argv[2]);
    int firstTestLogicConfig = atoi(argv[3]);
    int secondTestIterationCount = atoi(argv[4]);
    int secondTestLogic = atoi(argv[5]);
    HopcroftKarp hk;
    long long int time;
    // csv sintaksa: broj vrhova, broj lijevih bridova, broj desnih bridova, pristup, vrijeme
    for (int i = 6; i < firstTestVertexCountMax; i++)
    {
        for (int j = 0; j < firstTestIterationCount; j++)
        {
            // E = V_1 x V_2, |V| = i, |V_1,2| = i/2 => |E| = i^2/4
            if (firstTestLogicConfig != 1) {
                generateTestingData(hk, i / 2, i / 2, 0);
                time = benchmark(hk, true);
                printf("%d, %d, %d, 0, %lld\n", i, i / 2, i / 2, time);
            }

            // |E| = floor(sqrt(V))
            if (firstTestLogicConfig != 0) {
                generateTestingData(hk, i / 2, i / 2, 1);
                time = benchmark(hk, true);
                printf("%d, %d, %d, 1, %lld\n", i, i / 2, i / 2, time);
            }
        }
    }

    for (int j = 0; j < secondTestIterationCount; j++) // broj iteracija
    {
        int l = secondTestLogic;
        generateTestingData(hk, 325, 325, l);
        time = benchmark(hk, true);
        printf("%d, %d, %d, %d, %lld\n", 650, 325, 325, l, time);

        // generateTestingData(hk, 350, 300, l);
        // time = benchmark(hk, true);
        // printf("%d, %d, %d, %d, %lld\n", 650, 350, 300, l, time);

        // generateTestingData(hk, 300, 350, l);
        // time = benchmark(hk, true);
        // printf("%d, %d, %d, %d, %lld\n", 650, 300, 350, l, time);

        generateTestingData(hk, 500, 500, l);
        time = benchmark(hk, true);
        printf("%d, %d, %d, %d, %lld\n", 1000, 500, 500, l, time);

        // generateTestingData(hk, 700, 300, l);
        // time = benchmark(hk, true);
        // printf("%d, %d, %d, %d, %lld\n", 1000, 700, 300, l, time);

        generateTestingData(hk, 1250, 1250, l);
        time = benchmark(hk, true);
        printf("%d, %d, %d, %d, %lld\n", 2500, 1250, 1250, l, time);

        // generateTestingData(hk, 1000, 1500, l);
        // time = benchmark(hk, true);
        // printf("%d, %d, %d, %d, %lld\n", 2500, 1000, 1500, l, time);

        generateTestingData(hk, 2500, 2500, l);
        time = benchmark(hk, true);
        printf("%d, %d, %d, %d, %lld\n", 5000, 2500, 2500, l, time);

        // generateTestingData(hk, 3000, 2000, l);
        // time = benchmark(hk, true);
        // printf("%d, %d, %d, %d, %lld\n", 5000, 3000, 2000, l, time);

        generateTestingData(hk, 4000, 4000, l);
        time = benchmark(hk, true);
        printf("%d, %d, %d, %d, %lld\n", 8000, 4000, 4000, l, time);

        // generateTestingData(hk, 2000, 6000, l);
        // time = benchmark(hk, true);
        // printf("%d, %d, %d, %d, %lld\n", 8000, 2000, 6000, l, time);

        // generateTestingData(hk, 4000, 6000, l);
        // time = benchmark(hk, true);
        // printf("%d, %d, %d, %d, %lld\n", 10000, 4000, 6000, l, time);

        generateTestingData(hk, 5000, 5000, l);
        time = benchmark(hk, true);
        printf("%d, %d, %d, %d, %lld\n", 10000, 5000, 5000, l, time);
    }
}
