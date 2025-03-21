#include <stdio.h>

void main() {
    int a[10][15], n, v, indegree, outdegree;
    
    printf("How many vertices: ");
    scanf("%d", &v);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            a[i][j] = 0;
            if (i != j) {
                printf("Is there an edge between %d -> %d (1/0): ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }
    }

    printf("\nVertex\ttotal-degree\t");

    for (int s = 0; s < v; s++) {
        indegree =0;
        outdegree = 0;
        

        for (int i = 0; i < v; i++) {
            indegree +=a[i][s];
            outdegree += a[s][i];
            
        }
        printf("\n%d\t%d\t", s+ 1, indegree+outdegree);
    }
}