#include<stdio.h>
struct block{
    int bno;
    int size;
};
struct allocation{
    int bno;
    int pno;
};
#define max 25
int main(){
    int p,b,ps[max],bs[max];
    struct block blocks[max];
    int allocated[max],a=0;
    struct allocation alloc[max];
    int counter=0;
    printf("Enter the number of blocks: \n");
    scanf("%d",&b);
    printf("Enter the number of processes: \n");
    scanf("%d",&p);
    printf("Enter the size of blocks: \n");
    for(int i=0;i<b;i++){
        int t;
        scanf("%d",&t);
        blocks[i].bno=i;
        blocks[i].size=t;
    }
    printf("Enter the size of processes: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&ps[i]);
    }
    // descending sorting
    for(int i=0;i<b;i++){
        for(int j=i+1;j<b;j++){
            if(blocks[i].size<=blocks[j].size){
                struct block temp=blocks[i];
                blocks[i]=blocks[j];
                blocks[j]=temp;
            }
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<b;j++){
            if(ps[i]<=blocks[j].size){
                int flag=0;
                for(int k=0;k<a;k++){
                    if(allocated[k]==blocks[j].bno){
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
                    break;
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