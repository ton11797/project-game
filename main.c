#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include"renderc.h"
#include"loadfile.h"
#define WORLDLEN 16
//prototype function
void delay(unsigned int);
void cursor(int,int);
int manu();

int main(){
    int n,i,*status,*ans,m,x,y,f=0,score;
    char *data,in[(WORLDLEN+1)],name[30],gc;
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
        render(n,data,status,score);
        delay(5000);
        for(i=0;i<n*n;i++){
            *(status+i)=0;
        }
        render(n,data,status,score);
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
                    render(n,data,status,score);
                    delay(1000);
                    *(status+x-1)=3;
                    *(status+y-1)=3;
                    render(n,data,status,score);
                    f++;
                    if(f>= n*n/2){
                        system("cls");
                        printf("GAME END\n");
                        printf("Enter your nick name: ");
                        scanf("%s",name);
                        savescore(name,score);
                        f=0;
                        break;
                        }
                }else{
                    score-=100;
                    *(status+x-1)=1;
                    *(status+y-1)=1;
                    render(n,data,status,score);
                    delay(3000);
                    *(status+x-1)=0;
                    *(status+y-1)=0;
                    render(n,data,status,score);
                }
            }else{
            printf("Try again!!\n");
            }
        }
        free(data);
        free(status);
    }
    if(n==99)break;
}
    return 0;
}
int manu(){
    system("cls");
    char title[6][100]={"     ________          ________          ________          ________     "
                         ,"    |\\   ____\\        |\\   __  \\        |\\   __  \\        |\\   ___ \\    "
                         ,"    \\ \\  \\___|        \\ \\  \\|\\  \\       \\ \\  \\|\\  \\       \\ \\  \\_|\\ \\   "
                         ,"     \\ \\  \\            \\ \\   __  \\       \\ \\   _  _\\       \\ \\  \\ \\\\ \\  "
                         ,"      \\ \\  \\____        \\ \\  \\ \\  \\       \\ \\  \\\\  \\|       \\ \\  \\_\\\\ \\ "
                         ,"       \\ \\_______\\       \\ \\__\\ \\__\\       \\ \\__\\\\ _\\        \\ \\_______\\"
                         ,"        \\|_______|        \\|__|\\|__|        \\|__|\\|__|        \\|_______|"};
    int i,s=0;
    for(i=0;i<=6;i++)printf("%s\n",title[i]);
    printf("%50s","press any key");
    getch();
    do{
        system("cls");
        for(i=0;i<=6;i++)printf("%s\n",title[i]);
        printf("%45s","Select manu\n");
        printf("%20s %s","","[1]Play Game\n");
        printf("%20s %s","","[2]Show Score\n");
        printf("%20s %s","","[3]Exit\n");
        printf("%10s %s","","Enter number[1-3]");
        scanf("%d",&i);
        if(i==3){
            return 99;
        }else if(i==1){
            system("cls");
            for(i=0;i<=6;i++)printf("%s\n",title[i]);
            printf("%45s","Select Level\n");
            printf("%20s %s","","[1]Easy\n");
            printf("%20s %s","","[2]Normal\n");
            printf("%20s %s","","[3]Hard\n");
            printf("%20s %s","","[4]Very Hard\n");
            printf("%20s %s","","[99]EXIT\n");
            printf("%10s %s","","Enter number[1-4,99]");
            scanf("%d",&i);
            if(i==99)return 99;
            while(i>4||i<1){
                printf("Enter again");
                scanf("%d",&i);
            }
            return i*2;

        }else if(i==2){
            system("cls");
            for(i=0;i<=6;i++)printf("%s\n",title[i]);
            printf("%45s","Scoreboard\n");
            readscore();
            printf("%10s %s","","press any key back to menu");
            getch();
        }else{
            return 99;
        }
    }while(i!=99);
    return 21;
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
