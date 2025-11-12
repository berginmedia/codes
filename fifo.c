#include <stdio.h>

int main() {
    int n;
    printf("Enter number of pages: ");
    scanf("%d", &n);

    int f;
    printf("Enter number of frames: ");
    scanf("%d", &f);
    int frames[f];
    for (int i = 0; i < f; i++) frames[i] = -1;

    int pages[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Pages\tFrames\n");
    int count = 0;
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;

        for (int j = 0; j < f; j++) {
            if (pages[i] == frames[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            frames[count % f] = pages[i];
            count++;
            pageFaults++;
        }

        printf("%d\t", pages[i]);
        for (int k = 0; k < n; k++) {
            if (frames[k] == -1) printf("- ");
            else printf("%d ", frames[k]);
        }
    }

    printf("Number of page faults: %d", pageFaults);
}