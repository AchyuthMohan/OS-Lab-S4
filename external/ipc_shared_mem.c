#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/ipc.h>
int main(){
    void *shared_memory;
    int shm_id=shmget((key_t)1122,1024,0666|IPC_CREAT);
    shared_memory=shmat(shm_id,NULL,0);
    int state=0;
    while(state==0){
        printf("1.Read  2.Write  3.Exit: \n");
        int ch;
        scanf("%d",&ch);  
        switch(ch){
            case 1:{
                printf("%s\n",shared_memory);
                break;
            }
            case 2:{
                printf("Enter the contents: \n");
                char str[100];
                gets(str);
                strcpy(shared_memory,str);
                break;
            }
            case 3:{
                state=1;
                break;
            }
        }
    }
    
    
}