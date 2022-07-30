#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=3,empty=0;
int wait(int s){
    return (--s);
}
int signal(int s){
    return(++s);
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    printf("Producer added a new product\n");
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=wait(empty);
    printf("Consumer consumed a product\n");
    mutex=signal(mutex);
}
int main(){
    int state=0,n;
    while(state==0){
        printf("1. Producer 2. Consumer 3. exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:{
                if(((mutex==1)&&(empty!=0))){
                    producer();

                }
                else{
                    printf("Buffer is full!!\n");
                }
                break;
            }
            case 2:{
                if((mutex==1)&&(full!=0)){
                    consumer();

                }
                else{
                    printf("Buffer is empty\n");
                }
                break;
            }
            case 3:{
                state=1;
                break;
            }
        }
    }
    return 0;

}