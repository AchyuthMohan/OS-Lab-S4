#include<stdio.h>
int mutex=1,full=3,empty=0;
int wait(int s){
    return (--s);
}
int signal(int s){
    return (++s);
}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    mutex=signal(mutex);
}
int main(){
    int state=0;
    int ch;
    while(state==0){
        printf("1. Producer   2. Consumer     3. exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                if(mutex==1&&empty!=0){
                    producer();
                    printf("Producer added one product");
                }
                else{
                    printf("No access");
                }
                break;
            }
            case 2:{
                if(mutex==1&&full!=0){
                    consumer();
                    printf("consumer purchased one product..");

                }
                else{
                    printf("No access");
                }
                break;
            }
            case 3:{
                state=1;

            }
            break;
        }
    }
}