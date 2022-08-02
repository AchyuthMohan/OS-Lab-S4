#include<stdio.h>
#include<stdlib.h>
#define size 20
void main(){
    int n,m,alloc[size][size],avail[size],max[size][size],need[size][size];
    printf("Enter the numbe rof processes: ");
    scanf("%d",&n);
    printf("Ente rthe number of resources: ");
    scanf("%d",&m);
    printf("Enter the allocation matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Enter the value for p[%d][%d]: ",i,j);
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the max matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Enter the value for p[%d][%d]: ",i,j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available array: \n");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((max[i][j]-alloc[i][j])<0){
                printf("Enter valid values!!");
                exit(1);

            }
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("NEED MATRIX: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%D\t",need[i][j]);
        }
    }

    int work[size],finish[size],safe_seq[size],ind=0;
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
                        flag =1;
                        break;
                    }
                }
                if(flag==0){
                    safe_seq[ind++]=i;
                    finish[i]=1;
                    for(int y=0;y<m;y++){
                        work[y]+=alloc[i][y];
                    }
                }
            }
        }
    }
    printf("SAFE SEQUENCE: \n");
    for(int i=0;i<n;i++){
        printf("%d--->",safe_seq[i]);
    }

}