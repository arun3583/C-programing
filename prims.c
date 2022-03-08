#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
int main()
{
    int n, G[40][40], no_edge = 0, selected[40], cost = 0;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    memset(selected, false, sizeof(selected));
    selected[0] = true;
    int x,y;
    printf("Edge : Weight\n");
    while (no_edge < n - 1) {
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        if (G[x][y] != 0) {
            printf("%d - %d : %d\n", x, y, G[x][y]);
            cost = cost + G[x][y];
            selected[y] = true;
        }
        no_edge++;
    }
    printf("Cost = %d \n", cost);
    return 0;
}