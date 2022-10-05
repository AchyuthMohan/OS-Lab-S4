#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,m;
    printf("Enter the size of disk: \n");
    scanf("%d",&n);
    printf("Enter the number of processes to be seeked: \n");
    scanf("%d",&m);
    int rq[m];
    printf("Enter the request queue: \n");
    for(int i=0;i<m;i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the initial: \n");
    int initial;
    scanf("%d",&initial);
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(rq[i]>rq[j]){
                int temp=rq[i];
                rq[i]=rq[j];
                rq[j]=temp;
            }
        }
    }
    int index,result=0;
    for(int i=0;i<m;i++){
        if(initial<=rq[i]){
            index=i;
            break;
        }
    }
    result+=abs(initial-(n-1));
    result+=abs((n-1));
    result+=abs(rq[index-1]-0);
    
    printf("%d",result);

}