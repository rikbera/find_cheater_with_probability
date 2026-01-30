#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <string.h>
char coin_flip(void){
    if(rand()%2==1){
        return 'H';
    }
    else{
        return 'T';
    }
}
char Bias_coin(){
     if(rand()%4<3){
        return'H';
    }
    else{
        return'T';
    }
}
char **Detective(int TOSS_PP,int TEST_SUB,char coinfilp[TEST_SUB][TOSS_PP]){
    char **arr=malloc(TEST_SUB*sizeof(char*));
    int head_percente,tale_percente;
    int num_head=0,num_tale=0;
    for(int i=0;i<TEST_SUB;i++){
        num_head=0,num_tale=0,head_percente=0,tale_percente=0;
        for(int j=0;j<TOSS_PP;j++){
            if(coinfilp[i][j]=='H'){
                num_head++;
            }
            else{
                num_tale++;
            }
            
        }
        head_percente=num_head*100/(num_head+num_tale);
        tale_percente=num_tale*100/(num_head+num_tale);
        if(head_percente>66){
            arr[i]="cheater";
        }
        else{
            arr[i]="FAIR";
        }
    }   
    return arr;
  
}
int main(){

    srand(time(NULL));
    int CHEAT=90,TOSS_PP=20,TEST_SUB=1030,subject_num=0;
    
    char coinfilp[TEST_SUB][TOSS_PP];
    
    int CHeat_Pre=0,FAIR_pre=0;
    for(int i=0;i<CHEAT;i++){
        
        for(int j=0;j<TOSS_PP;j++){
            coinfilp[i][j]=Bias_coin();
        }
    }
    for(int i=CHEAT;i<TEST_SUB;i++){
        
        for(int j=0;j<TOSS_PP;j++){
            coinfilp[i][j]=coin_flip();
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<TOSS_PP;j++){
           // printf("%c",coinfilp[i][j]);
        }
        //printf("\n");
    }
    char **results = Detective(TOSS_PP, TEST_SUB, coinfilp);
    for(int i=0;i<TEST_SUB;i++){
    (strcmp(results[i], "FAIR") == 0) ? FAIR_pre++ : CHeat_Pre++;   
         
    
    //printf("%s",results[i]) ;
    //printf("\n");   

    }
    printf("FAIR PREDICTION==%d,Cheater PRE==%d",FAIR_pre,CHeat_Pre);






free(results);


    return 0;
}

//next low the possible toss and find perfect suspection percentage
