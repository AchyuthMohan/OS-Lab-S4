#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
int shmid;
void *shared_memory;

void read(){
    
}
void write(){
    
}
int main(){
    int state=0;
    shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
    shared_memory=shmat(shmid,NULL,0);
    while(state==0){
        printf("1. read 2. write 3. exite\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("%s",shared_memory);
                break;
            }
            case 2:{
                char buff[100];
                printf("Enter the contents to be written in the shared memory: ");
                scanf("%s",buff);
                strcpy(shared_memory,buff);
                break;
                
            }
            case 3:{
                state=1;
                break;
            }
        }
    }
}