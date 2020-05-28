
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    // dopolnite ...
    FILE* vhod = fopen(argv[1],"r");
    int vrstica=atoi(argv[2]);
    int stolpec=atoi(argv[3]);
    int rezerva=stolpec;
    
    int cur=0;
    char* beseda = (char*)malloc(10000*sizeof(char));
    int indeks=0;
    
    while((cur=fgetc(vhod))!=EOF){
        if(vrstica==1 && cur == '\n')break;
        if(stolpec==1 && vrstica==1){
            if(cur==' '){
                break;
            }
            beseda[indeks]=cur;
            indeks++;
        }else{
            if(cur==' '){
                stolpec--;
            }    
            if(cur=='\n'){
                vrstica--;
                stolpec=rezerva;
            }
        }
    }
    beseda[indeks]='\0';
    for(int i = 0; i<indeks; i++){
        printf("%c",beseda[i]);
    }
    printf("\n");
    
    return 0;
}
