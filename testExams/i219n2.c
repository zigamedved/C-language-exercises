
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga2.h"

void uredi(Oseba** osebe, int n) {
    // dopolnite ...
    
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(strcmp(osebe[j]->ime,osebe[j+1]->ime)>0){
                Oseba* temp = osebe[j];
                osebe[j]=osebe[j+1];
                osebe[j+1]=temp;
            }
        }
    }
}

int main() {
    // koda za ro"cno testiranje (dopolnite po "zelji/potrebi)
    return 0;
}
