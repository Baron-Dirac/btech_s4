#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct process {
    char pname[20];
    int at, bt, wt, tt, ct, status;
} p[20], temp;
struct done {
    char name[20];
    int st, ct;
} d[100];
void gantt_chart(int num) {
    printf("\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < num - 1; i++) {
        printf("--------");
    }
    printf("-------\n|");
    for (int i = 0; i < num; i++) {
        printf("  %s\t|", d[i].name);
    }
    printf("\n ");
    for (int i = 0; i < num - 1; i++) {
        printf("--------");
    }
    printf("-------\n%d", d[0].st);
    for (int i = 0; i < num; i++) {
        printf("\t%d", d[i].ct);
    }
    printf("\n");
}
int main() {
    int i, j, n, k = 0, num = 0;
    float sumwt = 0, sumtt = 0;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    for (k = 0; k < n; k++) {
        printf("Name: ");
        scanf("%s", p[k].pname);
        printf("Arrival Time: ");
        scanf("%d", &p[k].at);
        printf("Burst Time: ");
        scanf("%d", &p[k].bt);
        p[k].status = 0;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) { 
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (i = 0, k = 0; k < n;) {
        if (p[k].at <= i && p[k].status == 0) {
            strcpy(d[num].name, p[k].pname);
            d[num].st = i;
            i += p[k].bt;
            p[k].ct = i;
            d[num].ct = i;

            p[k].tt = d[num].ct - p[k].at;
            p[k].wt = p[k].tt - p[k].bt;
            sumwt += p[k].wt;
            sumtt += p[k].tt;
            
            p[k].status = 1;
            k++;
            num++;
        } else {
            strcpy(d[num].name, "Idle");
            d[num].st = i;
            while(p[k].at != i)
                i++;
            d[num].ct = i;
            num++;
        }
    }
    gantt_chart(num);
    printf("\nProcess Table:\n");
    printf("PName\tAT\tBT\tCT\tTT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }
    printf("\nAverage Waiting Time: %.2f\n", sumwt / n);
    printf("Average Turnaround Time: %.2f\n", sumtt / n);
    return 0;
}
/*OUTPUT
Enter the no. of processes: 4
Name: p1
Arrival Time: 1
Burst Time: 7
Name: p2
Arrival Time: 3
Burst Time: 3
Name: p3
Arrival Time: 6
Burst Time: 2
Name: p4
Arrival Time: 7
Burst Time: 10
Gantt Chart:
 ---------------------------------------
|  Idle |  p1   |  p2   |  p3   |  p4   |
 ---------------------------------------
0       1       8       11      13      23
Process Table:
PName   AT      BT      CT      TT      WT
p1      1       7       8       7       0
p2      3       3       11      8       5
p3      6       2       13      7       5
p4      7       10      23      16      6
Average Waiting Time: 4.00
Average Turnaround Time: 9.50*/
