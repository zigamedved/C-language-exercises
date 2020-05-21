#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    char* imeVhoda = (char*)malloc(101*sizeof(char));
    char* imeIzhoda = (char*)malloc(101*sizeof(char));
    
    scanf("%s %s",imeVhoda,imeIzhoda);
    
    FILE *vhod = fopen(imeVhoda,"r");
    FILE *izhod = fopen(imeIzhoda,"w");
    
    if(vhod==NULL){
        printf("Can't open file\n");
        exit(1);
    }
    
    char* izpisi  = (char*)malloc((1000000)*sizeof(char));
    char* vrstica = (char*)malloc((1000000)*sizeof(char));
    int c;
    int count=0;
    int max = 0;
    while((c=fgetc(vhod))!=EOF){
        if(c=='\n'){
            if(count>max){
                //vrstica[count]='\0';
                //printf("trenutna vrstica %s\n",vrstica);
                strcpy(izpisi,vrstica);
                max=count;
            }
            count = 0;
        }else{
            vrstica[count]=c;
            count++;
        }
    }
    
    //izpisi[max+1]='\0';
    
    
    fprintf(izhod,"%s\n",izpisi);
        
    fclose(vhod);
    fclose(izhod);
    free(vrstica);
    free(izpisi);
    
    return 0;
}



