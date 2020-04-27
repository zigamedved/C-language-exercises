
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long x, long a, long b) {
    // popravite / dopolnite ...
     long izpis=-1;
     long vrednost = 1;
    for(long i = a; i<=b; i++){
        vrednost=f(i);
        if(vrednost==x){
            izpis=i;
            break;
        }
    }
    //printf("%ld",izpis);
    return izpis;
    
    
    
    return -1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
