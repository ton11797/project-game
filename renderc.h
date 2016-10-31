#define WORLDLEN 16
#define CARDLONG 2
void render(int n,char *pdata,int *s){
	int i,j,k,l,v=1;
    char *data;
    data=pdata;
    system("cls");
	for (k = 0; k < n; ++k){
        for (i = 0; i < n; ++i){
                for (j = 0; j < WORLDLEN+2; ++j)if(*s!=3)printf("=");
                if(*s!=3)printf("  ");
                for (j = 0; j < WORLDLEN+4; ++j)if(*s==3)printf(" ");
                s++;
        }
        s-=n;
		printf("\n");
        for(l=0;l<CARDLONG;l++){
            for (i = 0; i < n; ++i){
                        if(*s!=3)printf("=");
                        for (j = 0; j < WORLDLEN; ++j)if(*s!=3)printf(" ");
                        if(*s!=3)printf("=  ");
                        for (j = 0; j < WORLDLEN+4; ++j)if(*s==3)printf(" ");
                        s++;
            }
            s-=n;
            printf("\n");
        }
            for(i=0;i<n;i++){
                if(*s==1){
                    printf("=");
                    if(strlen(data)<(WORLDLEN))for(j=0;j<((WORLDLEN)-strlen(data))/2;j++)printf(" ");
                    printf("%s",data);
                    if(strlen(data)<(WORLDLEN))for(j=0;j<((WORLDLEN)-strlen(data))/2;j++)printf(" ");
                    if(strlen(data)%2!=0)printf(" ");
                    data+=(WORLDLEN+1);
                    printf("=  ");
                    v++;
                }else if(*s==0){
                    printf("=");
                    for(j=0;j<WORLDLEN/2;j++)printf(" ");
                    printf("%d",v);
                    for(j=0;j<(WORLDLEN/2)-2;j++)printf(" ");
                    if(v<10)printf(" ");
                    printf("=  ");
                    v++;
                    data+=(WORLDLEN+1);
                }else{
                    for (j = 0; j < WORLDLEN+4; ++j)printf(" ");
                    v++;
                    data+=(WORLDLEN+1);
                }
            s++;
            }
		printf("\n");
        s-=n;
        for(l=0;l<CARDLONG;l++){
            for (i = 0; i < n; ++i){
                        if(*s!=3)printf("=");
                        for (j = 0; j < WORLDLEN; ++j)if(*s!=3)printf(" ");
                        if(*s!=3)printf("=  ");
                        for (j = 0; j < WORLDLEN+4; ++j)if(*s==3)printf(" ");
                        s++;
            }
            s-=n;
            printf("\n");
        }
        for (i = 0; i < n; ++i){
                for (j = 0; j < WORLDLEN+2; ++j)if(*s!=3)printf("=");
                if(*s!=3)printf("  ");
                for (j = 0; j < WORLDLEN+2; ++j)if(*s==3)printf(" ");
                if(*s==3)printf("  ");
                s++;
        }
        printf("\n");
	}
}
