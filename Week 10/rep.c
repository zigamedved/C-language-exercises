#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
    
    char* vhod = argv[1];
    int n = atoi(argv[2]);
    //printf("%d\n",n);
    FILE* input = fopen(vhod,"r");
    
    char** tab = (char**)malloc(1000000*sizeof(char*));
    char* trenutnaVrstica = (char*)malloc(12*sizeof(char));
    char c;
    
    int presledki=-1;
    int count=0;
    int i=0;
    
    while((c=fgetc(input))!=EOF){
            if(c=='\n'){
                presledki++;
                trenutnaVrstica[count]='\0';
                tab[i]=trenutnaVrstica;
                i++;
                trenutnaVrstica=(char*)malloc(12*sizeof(char));
                count=0;
            }else{
                trenutnaVrstica[count]=c;
                count++;
            }
    }
    if(presledki==-1)exit(0);
    //printf("vrstic je %d\n",presledki);
    
    if(n>presledki){
        for(int j = 0; j<i-1; j++){
            printf("%s\n",tab[j]);
        }
    }else{
        int indeks=presledki-n;
        for(int j = indeks; j<presledki; j++){
            printf("%s\n",tab[j]);
        }
    }
    
    fclose(input);
    free(tab);
    free(trenutnaVrstica);
    
    return 0;
}

