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

//function save score
void savescore(char name[],int score){
    FILE *fp;
    fp = fopen("score.txt","a");
    fprintf(fp, "%s %d\n",name,score);
    fclose(fp);
}


void readscore(){
    FILE *fp;
    char read[30],name[50][30],keep[30];
    int score[50][10];
    int i,j,c=0;
    fp =fopen("score.txt","r");
    //read name and score in file
    fscanf(fp, "%s", read);
    while(strcmp(read,score[c-1])!=0){
        strcpy(name[c],read);
        fscanf(fp, "%s", read);
        strcpy(score[c],read);
        fscanf(fp, "%s", read);
        c++;
    }
    //sorting score
    for(i=0;i<c;i++){
        for(j=i+1;j<c;j++){
            if (atoi(score[i])<atoi(score[j])){
                strcpy(keep,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],keep);
                strcpy(keep,score[i]);
                strcpy(score[i],score[j]);
                strcpy(score[j],keep);
            }
        }
    }
    //print score
    for (i = 0; i < c; ++i){
        printf("%20s %d.%s %s\n","",i+1,name[i],score[i]);
    }
    fclose(fp);
}

