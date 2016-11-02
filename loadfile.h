#define WORLDLEN 16
void loadworld(char *pdata,int *use,int n){
    //read word to array
    FILE *fp;
    char world[100][WORLDLEN];
    char read[WORLDLEN],*data;
    int i=0,j,cc,c=0;
    data=pdata;
    fp = fopen("text.txt","r");
    while (fgets(read, WORLDLEN, fp) != NULL) {
        if(read[strlen(read)-1]=='\n')read[strlen(read)-1]='\0';
        strcpy(world[c],read);
        c++;
    }
    //switching word
    int r,r2,keep;
    time_t t;
    srand((unsigned) time(&t));
    for(i=0;i<n*n/2;i++){
        r=rand()%c;
        cc=0;
        for(j=0;j<i&&i!=0;j++){
            if(*(use+j)==r)cc++;
        }
        if(cc==0){
            *(use+i)=r;
            *(use+i+(n*n/2))=r;
        }else{
            i--;
        }
    }
    for(i=0;i<n*n;i++){
        r=rand()%(n*n);
        r2=rand()%(n*n);
        if(r!=r2){
            keep=*(use+r);
            *(use+r)=*(use+r2);
            *(use+r2)=keep;
        }
    }
    //send word to main programm
   for(i=0;i<n*n;i++){
    	strcpy(data,world[*(use+i)]);
    	data+=WORLDLEN+1;
    }
    fclose(fp);
}