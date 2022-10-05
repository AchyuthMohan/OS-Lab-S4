#include<stdio.h>
#define size 60
struct frame{
    int pno;
    int frq;
};
struct allocation{
    int fno,bno;
};
int main(){
    int p,f,process[size];
    struct allocation alloc[size];
    int count=0;
    printf("Enter the number of processes: \n");
    scanf("%d",&p);
    printf("Enter the number of frames: \n");
    scanf("%d",&f);
    printf("Enter the processs sequence: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&process[i]);
    }
    
    struct frame frames[f];
    for(int i=0;i<f;i++){
        frames[i].frq=-1;
        frames[i].pno=-1;
    }
    for(int i=0;i<p;i++){
        int flag=0;
        for(int j=0;j<f;j++){
            if(process[i]==frames[j].pno){
                flag=1;
                break;
            }
        }
        if(flag==0){
            count++;
            int min=frames[0].frq;
            for(int j=0;j<f;j++){
                if(min>frames[j].frq){
                    min=frames[j].frq;
                }
            }
            for(int j=0;j<f;j++){
                if(frames[j].frq==min){
                    frames[j].pno=process[i];
                    frames[j].frq=1;
                    for(int k=0;k<f;k++){
                        printf("%d   ",frames[k].pno);
                    }
                    printf("\n");
                }
            }
        }
        else{
            for(int j=0;j<f;j++){
                if(frames[j].pno==process[i]){
                    frames[j].frq+=1;
                    for(int k=0;k<f;k++){
                        printf("%d   ",frames[k].pno);
                    }
                    printf("\n");
                }
            }
        }
    }
    printf("Count: %d\n",count);
    printf("Hit count: %d",(p-count));
}