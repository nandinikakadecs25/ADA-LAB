#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {

    int n, cost[MAX][MAX], dist[MAX], visited[MAX] = {0};
    int i, j, u, min, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix (use 9999 for no edge):\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
    }

    visited[start] = 1;
    dist[start] = 0;

    for (i = 1; i < n; i++) {

        min = INF;

        for (j = 0; j < n; j++) {

            if (!visited[j] && dist[j] < min) {

                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < n; j++) {

            if (!visited[j] && dist[u] + cost[u][j] < dist[j]) {

                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", start);

    for (i = 0; i < n; i++) {

        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
