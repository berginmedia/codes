#include <stdio.h>

int main() {
    int nb, np;
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    int block[nb];
    printf("Enter block sizes: ");
    for (int i = 0; i < nb; i++) scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);
    int process[np], alloc[np];
    printf("Enter process sizes: ");
    for (int i = 0; i < np; i++) scanf("%d", &process[i]);

    for (int i = 0; i < np; i++) alloc[i] = -1;

    for (int i = 0; i < np; i++) {
        int best = -1;
        for (int j = 0; j < nb; j++) {
            if (block[j] >= process[i]) {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < np; i++) {
        if (alloc[i] != -1) printf("%d\t%d\t%d\n", i + 1, process[i], alloc[i] + 1);
        else printf("%d\t%d\tNot Allocated\n", i + 1, process[i]);
    }
}
