#include<stdio.h>
struct frame{
    int psize;
    int index;
};
int main(){
    int p,f,miss=0;
    printf("Enter the number of processes: \n");
    scanf("%d",&p);
    int processes[p];
    printf("Enter the frame size: \n");
    scanf("%d",&f);
    struct frame frames[f];
    printf("Enter the process array: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&processes[i]);
    }
    for(int i=0;i<f;i++){
        frames[i].index=-1;
        frames[i].psize=-1;

    }
    for(int i=0;i<p;i++){
        int flag=0;
        for(int j=0;j<f;j++){
            if(frames[i].psize==processes[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){   //not there
            miss++;
            int min=frames[0].index;
            for(int k=0;k<f;k++){
                if(min>frames[k].index){
                    min=frames[k].index;
                }
            }
            for(int k=0;k<f;k++){
                if(min==frames[k].index){
                    frames[k].index=i;
                    frames[k].psize=processes[i];
                    break;
                }
            }
        }
        else{
            for(int k=0;k<f;k++){
                if(frames[k].psize==processes[i]){
                    frames[k].index=i;
                    break;
                }
                else{
                    continue;
                }
            }
        }
        printf("Status: \n");
        printf("Falut: %d\n",miss);
        for(int c=0;c<f;c++){
            printf("Block: %d -----> %d",c,frames[c].psize);
        }
        printf("\n");
    }
    printf("Fault: %d",miss);
}