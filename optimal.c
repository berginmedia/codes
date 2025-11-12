#include <stdio.h>

int main() {
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int f;
    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frames[f], nextuse[f], pages[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    for (int i = 0; i < f; i++) frames[i] = -1;

    int pageFault = 0;

    for (int i = 0; i < n; i++) {
        int flag = 0;

        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            if (pageFault < f) {
                frames[pageFault] = pages[i];
            } else {
                for (int j = 0; j < f; j++) {
                    nextuse[j] = -1;
                    for (int k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            nextuse[j] = k;
                            break;
                        }
                    }
                }

                int farthest = -1, replaceindex = -1;
                for (int j = 0; j < f; j++) {
                    if (nextuse[j] == -1) {
                        replaceindex = j;
                        break;
                    }
                    if (farthest < nextuse[j]) {
                        farthest = nextuse[j];
                        replaceindex = j;
                    }
                }

                frames[replaceindex] = pages[i];
            }
            pageFault++;
        }
    }

    printf("Number of page faults: %d\n", pageFault);
}
