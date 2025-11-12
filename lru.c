#include <stdio.h>

int main() {
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int f;
    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frames[f], recents[f];
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        recents[i] = -1;
    }

    int pages[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("\nPage\tFrames\n");

    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int flag = 0;

        for (int j = 0; j < f; j++) {
            if (pages[i] == frames[j]) {
                flag = 1;
                recents[j] = i;
                break;
            }
        }

        if (flag == 0) {
            if (pageFaults < f) {
                frames[pageFaults] = pages[i];
                recents[pageFaults] = i;
            } else {
                int least = 0;
                for (int k = 1; k < f; k++) {
                    if (recents[k] < recents[least])
                        least = k;
                }
                frames[least] = pages[i];
                recents[least] = i;
            }
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for (int k = 0; k < f; k++) {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nNumber of page faults: %d\n", pageFaults);
}
