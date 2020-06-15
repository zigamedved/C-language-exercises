
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // dopolnite ...
    
    char* imeVhoda = (char*)malloc(21*sizeof(char));
    char* imeIzhoda = (char*)malloc(21*sizeof(char));
    
    char iscemo;
    scanf("%s %s\n",imeVhoda,imeIzhoda);
    scanf("%c",&iscemo);
    
    //printf("\n%s %s",imeVhoda,imeIzhoda);
    //printf("\n%c\n",iscemo );
    
    FILE* vhod = fopen(imeVhoda,"r");
    FILE* izhod = fopen(imeIzhoda,"w");
    
    char* rezultat = (char*)malloc(1001*sizeof(char));
    char* trenutna = (char*)malloc(1001*sizeof(char));
    
    int indeks=0;
    
    int trenuten;
    int flag=0;
    
    while((trenuten=fgetc(vhod))!=EOF){
            if(trenuten=='\n'){
                    trenutna[indeks]='\0';
                    if(flag==1){
                        strcpy(rezultat,trenutna);
                       flag=0;
                    }
                    indeks=0;
                    trenutna = (char*)malloc(1001*sizeof(char));
                    continue;
            }
                
            if(trenuten==iscemo){
                flag=1;
            }
            
            trenutna[indeks]=trenuten;
            indeks++;
            
    }
    
    
    fprintf(izhod,"%s",rezultat);
    
    
    return 0;
}
