#include<stdio.h>
#include<string.h>
void render(int n,char *data,int *s){
	int i,j,k,v=1;
	for (k = 0; k < n; ++k){
		for (i = 0; i < n; ++i)printf("==========  ");
		printf("\n");
        for(i=0;i<n;i++)printf("=        =  ");
		printf("\n");
		for(i=0;i<n;i++){
            if(*s==1){
                printf("=");
                if(strlen(data)<8)for(j=0;j<(8-strlen(data))/2;j++)printf(" ");
                printf("%s",data);
                if(strlen(data)<8)for(j=0;j<(8-strlen(data))/2;j++)printf(" ");
                if(strlen(data)%2!=0)printf(" ");
                data+=9;
                printf("=  ");
            }else{
                printf("=   %d   ",v);
                if(v<9)printf(" ");
                printf("=  ");
                v++;
            }
            s++;
		}
		printf("\n");
        for(i=0;i<n;i++)printf("=        =  ");
		printf("\n");
		for (i = 0; i < n; ++i)printf("==========  ");
        printf("\n");
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
