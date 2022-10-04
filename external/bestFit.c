#include<stdio.h>
#define max 40
struct block{
    int bno;
    int size;
    int is_alloc;
};
struct allocated{
    int bno,pno;
};
int main(){
    int b,p,counter=0;
    struct allocated allocs[max];
    printf("Enter the number of processes: \n");
    scanf("%d",&p);
    int allocated[p],a=0;
    printf("Enter the number of blocks: \n");
    scanf("%d",&b);
    struct block blocks[b];
    int processes[p];
    printf("Enter the size of processes: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&processes[i]);
    }
    printf("Enter the size of blocks: ");
    for(int i=0;i<b;i++){
        scanf("%d",&blocks[i].size);
        blocks[i].bno=i;
        blocks[i].is_alloc=0;
    }
    for(int i=0;i<b;i++){
        for(int j=i+1;j<b;j++){
            if(blocks[i].size>blocks[j].size){
                struct block temp=blocks[i];
                blocks[i]=blocks[j];
                blocks[j]=temp;
            }
        }

    }
    for(int i=0;i<p;i++){
        for(int j=0;j<b;j++){
            if(processes[i]<=blocks[j].size){
                if(blocks[j].is_alloc==0){
                    allocs[counter].bno=blocks[j].bno;
                    allocs[counter].pno=processes[i];
                    counter++;
                    blocks[j].is_alloc=1;
                }
            }
            else{
                continue;
            }
        }
    }
    printf("Result: \n");
    for(int i=0;i<counter;i++){
        printf("Block: %d--->Process: %d\n",allocs[i].bno,allocs[i].pno);
    }

}