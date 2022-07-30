#include<stdio.h>
#include<stdlib.h>
#define size 30
int main(){
    int p[size],bt[size],wt[size],tat[size],pr[size],n,total_tat=0,total_wt=0,avg_wt,avg_tat;
    printf("Enter the number  of processes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the priority for p[%d]: ",i+1);
        scanf("%d",&pr[i]);
        printf("Enter the burst time for p[%d]: ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pr[i]>pr[j]){
                int temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

            }
        }
    }
    for(int i=0;i<n;i++){
        wt[i]=0;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        total_wt+=wt[i];
    }

    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        total_tat+=tat[i];
    }
    avg_tat=total_tat/n;
    avg_wt=total_wt/n;
    printf("Process\t\t\tburst time\t\t\tturn around time\t\t\twait time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i],bt[i],tat[i],wt[i]);

    }
     printf("Average wait time: %d\n",avg_wt);
    printf("Average turn around time: %d",avg_tat);

}