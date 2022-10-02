#include<stdio.h>
struct frame{
    int pno;
    int index;
};
int main(){
    int p,f,miss=0;
    printf("Enter the number of frames: \n");
    scanf('%d',&f);
    printf("Enter the number of pages: \n");
    scanf("%d",&p);
    int pages[p];
    printf("Enter the pages string: \n");
    for(int i=0;i<p;i++){
        scanf("%d",&pages[i]);
    }
}