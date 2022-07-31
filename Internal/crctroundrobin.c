#include<stdio.h>
#include<stdlib.h>
int main(){
    int q,n,i,wt[20],bt[20],tat[20],rem_bt[20],count,sq=0,temp;
    float awt=0,atat=0;
    printf("Enter the number of processes: ");
    
    scanf("%d",&n);
    for(i=0;i<20;i++){
        wt[i]=0;
        rem_bt[i]=0;
    }
    for(i=0;i<n;i++){
        printf("Enter the burst time of p[%d]: ",i+1);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d",&q);
    while(1){
        for(i=0, count=0;i<n;i++){
            temp=q;
            if(rem_bt[i]==0){
                count++;
                continue;
            }
            if(rem_bt[i]>q){
                rem_bt[i]=rem_bt[i]-q;
            }
            else{
                if(rem_bt[i]>=0){
                    temp=rem_bt[i];
                    rem_bt[i]=0;
                }
                sq+=temp;
                tat[i]=sq;
            }
            
        }
        if(n==count){
                break;  //breaking while loop after all process.
            }
    }
    printf("\nprocess\t\tburst time\t\t tat\t\twaiting time\n");;
    for(i=0;i<n;i++){
        wt[i]+=(bt[i]-tat[i]);
        awt+=wt[i];
        atat+=tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],tat[i],wt[i]);

    }
    awt=awt*1.0/(float)n;
    atat=atat*1.0/(float)n;
    printf("Average tat: %f\n",atat);
    printf("Average wt: %f",awt);

}