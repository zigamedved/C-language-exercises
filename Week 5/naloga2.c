 

/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga2.c
./test01

*/

#include <stdio.h>
#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    // dopolnite ...
    int* temp = *a;
    *a = *b;
    *b = temp;
    
}

void uredi(int** a, int** b, int** c) {
    // dopolnite ...
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
     int a = 10;
    int b = 20;
    int* pa = &a;
    int* pb = &b;

    zamenjaj(&pa, &pb);

    printf("*pa = %d, *pb = %d\n", *pa, *pb);
    printf("a = %d, b = %d\n", a, b);

    
    return 0;
    return 0;
}
