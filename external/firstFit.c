#include<stdio.h>
#define max 20
struct allocation{
    int bno;
    int pno;
};
int main(){
    int b,p,bs[max],ps[max],allocated[max];
    struct allocation alloc[max];
    int a=0;
    int counter=0;
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    printf("enter the number of blocks\n");
    scanf("%d",&b);
    printf("Enter the size of blocks: \n");
    for(int i=0;i<b;i++){
        scanf("%d",&bs[i]);

    }
    printf("Enter the size of processes: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&ps[i]);
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            if(ps[i]<=bs[j]){
                int flag=0;
                for(int k=0;k<a;k++){
                    if(allocated[k]==j){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    allocated[a++]=j;
                    alloc[counter].bno=j;
                    alloc[counter].pno=i;
                    counter++;
                    break;
                }
            }
            else{
                continue;
            }
        }
    }
    for(int i=0;i<counter;i++){
        printf("Block: %d ----> Process: %d\n",alloc[i].bno,alloc[i].pno);
    }
}