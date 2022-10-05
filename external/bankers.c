#include<stdio.h>
#define size 35
int main(){
    int n,m,safe_seq[size];
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    printf("Enter number of resources: \n");
    scanf("%d",&m);
    printf("Enter the allocation matrix: \n");
    int alloc[size][size],max[size][size],need[size][size],avail[size],work[size];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);

        }
    }
    printf("Enter the max matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("Need Matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    printf("Enter the available array: \n");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    for(int i=0;i<m;i++){
        work[i]=avail[i];
    }
    int finish[size];
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
    int counter=0;
    int index=0;
    while(counter!=n){
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        int flag=1;
                        break;
                    }
                }
                if(flag==0){
                    finish[i]=1;
                    counter++;
                    safe_seq[index++]=i;
                    for(int k=0;k<m;k++){
                        work[k]+=alloc[i][k];
                    }
                    

                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
    }
printf("Safe: ");
for(int i=0;i<n;i++){
    printf("%d\t",safe_seq[i]);
}

}