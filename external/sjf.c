#include<stdio.h>
#define size 50
struct process{
    int bt,pno,ct,tat,wt;
};
int main(){
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    struct process procesess[size];
    for(int i=0;i<n;i++){
        printf("Enter the burst time of p[%d]: \n",i);
        scanf("%d",&procesess[i].bt);
        procesess[i].pno=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(procesess[i].bt>procesess[j].bt){
                struct process temp=procesess[i];
                procesess[i]=procesess[j];
                procesess[j]=temp;
            }
        }
    }
    int completion_time=0;
    for(int i=0;i<n;i++){
        procesess[i].ct=completion_time+procesess[i].bt;
        completion_time+=procesess[i].bt;
    }
    for(int i=0;i<n;i++){
        procesess[i].tat=procesess[i].ct;
    }
    for(int i=0;i<n;i++){
        procesess[i].wt=procesess[i].tat-procesess[i].bt;
    }
    int net_wt=0,net_tat=0;
    for(int i=0;i<n;i++){
        net_tat+=procesess[i].tat;
        net_wt+=procesess[i].wt;
    }
    float avg_wt,avg_tat;
    avg_tat=(1.0)*net_tat/n;
    avg_wt=(1.0)*net_wt/n;
    printf("AVG WT: %f, AVG TAT: %f",avg_wt,avg_tat);
}