#include<stdio.h>
#include<string.h>
void render(int n,char *data,int *s){
	int i,j,k,v=1;
	for (k = 0; k < n; ++k){
        for (i = 0; i < n; ++i){
                if(*s!=3)printf("==========  ");
                if(*s==3)printf("            ");
                s++;
        }
        s-=n;
		printf("\n");
        for (i = 0; i < n; ++i){
                if(*s!=3)printf("=        =  ");
                if(*s==3)printf("            ");
                s++;
        }
        s-=n;
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
                    v++;
                }else if(*s==0){
                    printf("=   %d   ",v);
                    if(v<9)printf(" ");
                    printf("=  ");
                    v++;
                }else{
                    printf("            ");
                }
            s++;
            }
		printf("\n");
        s-=n;
        for (i = 0; i < n; ++i){
                if(*s!=3)printf("=        =  ");
                if(*s==3)printf("            ");
                s++;
        }
		printf("\n");
        s-=n;
        for (i = 0; i < n; ++i){
                if(*s!=3)printf("==========  ");
                if(*s==3)printf("            ");
                s++;
        }
        printf("\n");
	}
}
