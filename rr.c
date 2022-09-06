#include<stdbool.h>
void findWaitingTime(int processes[],int n,int bt[],int wt[],int quantum){
    int rem_bt[n];
    for(int i = 0;i<n;i++){
        rem_bt[i] = bt[i];
    }
    int t=0;
    while(true){
        bool done = true;
        for(int i = 0;i<n;i++){
            if(rem_bt[i]>0){
                done = false;
                if(rem_bt[i]>quantum){
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    t = t+ rem_bt[i];
                    wt[i] = t- bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == true)
            break;
    }
}

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[]){
    for(int i =0;i<n;i++){
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[],int n,int bt[],int quantum){

    int wt[n],tat[n],total_wt = 0,total_tat = 0;

    findWaitingTime(processes,n,bt,wt,quantum);
    findTurnAroundTime(processes,n,bt,wt,tat);
    printf("Processes  Burst time  Waiting time    Turn around time\n");
    for(int i =0;i<n;i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("    P%d\t",processes[i]);
        printf("\t%d\t",bt[i]);
        printf("\t%d\t",wt[i]);
        printf("\t%d \n",tat[i]);
    }
    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("Average waiting time = %f\nAverage turn around time = %f\n",avg_wt,avg_tat);
}

void main(){
    int n;
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    int processes[n-1],burst_time[n-1];
    printf("Enter the burst time of processes: ");
    for(int i =0;i<n;i++){
        processes[i] = (i+1);
        scanf("%d", &burst_time[i]);
    }
    int quantum = 4;
    findavgTime(processes,n,burst_time,quantum);
}

