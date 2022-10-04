#include<stdio.h>
struct process{
    int pno,priority,bt,ct,tat,wt;
};
int main(){
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    struct process processes[n];
    for(int i=0;i<n;i++){
        printf("Enter the burst time of p[%d]: \n",i);
        scanf("%d",&processes[i].bt);
        printf("Enter the priority of p[%d]: \n",i);
        scanf("%d",&processes[i].priority);
        processes[i].pno=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(processes[i].priority>processes[j].priority){
                struct process temp=processes[i];
                processes[i]=processes[j];
                processes[j]=temp;
            }
        }
    }
    int completion_time=0;
    for(int i=0;i<n;i++){
        processes[i].ct=completion_time+processes[i].bt;
        completion_time+=processes[i].bt;
    }
    for(int i=0;i<n;i++){
        processes[i].tat=processes[i].ct;
    }
    for(int i=0;i<n;i++){
        processes[i].wt=processes[i].tat-processes[i].bt;
    }
    int net_wt=0,net_tat=0;
    for(int i=0;i<n;i++){
        net_wt+=processes[i].wt;
        net_tat+=processes[i].tat;
    }
    float avg_wt,avg_tat;
    avg_tat=(1.0)*net_tat/n;
    avg_wt=(1.0)*net_wt/n;
    printf("AVG WT: %f, AVG TAT: %f",avg_wt,avg_tat);

}