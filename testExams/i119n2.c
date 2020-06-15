
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Vozlisce* obrni(Vozlisce* zacetek) {
    // popravite / dopolnite ...
    Vozlisce* prev=NULL;
    Vozlisce* current=zacetek;
    Vozlisce* iter=current;
    
    while(iter!=NULL){
        iter=iter->naslednje;
        current->naslednje=prev;
        prev=current;
        current=iter;
    }
    
    return prev;
}

int main() {
    // koda za ro"cno testiranje (dopolnite po "zelji/potrebi)
    return 0;
}
