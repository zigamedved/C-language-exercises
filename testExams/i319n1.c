
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    // dopolnite ...
    char* imeVhoda=(char*)malloc(21*sizeof(char));
    char* imeIzhoda=(char*)malloc(21*sizeof(char));
    int n;
    scanf("%s%d%s",imeVhoda,&n,imeIzhoda);
    
    FILE* vhod = fopen(imeVhoda,"rb");
    FILE* izhod = fopen(imeIzhoda,"w");
  
    int curr;
    int remainder;
    
    int first=0;
    int second2=0;
    char second;
    int first2=0;
    
    int flag=0;
    int flag1=0;
    
    for(int i = 0; i<n; i++){
        curr=fgetc(vhod);
        
        remainder=curr%16;
        if(remainder==15){
            second='F';
        }else if(remainder==14){
            second='E';
        }else if(remainder==13){
            second='D';
        }else if(remainder==12){
            second='C';
        }else if(remainder==11){
            second='B';
        }else if(remainder==10){
            second='A';
        }else if(remainder==0){
                second='0';
        }else{
            flag=1;
            second2=remainder;
        }
        curr/=16;
        remainder=curr%16;

        if(remainder==15){
            first='F';
        }else if(remainder==14){
            first='E';
        }else if(remainder==13){
            first='D';
        }else if(remainder==12){
            first='C';
        }else if(remainder==11){
            first='B';
        }else if(remainder==10){
            first='A';
        }else if(remainder==0){
                first='0';
        }else{
            flag1=1;
            first2=remainder;
        }
        
        if(flag1==1 && flag==1){
            fprintf(izhod,"%d%d\n",first2,second2);
        }else if(flag1==1 && flag==0){
            fprintf(izhod,"%d%c\n",first2,second);
        }else if(flag1==0&&flag==1){
            fprintf(izhod,"%c%d\n",first,second2);
        }else{
            fprintf(izhod,"%c%c\n",first,second);
        }
        
        flag=0;
        flag1=0;
        //fprintf(izhod,"\n");
        //fprintf(izhod,"%02X\n",curr);
    }
    return 0;
}
