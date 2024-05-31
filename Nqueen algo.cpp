#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000

int x[MAX] = {0};
int coun=0;

bool place(int k, int i) {
    for (int j = 0; j <= k - 1; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void Algorithm_NQueen(int k, int n) {
    for (int i = 0; i < n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == (n - 1)) {
                for (int l = 0; l < n; l++) {
                    printf("queen no: %d, row no: %d, column no: %d\n", l+1, l+1, x[l]+1);
                }
                printf("\n");
                if(coun==3)
                {
                	exit(0);
				}
				coun++;
            } else {
                Algorithm_NQueen((k + 1), n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    Algorithm_NQueen(0, n);
    return 0;
}

