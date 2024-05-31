#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000
#define m 3

int ou=1;

int x[MAX]={0};
int g[MAX][MAX];
int edges;

void nextvalue(int k) {
    while (1) {
        int j;
        x[k] = (x[k] + 1) % (m + 1);

        if (x[k] == 0)
            return;

        for (j = 0; j < edges; j++) {
            if ((g[k][j] != 0) && (x[k] == x[j]))
                break;
        }

        if (j == edges)
            return;
    }
}

void mcoloring(int k) {
	
    while (1) {
        nextvalue(k);
        if (x[k] == 0)
            return;
        if (k == edges - 1) { 
        	printf("output:%d \n", ou++);

            for (int i = 0; i < edges; i++) {
                printf("vertex %d -> color %d\t", i, x[i]);
            }
            printf("\n"); 
            
        } else {
            mcoloring(k + 1);
        }
    }
}

int main() {

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < edges; i++) {
//        printf("Enter values for edge %d:\n", i);
        for (int j = 0; j < edges; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int k = 0;
    mcoloring(k);
    return 0;
}

