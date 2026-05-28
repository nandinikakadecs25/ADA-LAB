#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {

    int n, cost[MAX][MAX], visited[MAX] = {0};
    int i, j, ne = 1;
    int min, mincost = 0;
    int a = 0, b = 0, u = 0, v = 0;

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

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (ne < n) {

        min = INF;

        for (i = 0; i < n; i++) {

            if (visited[i]) {

                for (j = 0; j < n; j++) {

                    if (!visited[j] && cost[i][j] < min) {

                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d edge (%d -> %d) = %d\n", ne++, a, b, min);

        mincost += min;
        visited[b] = 1;

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
