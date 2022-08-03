#include<stdio.h>
#include<stdlib.h>
#define size 40
int main(){
    int pr[size],bt[size],p[size],n,wt[size],total_wt=0,total_tat=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the burst times: \n");
    for(int i=0;i<n;i++){
        printf("p[%d]",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    printf("Enter the priority: \n");
    for(int i=0;i<n;i++){
        printf("p[%d]",i+1);
        scanf("%d",&pr[i]);
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
    int tat[size];
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        total_tat+=tat[i];
    }
    printf("process\tburst time\tpriority\ttat\twt\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t\n",p[i],bt[i],pr[i],tat[i],wt[i]);
    }
    float avg_wt=(float)total_wt/n;
    float avg_tat=(float)total_tat/n;
    printf("Average wt: %f\n",avg_wt);
    printf("Avergae tat: %f",avg_tat);


}