#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], pr[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT, and priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0, highest, finish;
    float awt = 0, atat = 0;
    while (complete != n) {
        int min_pr = 9999;
        highest = -1;
        for (int i = 0; i < n; i++)
            if (at[i] <= time && pr[i] < min_pr && rt[i] > 0) {
                min_pr = pr[i];
                highest = i;
            }

        if (highest == -1) { time++; continue; }

        rt[highest]--;
        if (rt[highest] == 0) {
            complete++;
            finish = time + 1;
            wt[highest] = finish - bt[highest] - at[highest];
            if (wt[highest] < 0) wt[highest] = 0;
            tat[highest] = finish - at[highest];
        }
        time++;
    }

    for (int i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
    printf("Average WT = %.2f\nAverage TAT = %.2f\n", awt / n, atat / n);
}