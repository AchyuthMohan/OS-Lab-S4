#include<stdio.h>
int mutex=1,full=3,empty=0;
int signal(int s){
    return ++s;
}
int wait(int s){
    return --s;
}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    mutex=signal(mutex);
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    mutex=signal(mutex);
}
int main(){
    int state=1,choice;
    while(state==1){
        printf("1. customer 2. producer 3. exit: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                if(mutex==1&&full!=0){
                    consumer();
                    printf("Customer purchased product!!\n");
                }
                else{
                    printf("No items to purchase!!");

                }
                break;
            }
            case 2:{
                if(mutex==1&&empty!=0){
                    producer();
                    printf("Producer added aproduct!!\n");

                }
                else{
                    printf("Buffer full!!\n");

                }
                break;
            }
            case 3:{
                state=0;
                break;
            }
        }
    }
}