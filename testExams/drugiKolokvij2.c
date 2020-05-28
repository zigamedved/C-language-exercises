
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Vozlisce* prepleti(Vozlisce** seznami, int n) {
    // popravite / dopolnite ...
    int stevec = 0;
    Vozlisce* current;
    for(int i = 0; i<n; i++){
        current=seznami[i];
        while(current!=NULL){
              current=current->naslednje;
              stevec++;
        }
    }
    Vozlisce* rezultat = (Vozlisce*)malloc(stevec*sizeof(Vozlisce));
    Vozlisce* nastavi=rezultat;
    
    int indeks=0;
    int prekini = 0;
    int rezerva=0;
    
    Vozlisce* trenuten;
    while(true){
        if(prekini==n)break;
        prekini=0;
        for(int i = 0; i<n; i++){
            trenuten=seznami[i];
            rezerva=indeks;
            while(rezerva>0 && trenuten!=NULL){
                trenuten=trenuten->naslednje;
                rezerva--;
            }
            if(trenuten==NULL){
                prekini++;
                continue;
            }else{
                Vozlisce* novo = malloc(sizeof(Vozlisce));
                novo->podatek=trenuten->podatek;
                nastavi->naslednje=novo;
                nastavi=nastavi->naslednje;
            
            }
        }
        indeks++;
    }
    return rezultat->naslednje;
    
}

int main() {
    return 0;
}
