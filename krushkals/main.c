#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

int find(int node) {

    while (parent[node] != 0) {
        node = parent[node];
    }

    return node;
}

int unionset(int x, int y) {

    if (x != y) {
        parent[y] = x;
        return 1;
    }

    return 0;
}

int main() {

    int n;
    int cost[MAX][MAX];
    int i, j;
    int min, mincost = 0;
    int a, b, u, v;
    int edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    printf("\nEdges in Minimum Cost Spanning Tree:\n");

    while (edges < n - 1) {

        min = INF;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (unionset(u, v)) {

            printf("%d edge (%d -> %d) = %d\n", edges + 1, a, b, min);

            mincost += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
