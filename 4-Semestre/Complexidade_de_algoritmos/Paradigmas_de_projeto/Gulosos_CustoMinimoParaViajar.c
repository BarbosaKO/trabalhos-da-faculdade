#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


    int minnode(int n, int keyval[], bool mstset[])
    {
        int mini = INT_MAX;
        int mini_index;
        for (int i = 0; i < n; i++)
        {
            if (mstset[i] == false && keyval[i] < mini)
            {
                mini = keyval[i], mini_index = i;
            }
        }
        return mini_index;
    }

    void findcost(int n, int city[][5])
    {
        int parent[n];
        int keyval[n];
        bool mstset[n];
        for (int i = 0; i < n; i++)
        {
            keyval[i] = INT_MAX;
            mstset[i] = false;
        }

        parent[0] = -1;
        keyval[0] = 0;

        for(int i = 0; i < n - 1; i++)
        {
            int u = minnode(n, keyval, mstset);
            mstset[u] = true;
            for(int v = 0; v < n; v++)
            {
                if(city[u][v] && mstset[v] == false && city[u][v] < keyval[v])
                {
                    keyval[v] = city[u][v];
                    parent[v] = u;
                }
            }
        }

        int cost = 0;
        for (int i = 1; i < n; i++)
            cost += city[parent[i]][i];
        printf("%d\n", cost);
    }

int main() {

// Input 1
int n1 = 5;
             int city1[] = {{0, 1, 2, 3, 4},{1, 0, 5, 0, 7},{2, 5, 0, 6, 0},{3, 0, 6, 0, 0},{4, 7, 0, 0, 0}};
findcost(n1, city1);

// Input 2
int n2 = 6;
int city2[] = {{0, 1, 1, 100, 0, 0},{1, 0, 1, 0, 0, 0},{1, 1, 0, 0, 0, 0},{100, 0, 0, 0, 2, 2},{0, 0, 0, 2, 0, 2},{0, 0, 0, 2, 2, 0}};
findcost(n2, city2);

return 0;
}
