#include<stdio.h>
#include<stdlib.h>
#define size 50
int main(){
    int n,total=0,bt[size],at[size],p[size],temp[size],i,qt,x,tat=0,wt=0;
    printf("Enter the number pf processes: \n");
    float avg_tat,avg_wt;
    scanf("%d",&n);
    x=n;
    for(i=0;i<n;i++){
        printf("Enter the burst time of p[%d]: \n",i+1);
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
        printf("Enter the arrival time of p[%d]: \n",i+1);
        scanf("%d",&at[i]);
    }
    printf("Enter the time quantum: %d");
    scanf("%d",&qt);
    int counter;
    
    printf("process\tburst time\ttat\twait time\n");
    for(i=0,total=0;x!=0;){
        if(temp[i]<=qt&&temp[i]>0){
            temp[i]=0;
            total=total+temp[i];
            counter=1;
        }
        else if(temp[i]>0){
            temp[i]=temp[i]-qt;
            total+=qt;
        }
        if(temp[i]==0&&counter==1){
            x--;
            printf("process[%d]\t%d\t%d\t%d\n",i+1,bt[i],total-at[i],total-at[i]-bt[i]);
            tat+=total-at[i];
            wt+=total-at[i]-bt[i];
            counter=0;
        }
        if(i==n-1){
            i=0;
        }
        else if(at[i+1]<=total){
            i++;
        }
        else{
            i=0;
        }
    }
    avg_tat=1.0*(tat/n);
    avg_wt=1.0*(wt/n);
    printf("Average wt: %f\n",avg_wt);
    printf("Average tat: %f\n",avg_tat);


}