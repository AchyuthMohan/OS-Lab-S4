#include<stdio.h>
#define max 30
struct block{
    int bno;
    int size;
};
struct allocation{
    int bno;
    int pno;
};
int main(){
    int b,p,bs[max],ps[max];
    struct block blocks[max];
    struct allocation alloc[max];
    int counter=0;
    int allocated[max],a=0;
    printf("Enter the umber of processes: \n");
    scanf("%d",&p);
    printf("Enter the number of blocks: \n");
    scanf("%d",&b);
    printf("Enter the process sizes: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&ps[i]);
    }
    printf("Enter the block sizes: \n");
    for(int j=0;j<b;j++){
        blocks[j].bno=j;
        int t;
        scanf("%d",&t);
        blocks[j].size=t;
    }
    // sorting
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++){
            if(blocks[i].size>=blocks[j].size){
                struct block temp=blocks[i];
                blocks[i]=blocks[j];
                blocks[j]=temp;
            }
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<b;j++){
            if(blocks[j].size>=ps[i]){
                int flag=0;
                for(int k=0;k<a;k++){
                    if(blocks[j].bno==allocated[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    alloc[counter].bno=blocks[j].bno;
                    alloc[counter].pno=ps[i];
                    allocated[a]=blocks[j].bno;
                    counter++;
                    a++;
                }
            }
            else{
                continue;
            }
        }
    }
    for(int i=0;i<counter;i++){
        printf("Block: %d----> Process: %d\n",alloc[i].bno,alloc[i].pno);
    }
}