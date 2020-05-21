#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zamik=0;
char presledek=' ';

void izpisi(char* trenutnaVrstica,FILE* output){
   
    if(strlen(trenutnaVrstica)==0){
        for(int i = 0; i<zamik; i++){
                fprintf(output,"%c",presledek);
        }
        fprintf(output,"\n");
        return;
    }
 
    int count=0;
    int flag=0;
    int enkrat=0;
    char c;
    
    while(trenutnaVrstica[count]!='\0'){
        c=trenutnaVrstica[count];
        if(c=='{'){
            if(trenutnaVrstica[count+1]=='\0'){
                zamik+=4;
            }
        }
        if(c=='}')zamik-=4;
        if(c!=' '){
            flag=1;
        }
        
        if(flag==1 && enkrat== 0){
            //fprintf(output,"Zamik za to vrstico je %d",zamik);
            for(int i = 0; i<zamik; i++){
                fprintf(output,"%c",presledek);
            }
            enkrat=1;
        }
        
        if(flag==1){
            fprintf(output,"%c",c);
        }
        count++;    
    }
    fprintf(output,"\n");
}

int main(int argc, char** argv){
    
    char* vhod = argv[1];
    char* izhod = argv[2];
    //printf("%s %s",vhod,izhod);
    FILE* input = (FILE*)malloc(sizeof(FILE));
    FILE* output = (FILE*)malloc(sizeof(FILE));
    
    input = fopen(vhod,"r");
    output = fopen(izhod,"w");
    
    char* trenutnaVrstica = (char*)malloc(1005*sizeof(char));
    char c;
    int presledki=0;
    int count=0;
    
    while((c=fgetc(input))!=EOF){
            if(c=='\n'){
                trenutnaVrstica[count]='\0';
                izpisi(trenutnaVrstica,output);
                trenutnaVrstica=(char*)malloc(1005*sizeof(char));
                count=0;
            }else{
                trenutnaVrstica[count]=c;
                count++;
            }
    }
    
    free(trenutnaVrstica);
    fclose(input);
    fclose(output);
    
    return 0;
}
