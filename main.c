#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"conio.h"
#include<time.h>
#include"renderc.h"
#include"loadfile.h"
#include<windows.h>
#define WORLDLEN 16
//color.h
#define textcolor(txt,back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
//prototype function
void delay(unsigned int);
void cursor(int,int);
int manu();

int main(){
    int n,i,*status,*ans,m,x,y,f=0,score;
    char *data,in[(WORLDLEN+1)],name[30];
    while(1){
    n = manu();
    system("cls");
    if(n<20){
        //prepare data
        score=n*n*100;
        data =(char*)malloc(n*n*(WORLDLEN+1));
        status =(int*)malloc(sizeof(int)*(n*n));
        ans =(int*)malloc(sizeof(int)*(n*n));
        loadworld(data,ans,n);
        //game process
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
        //user input and process
        while(1){
            printf("Enter 2 card number :");
            scanf("%d %d",&x,&y);
            if(x<=(n*n)&&y<=(n*n)&&x!=y){
                printf("%d %d",*(ans+x-1),*(ans+y-1));
                if(*(ans+x-1)==*(ans+y-1)){
                    *(status+x-1)=1;
                    *(status+y-1)=1;
                    render(n,data,status);
                    delay(1000);
                    *(status+x-1)=3;
                    *(status+y-1)=3;
                    render(n,data,status);
                    f++;
                    if(f>= n*n/2){
                        system("cls");
                        printf("GAME END\n");
                        printf("Enter your nick name: ");
                        scanf("%s",name);
                        savescore(name,score);
                        f=0;
                        getch();
                        break;}
                }else{
                    score-=100;
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
    return 0;
}
int manu(){
    char title[6][100]={"     ________          ________          ________          ________     "
                         ,"    |\\   ____\\        |\\   __  \\        |\\   __  \\        |\\   ___ \\    "
                         ,"    \\ \\  \\___|        \\ \\  \\|\\  \\       \\ \\  \\|\\  \\       \\ \\  \\_|\\ \\   "
                         ,"     \\ \\  \\            \\ \\   __  \\       \\ \\   _  _\\       \\ \\  \\ \\\\ \\  "
                         ,"      \\ \\  \\____        \\ \\  \\ \\  \\       \\ \\  \\\\  \\|       \\ \\  \\_\\\\ \\ "
                         ,"       \\ \\_______\\       \\ \\__\\ \\__\\       \\ \\__\\\\ _\\        \\ \\_______\\"
                         ,"        \\|_______|        \\|__|\\|__|        \\|__|\\|__|        \\|_______|"};
    int i,s=0;
    for(i=0;i<=6;i++)printf("%s\n",title[i]);
        switch(s){
            case 0:{
                printf("%50s","press any key");
            }
        }
        return 2;
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void cursor(int x,int y){
COORD cursor;
cursor.X =x;
cursor.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cursor);
}
