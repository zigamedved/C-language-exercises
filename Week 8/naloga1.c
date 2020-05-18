
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

int prestej(Student** studentje, int stStudentov,char* predmet){
    int count=0;
    for(int i = 0; i<stStudentov; i++){
        Student* current = studentje[i];
        int num = current->stPO;
        for(int j = 0; j<num; j++){
            if(strcmp(predmet,current->po[j].predmet)==0){
                if(current->po[j].ocena>=6){
                        count++;
                        //printf("PREDMET %s\n",predmet);
                }
            }
        }
    }
    return count;
}

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    // popravite / dopolnite ...
    //najprej se moram sprehoditi cez tabelo ucencev in presteti koliko jih 
    //je opravilo ta predmet
    *stVO=prestej(studentje,stStudentov,predmet);
    //printf("Number of students who passed :%d\n",*stVO);
    VO** vrni = (VO**)malloc(*stVO*sizeof(VO*));
    //inicializiram tabelo
    for(int i = 0; i<*(stVO); i++){
        vrni[i]=(VO*)malloc(sizeof(VO));
    }
    //napolnim,posortiram,posortiram
    int count = 0;
    VO* tren;
    for(int i = 0; i<stStudentov; i++){
        Student* current = studentje[i];
        int num = current->stPO;
        for(int j = 0; j<num; j++){
            if(strcmp(predmet,current->po[j].predmet)==0){
                if(current->po[j].ocena>=6){
                        tren = (VO*)malloc(sizeof(VO));
                        tren->vpisna = current->vpisna;
                        tren->ocena = current->po[j].ocena;
                        vrni[count]=tren;
                        count++;
                }
            }
        }
    }
    //posortiraj,posortiraj... hope so
    int n = *stVO;
    
    //sort ocen??
    for(int i = 0; i<n-1;i++){
        for(int j = 0; j<n-i-1;j++){
            if(vrni[j]->ocena<vrni[j+1]->ocena){
                VO* temp = vrni[j];
                vrni[j]=vrni[j+1];
                vrni[j+1]=temp;
            }
        }
    }
    
    //sort vpisnih if ocene enake
    for(int i = 0; i<n-1;i++){
        for(int j = 0; j<n-i-1;j++){
            if(vrni[j]->ocena==vrni[j+1]->ocena){
                if(vrni[j]->vpisna>vrni[j+1]->vpisna){
                    VO* temp = vrni[j];
                    vrni[j]=vrni[j+1];
                    vrni[j+1]=temp;
                }
            }
        }
    }
    
    return vrni;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    
    //testni primer vzet iz ucilnice FRI 18.5.2020
    //ZACETEK
    Student* studentje[] = {
        (Student[]) {
            888,
            (PO[]){{"FIZ", 10}, {"P1", 7}, {"P2", 8}, {"OMA", 5}, {"ODV", 9}},
            5
        },
        (Student[]) {
            333,
            (PO[]){{"", 0}},
            0
        },
        (Student[]) {
            555,
            (PO[]){{"FIZ", 6}, {"P2", 8}, {"ARS", 5}, {"ODV", 9}},
            4
        },
        (Student[]) {
            111,
            (PO[]){{"P1", 7}, {"ARS", 6}},
            2
        },
        (Student[]) {
            777,
            (PO[]){{"P1", 10}, {"FIZ", 7}, {"ODV", 8}},
            3
        },
    };
    int stStudentov = sizeof(studentje) / sizeof(studentje[0]);
    
    izvedi(studentje, stStudentov, "FIZ");
    izvedi(studentje, stStudentov, "P1");
    izvedi(studentje, stStudentov, "P2");
    izvedi(studentje, stStudentov, "ODV");
    izvedi(studentje, stStudentov, "ARS");
    izvedi(studentje, stStudentov, "OMA");
    izvedi(studentje, stStudentov, "DS");
    
    //KONEC
    
    return 0;
}
