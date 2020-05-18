
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    // popravite / dopolnite ...
    for(int i = 0; i<stStudentov; i++){
        if(studentje[i]->vpisna==vpisna)return i;
        
    }
    
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    // popravite / dopolnite ...
    for(int i = 0; i<student->stPO; i++){
         if(strcmp(student->po[i].predmet,predmet)==0)return i;
     }
    
    
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    // popravite / dopolnite ...
    int stevilo=stStudentov;
    int poisci=poisciStudenta(studentje,stStudentov,vpisna);
    
    if(poisci!=-1){
        Student* tmp = studentje[poisci];
        int poisciPredmet=poisciPO(studentje[poisci],predmet);
        
        if(poisciPredmet!=-1){
            PO* vmesni=tmp->po;
            vmesni=vmesni+poisciPredmet;
            vmesni->ocena=ocena;
        }else{
           
            PO* nova = (PO*)malloc(sizeof(PO));
            strcpy(nova->predmet,predmet);
            nova->ocena=ocena;
            int stanje=tmp->stPO;
            PO* vmesni=tmp->po;
            vmesni=vmesni+stanje;
            vmesni=nova;
        }
        
    }else{
        Student* novo = (Student*)malloc(sizeof(Student));
        PO* trenutni = (PO*)malloc(10*sizeof(PO));
        strcpy(trenutni->predmet,predmet);
        trenutni->ocena=ocena;
        novo->po=trenutni;
        studentje[stStudentov]=novo;
        stevilo+=1;
    
    }

    return stevilo;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
