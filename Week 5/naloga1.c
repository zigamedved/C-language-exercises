
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga1.c
./test01

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    // popravite / dopolnite ...
    int * levo=t;
    int * desno=t;
    int stevec1=0;
    int stevec2=0;
    int *zacetek=NULL;
    
    while(*(levo-1)!=0){
        stevec1++;
        zacetek=levo;
        levo--;
    }
    zacetek=levo;
    
    while(*(desno+1)!=0){
        stevec2++;
        *konec=desno;
        desno++;
    }
    *konec=desno;
    
    *dolzina=0;
    *dolzina=stevec1+stevec2+1;
    
    return zacetek;
}

int main() {

    int tabela[] = {0, 3, 5, 2, 7, 1, -6, -4, 7, 2, -6, 9, -9, 0};
    int n = 0;
    int* pk = NULL;
    int* pz = poisci(tabela + 12, &n, &pk);
    printf("n = %d, *pz = %d, *pk = %d\n", n, *pz, *pk);

    exit(0);
    return 0;
   
}
