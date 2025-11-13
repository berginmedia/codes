#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0, min, shortest = 0, finish;
    float awt = 0, atat = 0;
    while (complete != n) {
        min = 9999;
        for (int i = 0; i < n; i++)
            if (at[i] <= time && rt[i] < min && rt[i] > 0) {
                min = rt[i];
                shortest = i;
            }

        if (min == 9999) { time++; continue; }

        rt[shortest]--;
        if (rt[shortest] == 0) {
            complete++;
            finish = time + 1;
            wt[shortest] = finish - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
            tat[shortest] = finish - at[shortest];
        }
        time++;
    }

    for (int i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    printf("Average WT = %.2f\nAverage TAT = %.2f\n", awt / n, atat / n);
}