#include<stdio.h>

struct Process {
    int pid;    
    int arrivaltime;// Process ID
    int burst_time; // Burst time
    int waittime;
    int status;
};

int findShortestJob(struct Process processes[], int n,int time) {
    int shortestTime = 9999;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivaltime<=time && processes[i].burst_time< shortestTime && processes[i].status==1) {
           shortestTime = processes[i].burst_time;
            index = i;
        }
    }
    return index;
}

void sjfScheduling(struct Process proc[], int n) {
    int i, j,total_waiting_time=0,total_turnaround_time=0,index;
    struct Process temp;
    int completed=0,time=0;
    while(completed<n){
        index=findShortestJob(proc,n,time);
       if(index!=-1){
        time+=proc[index].burst_time;
        completed++;
        proc[index].status=0;
        proc[index].waittime=time-proc[index].burst_time-proc[index].arrivaltime;
        total_waiting_time+=proc[index].waittime;
        total_turnaround_time+=proc[index].waittime+proc[index].burst_time;}
    else{
        time++;}
    }
   
    printf("Process\tBurst Time\tWaiting Time \t Turn around time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t\t%d\t%d\n", proc[i].pid, proc[i].burst_time,proc[i].waittime,proc[i].waittime+proc[i].burst_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
}

void main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
 struct Process proc[n];
    printf("Enter process details (Process ID, Burst Time,arrival time:)\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].burst_time,&proc[i].arrivaltime);
        proc[i].status=1;
    }
    sjfScheduling(proc, n);
}