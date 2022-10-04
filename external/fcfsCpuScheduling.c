#include<stdio.h>
#define size 50
struct process{
    int pno;
    int bt;
    int wt;
    int tat;
    int at;
    int ct;
};
int main(){
    int n;
    struct process processes[size];
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    int complete_time=0;
    for(int i=0;i<n;i++){
        printf("Enter the arrival time of p[%d]: ",i);
        scanf("%d",&processes[i].at);
        printf("Enter the burst time of p[%d]: ",i);
        scanf("%d",&processes[i].bt);
        processes[i].pno=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(processes[i].at>processes[j].at){
                struct process temp=processes[i];
                processes[i]=processes[j];
                processes[j]=temp;
            }
        }
    }
    complete_time=processes[0].bt;
    processes[0].ct=complete_time;
    for(int i=1;i<n;i++){
        complete_time+=processes[i].bt;
        processes[i].ct=complete_time;
    }
    for(int i=0;i<n;i++){
        processes[i].tat=processes[i].ct-processes[i].at;
    }
    for(int i=0;i<n;i++){
        processes[i].wt=processes[i].tat-processes[i].bt;
    }
    int net_wt=0,net_tat=0;
    for(int i=0;i<n;i++){
        net_tat+=processes[i].tat;
        net_wt+=processes[i].wt;
    }
    printf("Sequence: \n");
    for(int i=0;i<n;i++){
        printf("P[%d]  wt: %d  bt: %d  at: %d  tat: %d  ct: %d\n",processes[i].pno,processes[i].wt,processes[i].bt,processes[i].at,processes[i].tat,processes[i].ct);
    }
    float avg_wt,avg_tat;
    avg_tat=(1.0)*net_tat/n;
    avg_wt=(1.0)*net_wt/n;
    printf("AVG WT: %f, AVG TAT: %f",avg_tat,avg_wt);
}