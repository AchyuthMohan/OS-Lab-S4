#include<stdio.h>
#define size 30
int main(){
    int p[size],pr[size],bt[size],n,seq[size],index=0, wt[size],tat[size],net_tat= 0,net_wt=0;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter the burst time of p[%d]: \n",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the priority of p[%d]: \n",i+1);
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
            net_wt+=wt[i];
        }
    }
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        net_tat+=tat[i];
    }
    printf("Process\tbt\ttat\tpriority\n");
    for(int i=0;i<n;i++){
        seq[index++]=p[i];
        printf("%d\t%d\t%d\t%d\n",p[i],bt[i],tat[i],pr[i]);
        
    }
   
    printf("net tat: %d",net_tat);
    float avg_wt,avg_tat;
    avg_tat=(float)net_tat/n;
    avg_wt=(float)net_wt/n;
    printf("avg tat: %f\n",avg_tat);
    printf("avg wt: %f\n",avg_wt);

    
    

}