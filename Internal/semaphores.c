#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=3,empty=0;
int signal(int s){
    return ++s;
}
int wait(int s){
    return --s;
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    printf("Producer added one product...");
    empty=wait(empty);
    mutex=signal(mutex);

}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("Consumer purchased one product..");
    mutex=signal(mutex);
}
int main(){
    int state=0;
    while(state==0){
        printf("1. producer  2.Consumer 3.exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                if(mutex==1&&empty!=0){
                    producer();
                }
                else{
                    printf("Buffer is full");
                }
                break;
            }
            case 2:{
                if(mutex==1&&full!=0){
                    consumer();
                }
                else{
                    printf("Buffer is empty");
                }
                break;
            }
            case 3:{
                state=1;
                break;
            }
        }
    }

}