
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    // popravite / dopolnite ..
    int sum=0;
    while(zacetek!=NULL){
        sum+=zacetek->podatek;
        zacetek=zacetek->naslednje;
    }
    return sum;
}

int vsotaR(Vozlisce* zacetek) {
    // popravite / dopolnite ...
    if(zacetek==NULL)return 0;    
    return zacetek->podatek+vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    
    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek=element;
    
    if( zacetek == NULL || zacetek->podatek>element){
        novo->naslednje=zacetek;
        return novo;
    }else{
        Vozlisce* head = zacetek;
    
        
        while(head->naslednje!=NULL && head->naslednje->podatek<element){
            head=head->naslednje;
        }
        
        novo->naslednje=head->naslednje;
        head->naslednje=novo;
    
    }
    return zacetek;
  
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
    
    if(zacetek==NULL || zacetek->podatek>element){
        Vozlisce* novo = (Vozlisce*)malloc(sizeof(Vozlisce));
        novo->podatek=element;
        novo->naslednje=zacetek;
        return novo;
    }
    
    zacetek->naslednje=vstaviUrejenoR(zacetek->naslednje,element);
    
    return zacetek;
    
}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
