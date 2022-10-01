#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>

int main(){
    void *shared_memory;
    int shmid;
    char buff[100];
    shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);
    printf("shared memory id: %d\n",shmid);
    
    shared_memory=shmat(shmid,NULL,0);
    printf("attatched space: %p\n",shared_memory);
    printf("Enter the contents to be written inn shared memory: \n");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("Contents: %s",(char *)shared_memory);
    if(shmctl(shmid,IPC_RMID,0)==-1){
        printf("error in deletion");
    }
    else{
        printf("shared memory deleted succesfully");
    }
    return 0;
}
