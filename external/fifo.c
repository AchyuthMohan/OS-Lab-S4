#include<stdio.h>
#define max 25
struct frame{
    int pno;
    int index;
};
int main(){
    int p,f,processes[max],miss=0;
    printf("Enter the number of processes: \n");
    scanf("%d",&p);
    printf("Enter the number of frames: \n");
    scanf("%d",&f);
    struct frame frames[f];
    for(int i=0;i<f;i++){
        frames[i].index=-1;
        frames[i].pno=-1;
    }
    printf("Enter the process string: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&processes[i]);
    }
    for(int i=0;i<p;i++){
        
        
        int flag=0;
        for(int j=0;j<f;j++){
            if(processes[i]==frames[j].pno){
                flag=1;
                break;
            }
        }
        if(flag==0){
            miss++;
            int min=frames[0].index;
            for(int k=0;k<f;k++){
                if(min>frames[k].index){
                    min=frames[k].index;
                }
            }
            for(int k=0;k<f;k++){
                if(frames[k].index==min){
                    frames[k].index=i;
                    frames[k].pno=processes[i];
                    break;
                }
            }

            printf("Status: ");
             for(int x=0;x<f;x++){
                printf("%d   ",frames[x].pno);
            }
            printf("\n");
            
        }
        else{
           continue;
        }
    }
    printf("Miss: %d",miss);
   
}