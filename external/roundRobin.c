#include<stdio.h>
struct process{
    int at,bt,tat,ct,pno,rm_bt;
};
int main(){
    int n,qt,current_time=0;
    printf("Enter the number of processes: \n");
    struct process processes[n];
    scanf("%d",&n);
    int wait_time[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time of p[%d]: \n",i);
        scanf("%d",&processes[i].at);
        printf("Enter the burst time of p[%d]: \n",i);
        scanf("%d",&processes[i].bt);
        processes[i].rm_bt=processes[i].bt;
        processes[i].pno=i;
    }
    printf("Enter the time quantum: \n");
    scanf("%d",&qt);
    int counter =0;
    // sorting on the basisi of arrival time
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(processes[i].at>processes[j].at){
                struct process temp=processes[i];
                processes[i]=processes[j];
                processes[j]=temp;
            }
        }
    }
    
    while(counter!=n){
        for(int i=0;i<n;i++){
            if(processes[i].rm_bt>qt){
                processes[i].rm_bt=processes[i].rm_bt-qt;
                current_time+=qt;
                
            }
            else if(processes[i].rm_bt<=qt &&processes[i].rm_bt!=0){
                current_time+=processes[i].rm_bt;
                processes[i].rm_bt=0;
                processes[i].ct=current_time;
                counter++;
            }
        }
   }
   for(int i=0;i<n;i++){
    processes[i].tat=processes[i].ct-processes[i].at;
   }
   
   for(int i=0;i<n;i++){
    wait_time[i]=processes[i].tat-processes[i].bt;
   }
//    for(int i=0;i<n;i++){
//     printf("%d\n",processes[i].tat);
//    }
   for(int i=0;i<n;i++){
    printf("P[%d]  AT:%d   BT:%d  WT:%d  TAT: %d  CT: %d\n",i,processes[i].at,processes[i].bt,wait_time[i] ,processes[i].tat,processes[i].ct);
   }

}