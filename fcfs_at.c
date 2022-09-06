void findWaitingTime(int processes[],int n,int bt[],int wt[],int at[]){

    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;

    for(int i = 1;i<n;i++){
        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] - at[i];
        if(wt[i]<0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[]){
    for(int i =0;i<n;i++){
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[],int n,int bt[],int at[]){

    int wt[n],tat[n],total_wt = 0,total_tat = 0;

    findWaitingTime(processes,n,bt,wt,at);
    findTurnAroundTime(processes,n,bt,wt,tat);
    printf("Processes  Burst time  Arrival time    Waiting time    Turn around time\n");
    for(int i =0;i<n;i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("    P%d\t",processes[i]);
        printf("\t%d\t",bt[i]);
        printf("\t%d\t",at[i]);
        printf("\t%d\t",wt[i]);
        printf("\t%d \n",tat[i]);
    }
    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("Average waiting time = %f\nAverage turn around time = %f\n",avg_wt,avg_tat);
}

void main(){
    int processes[] = {1,2,3};
    int n = 3;
    int burst_time[] = {22,8,3};
    int arrival_time[] = {0,1,2};
    findavgTime(processes,n,burst_time,arrival_time);
}
