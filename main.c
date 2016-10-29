#include<stdio.h>
#include<stdlib.h>
#include"renderc.h"
#include"gameprocess.h"
void adddata(char*,char[],int);

int main(){
    int n,i,*status,m;
    char *data,in[9];
    m=menu();
    system("cls");
    if(m==1){
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
    }else if(m==2){
        printf("static");
    }else{
        return 0;
    }
}
void adddata(char *data,char value[9],int order){
    int i;
    order--;
    data+=order*9;
    for(i=0;i<10;i++,data++){
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
