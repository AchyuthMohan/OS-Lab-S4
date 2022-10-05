#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter the disk size: \n");
    int n,m;
    scanf("%d",&n);
    printf("Enter the number of requests: \n");
    scanf("%d",&m);
    int rs[m];
    printf("Enter the request array: \n");
    for(int i=0;i<m;i++){
        scanf("%d",&rs[i]);
    }
    printf("Enter the initial position: \n");
    int initial;
    scanf("%d",&initial);
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(rs[i]>rs[j]){
                int temp=rs[i];
                rs[i]=rs[j];
                rs[j]=temp;
            }
        }
    }
    int index;
    for(int i=0;i<m;i++){
        if(initial<=rs[i]){
            index=i;
            break;
        }
    }
    int seek_time=0;
    printf("1. High to low  2.Low to high: \n");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:{
            for(int i=index;i<m;i++){
                printf("%d\t",rs[i]);
                seek_time+=abs(initial-rs[i]);
                initial=rs[i];
            }
        }
        case 2:{

        }
    }
}