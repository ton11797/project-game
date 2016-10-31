#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include"renderc.h"
#include"gameprocess.h"
#include"loadfile.h"
#define WORLDLEN 16
void adddata(char*,char[],int);
void delay(unsigned int);
int inputcard(int,int);
int main(){
    int n,i,*status,*ans,m,c=0,x,y;
    char *data,in[(WORLDLEN+1)];
    while(1){
    scanf("%d",&n);
    system("cls");
    //prepare data
    data =(char*)malloc(n*n*(WORLDLEN+1));
    status =(int*)malloc(sizeof(int)*(n*n));
    ans =(int*)malloc(sizeof(int)*(n*n));
    loadworld(data,ans,n);
    for(i=0;i<n*n;i++){
        *(status+i)=1;
    }
    render(n,data,status);
    delay(5000);
    for(i=0;i<n*n;i++){
        *(status+i)=0;
    }
    render(n,data,status);
    for(i=0;i<n*n;i++){
        printf("%d ",*(ans+i));
    }
    printf("\n");
/*
    for(i=0;i<n*n;i++){
        *(status+i)=1;
        render(n,data,status);
    }*/
    while(c==0){
        scanf("%d %d",&x,&y);
        if(x<=(n*n)&&y<=(n*n)&&x!=y){
            printf("%d %d",*(ans+x-1),*(ans+y-1));
            if(*(ans+x-1)==*(ans+y-1)){
                *(status+x-1)=3;
                *(status+y-1)=3;
                render(n,data,status);
            }else{
                *(status+x-1)=1;
                *(status+y-1)=1;
                render(n,data,status);
                delay(3000);
                *(status+x-1)=0;
                *(status+y-1)=0;
                render(n,data,status);
            }
        }else{
        printf("Try again!!\n");
        }
    }
    free(data);
    free(status);
}
}
void adddata(char *data,char value[(WORLDLEN+1)],int order){
    int i;
    order--;
    data+=order*(WORLDLEN+1);
    for(i=0;i<WORLDLEN+2;i++,data++){
        *(data) = value[i];
    }
}
int menu(){
    int s;
    printf("1.Start Game\n");
    printf("2.Show score\n");
    printf("3.Exit\n");
    printf("Select 1-3 :");
    scanf("%d",&s);
    return s;
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

