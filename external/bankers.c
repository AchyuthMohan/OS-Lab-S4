#include<stdio.h>
#define size 25
int main(){
    int n,m,max[size][size],alloc[size][size],need[size][size],available[size],finish[size],work[size],safe[size];
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    printf("Enter the number of resources: \n");
    scanf("%d",&m);
    printf("Enter the max matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the allocation matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
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
        scanf("%d",&available[i]);
    }
    for(int i=0;i<n;i++){
        finish[i]=0;

    }
    for(int i=0;i<m;i++){
        work[i]=available[i];
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>available[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safe[i]=i;

                }
                for(int y=0;y<m;y++){
                    work[y]+=alloc[i][y];
                }
                finish[i]=1;
            }
        }
    }
    printf("Safe sequence: \n");
    for(int i=0;i<n;i++){
        printf("%d--->",safe[i]);
    }
}