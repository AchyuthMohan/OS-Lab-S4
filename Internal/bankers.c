#include<stdio.h>
#include<stdlib.h>
#define size 50
int main(){
    int n,m,max[size][size],alloc[size][size],avail[size],need[size][size],work[size],finish[size],safe_seq[size],ind=0;
    printf("enter the number of processes: \n");
    scanf("%d",&n);
    printf("Enter the number of resources: \n");
    scanf("%d",&m);
    printf("Enter the max matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Enter the value for p[%d][%d]: \n",i,j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the allocation matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Enter the value for p[%d][%d]: \n",i,j);
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the available array: ");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((max[i][j]-alloc[i][j])<0){
                printf("Enter valid values...");
                exit(1);
            }
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("NEED MATRIX: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d\t",need[i][j]);

        }
        printf("\n");
    }
    for(int i=0;i<m;i++){
        work[i]=avail[i];
    }
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
           if(finish[i]==0){
            int flag=0;
            for(int j=0;j<m;j++){
                if(need[i][j]>work[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                safe_seq[ind++]=i;
                for(int y=0;y<m;y++){
                    work[y]+=alloc[i][y];
                }
                finish[i]=1;
            }
           }
        }
    }

    printf("SAFE SEQUENCE\n");
    for(int i=0;i<n;i++){
        printf("%d--->",safe_seq[i]);
    }

    return 0;
}