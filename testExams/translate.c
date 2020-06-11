
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

void cpy(int* source, int* destination){
    int num=0;
    while(source[num]!=0){
            destination[num]=source[num];
            num++;
    }
}

void pretvori(int** t) {
    // dopolnite ...
    int* current;
    int* pointer;
    int index=0;
    
    while(t[index]!=NULL){
        current = (int*)malloc(1000*sizeof(int));
        pointer=t[index];
        cpy(pointer,current);
        t[index]=current;
        index++;
    }
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}
