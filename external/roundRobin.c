#include<stdio.h>
struct process{
    int pno,at,bt,rem_bt,ct,tat,wt;
};
int main(){
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    struct process processes[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time of p[%d]: \n",i);
        scanf("%d",&processes[i].at);
        printf("Enter the burst time of p[%d]: \n",i);
        scanf("%d",&processes[i].bt);
        processes[i].pno=i;
        processes[i].rem_bt=processes[i].bt;
    }
    for(int i=0;i<n;i++){
        processes[i].ct=0;
        processes[i].tat=processes[i].wt=0;
    }
    int current_time=0;
    // sorting
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(processes[i].at>processes[j].at){
                struct process temp=processes[i];
                processes[i]=processes[j];
                processes[j]=temp;
            }
        }
    }
    int qt;
    printf("Enter the quantum time: \n");
    scanf("%d",&qt);
    int counter=0;
    while(counter!=n){
        for(int i=0;i<n;i++){
            if(processes[i].rem_bt>qt){
                processes[i].rem_bt=processes[i].rem_bt-qt;
                current_time+=qt;

            }
            else if(processes[i].rem_bt<=qt&&processes[i].rem_bt>0){
                current_time+=processes[i].rem_bt;
                processes[i].rem_bt=0;
                counter++;
                processes[i].ct=current_time;
            }
        }
    }
    int net_tat=0;
    float avg_tat;

    for(int i=0;i<n;i++){
        processes[i].tat=processes[i].ct-processes[i].at; 
    }
    for(int i=0;i<n;i++){
        net_tat+=processes[i].tat;
    }
    avg_tat=(1.0)*net_tat/n;
    for(int i=0;i<n;i++){
        processes[i].wt=processes[i].tat-processes[i].bt;
    }
    int net_wt=0;
    float avg_wt;
    for(int i=0;i<n;i++){
        net_wt+=processes[i].wt;
    }
    avg_wt=(1.0)*net_wt/n;
    printf("Result: \n");
    for(int i=0;i<n;i++){
        printf("p[%d]\t BT: %d\tAT: %d\tTAT: %d\tWT: %d\tCT: %d\n",processes[i].pno,processes[i].bt,processes[i].at,processes[i].tat,processes[i].wt,processes[i].ct);
    }
    printf("AVG TAT: %f\n",avg_tat);
    printf("AVG WT: %f",avg_wt);

}