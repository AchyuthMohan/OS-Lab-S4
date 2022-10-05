#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,net_head_movements=0;
    printf("Enter the number of requests: \n");
    scanf("%d",&n);
    int rq[n];
    printf("Enter the request array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the initial position: \n");
    int initial;
    scanf("%d",&initial);
    printf("1. high to low 2. low to high: ");
    int move;
    scanf("%d",&move);
    printf("%d\t",initial);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(rq[i]>rq[j]){
                int temp=rq[i];
                rq[i]=rq[j];
                rq[j]=temp;
            }
        }
    }
    int index;
    for(int i=0;i<n;i++){
        if(initial<rq[i]){
            index=i;
            break;
        }
    }
    if(move==1){
        for(int i=index;i<n;i++){
            net_head_movements+=abs(rq[i]-initial);
            printf("%d\t",rq[i]);
            initial=rq[i];
        }
        for(int i=index-1;i>=0;i--){
            net_head_movements+=abs(rq[i]-initial);
            printf("%d\t",rq[i]);
            initial=rq[i];
        }
    }
    else{
        for(int i=index-1;i>=0;i--){
            net_head_movements+=abs(rq[i]-initial);
            printf("%d\t",rq[i]);
            initial=rq[i];
        }
        for(int i=index;i<n;i++){
            net_head_movements+=abs(rq[i]-initial);
            printf("%d\t",rq[i]);
            initial=rq[i];
        }
    }
    printf("Result: %d",net_head_movements);
}