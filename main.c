#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"renderc.h"
#include"gameprocess.h"
#define WORLDLEN 16
void adddata(char*,char[],int);

int main(){
    int n,i,*status,*ans,m;
    char *data,in[(WORLDLEN+1)];
    while(1){
    scanf("%d",&n);
    system("cls");
    //prepare data
    data =(char*)malloc(n*n*(WORLDLEN+1));
    status =(int*)malloc(sizeof(int)*(n*n));
    ans =(int*)malloc(sizeof(int)*(n*n));

    for(i=0;i<n*n;i++){
        scanf("%s %d",in,status+i);
        adddata(data,in,i+1);
    }
    render(n,data,status);
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
