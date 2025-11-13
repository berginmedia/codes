#include <stdio.h>

int main() {
    int n, q;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], rem[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &q);

    int t = 0, done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;
                if (rem[i] > q) {
                    t += q;
                    rem[i] -= q;
                } else {
                    t += rem[i];
                    wt[i] = t - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    printf("Average WT = %.2f\nAverage TAT = %.2f\n", awt / n, atat / n);
}