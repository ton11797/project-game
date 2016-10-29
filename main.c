#include<stdio.h>
#include<stdlib.h>
#include"renderc.h"
#include"gameprocess.h"
void adddata(char*,char[],int);

void main(){
    int n,i,*status;
    char *data,in[9];
    scanf("%d",&n);
    data =(char*)malloc(n*n*9);
    status =(int*)malloc(sizeof(int)*(n*n));
    for(i=0;i<n*n;i++){
        scanf("%s %d",in,status+i);
        adddata(data,in,i+1);
    }
    render(n,data,status);
    free(data);
    free(status);
}
void adddata(char *data,char value[9],int order){
    int i;
    order--;
    data+=order*9;
    for(i=0;i<10;i++,data++){
        *(data) = value[i];
    }
}
