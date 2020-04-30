 /*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga2.c
./test01

*/

#include <stdio.h>
#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    // dopolnite ...
    int *temp = *b;
    *b = *a;
    *a = temp;
}

//30 20 10 --> 10 20 30
//10 20 30 --> return
//10 30 20 --> 10 20 30
//20 30 10 --> 20 10 30 
//20 10 30 --> 10 20 30
//30 10 20 --> 10 30 20 --> 10 20 30

void uredi(int** a, int** b, int** c) {
    // dopolnite ...
    if(**a>=**b && **a>=**c){
        if(**b>=**c){
           zamenjaj(a,c);
           return;
        }else if(**b<=**c){
            zamenjaj(b,c);
            zamenjaj(a,c);
            return;
        }
    }else if(**b>=**a && **b>=**c){
        if(**c>=**a){
            zamenjaj(b,c);
            return;
        }else if(**c<=**a){
            zamenjaj(b,c);
            zamenjaj(b,a);
            return;
        }
    }else if(**b<=**a && **b<=**c){
        if(**a<=**c){
            zamenjaj(b,a);
            return;
        }else if(**a>=**c){
            zamenjaj(b,a);
            zamenjaj(b,c);
            return;
        }
    }
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    int a = 24;
    int b = -12;
    int c = 36;

    int* pa = &a;
    int* pb = &b;
    int* pc = &c;

    uredi(&pa, &pb, &pc);

    printf("*pa = %d, *pb = %d, *pc = %d\n", *pa, *pb, *pc);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
