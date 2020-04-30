
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    // popravite / dopolnite ...
    int sum=0;
    for(int* i = zac; i<=kon; i++){
            sum+=*i;
    }
    
    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    // dopolnite ...
    if(*indeks==-1){
        *indeks=*kazalec-t;
    }else{
        *kazalec=t+(*indeks);
    }
    
}

void frekvenceCrk(char* niz, int** frekvence) {
    // dopolnite ...
    int* result=(int*)calloc(26,sizeof(int));
    char curr;
    curr=*niz;
    while(curr!='\0'){
        if(curr>='a' && curr<='z'){
            result[curr-'a']++;
        }else if(curr>='A' && curr<='z'){
            result[curr-'A']++;
        }
        
        niz++;
        curr=*niz;
    }

   *frekvence=result; 
    
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    int tabela[4];
    tabela[0]=1;
    tabela[1]=2;
    tabela[2]=3;
    tabela[3]=4;

    int* zac=tabela;
    int* kon=(tabela+3);

    printf("%d\n",vsota(zac,kon));

    return 0;
}
