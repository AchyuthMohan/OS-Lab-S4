

#include <stdio.h>
#define size 40


int main()
{
    int n,temp[size],bt[size],at[size],i,x,counter=0,total=0,q,net_wt=0,net_tat=0;
    
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    x=n;
    for(i=0;i<n;i++){
        printf("Enter the burst time of p[%d]: \n",i+1);
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
        printf("Enter the arrival time of p[%d]: \n",i+1);
        scanf("%d",&at[i]);
        
    }
    printf("Enter the time quantum: \n");
    scanf("%d",&q);
    printf("p\tbt\ttat\twt\n");
    for(total=0,i=0;x!=0;){
        if(temp[i]<=q&&temp[i]>0){
            temp[i]=0;
            total+=temp[i];
            counter=1;
            
        }
        else if(temp[i]>0){
            temp[i]=temp[i]-q;
            total+=q;
        }
        if(temp[i]==0&&counter==1){
            x--;
            printf("p[%d]\t%d\t%d\t%d\n",i+1,bt[i],total-at[i],total-at[i]-bt[i]);
            net_tat=net_tat+total-at[i];
            net_wt+=net_wt+ total-at[i]-bt[i];
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
    float avg_wt=1.0*(net_wt/n),avg_tat=1.0*(net_tat/n);
    printf("average wt: %f\n",avg_wt);
    printf("average tat: %f\n",avg_tat);
    
    
    

    return 0;
}
