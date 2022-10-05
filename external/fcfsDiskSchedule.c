#include<stdio.h>
#include<stdlib.h>
#define size 25
int main(){
    int n,rs[size],initial,result=0;
    printf("Enter the number of requests: \n");
    scanf("%d",&n);
    printf("Enter the request sequence: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&rs[i]);
    }
    printf("Enter the initial head position: \n");
    scanf("%d",&initial);
    for(int i=0;i<n;i++){
        printf("%d",rs[i]);
        result+=abs(rs[i]-initial);
        initial=rs[i];
    }

printf("Result: %d",result);
}