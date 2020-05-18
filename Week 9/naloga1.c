
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k) {
    // popravite / dopolnite ...
    if(k==1)return NULL;
    
    int i = 1; 
    
    Vozlisce* sprosti;
    
    while(i<k){
        i++;
        if(zacetek->naslednje==NULL)return NULL;
        sprosti=zacetek;
        zacetek=zacetek->naslednje;
        free(sprosti);
    }
    Vozlisce* iter=zacetek;
    Vozlisce* povezi = zacetek;
    
    while(true){
        
        int count = 0;
        
        while(count<k && iter->naslednje!=NULL){
            //if(iter->naslednje==NULL)break;
            count++;
            //sprosti=iter;
            iter=iter->naslednje;
            //free(sprosti);
        }
        
        if(count==k){
            if(iter->naslednje==NULL){
                povezi->naslednje=iter;
                return zacetek;
            }
        }
        
        if(iter->naslednje==NULL){
            povezi->naslednje=NULL;
            break;
        }
        
        povezi->naslednje=iter;
        povezi=povezi->naslednje;
        
        
    }
     return zacetek;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    
    return 0;
}
