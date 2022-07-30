#include<stdio.h>
#define max 20

int pr[max],bt[max],p[max],wt[0],tat[0];
int main(){
    int n;
    int  awt=0,avgtat=0,totalwt=0,total_tat=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the priority and  burst time of p[%d]\n",i+1);
        printf("Enter the priority: \n");
        scanf("%d",&pr[i]);
        printf("Enter the nurst time: \n");
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(int i=0;i<n;i++){
        int min=pr[i];
        for(int j=i+1;j<n;j++){
            if(pr[j]<min){
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
        printf("p[%d]--->%d\n",i+1,p[i]);
    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=0;
        for(int j=0;j<i;j++){
            wt[i]+=wt[j];
        }
        // totalwt+=wt[i];
    }
    
    // printf("Total wt: %d",totalwt);
    // awt=(float)totalwt/(float)n;
    // for(int i=0;i<n;i++){
    //     tat[i]=bt[i]+wt[i];
    //     total_tat+=tat[i];
    // }
    // avgtat=(float)total_tat/(float)n;
    // printing
    printf("Process\t\t\tburst time\t\t\tturn around time\t\t\twait time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i],bt[i],tat[i],wt[i]);

    }
    for(int i=0;i<n;i++){
        total_tat+=(float)tat[i];
        totalwt+=(float)wt[i];
    }
    avgtat=total_tat/(float)n;
    awt=totalwt/(float)n;
    printf("Average wait time: %d\n",awt);
    printf("Average turn around time: %d",avgtat);
    

}