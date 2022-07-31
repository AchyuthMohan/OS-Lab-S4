#include<stdio.h>
#include<stdlib.h>
#define size 30


int n, bt[size],tat[size],at[size],p[size],q;
void sort(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
}
void addProcesses(){
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the burst time of p[%d]: ",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the arrival time of p[%d]: ",i+1);
        scanf("%d",&at[i]);
    }
}
void execute(){
    for(int i=0;i>=0;i++){
        if(bt[i])
        printf("process: %d --->",p[i]);
        bt[i]=bt[i]-q;
        if(bt[i]>0){
            bt[n-1+i]=bt[i];
            p[n-1+i]=p[i];
        }
    }
}
int main(){
    int state=0;
    int ch;
    printf("Enter the time quantum: \n");
    scanf("%d",&q);
    while(state==0){
        printf("1. add process 2. generate result 3. exit: \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                addProcesses();
                sort();
                break;
            }
            case 2:{
                execute();
                break;
            }
            case 3:{
                state=1;
                break;
            }
        }
    }
}