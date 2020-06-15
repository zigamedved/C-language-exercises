
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    // dopolnite ...
    char* imeVhoda = (char*)malloc(21*sizeof(char));
    char* imeIzhoda = (char*)malloc(21*sizeof(char));
    int n;
    
    scanf("%s",imeVhoda);
    scanf("%d",&n);
    scanf("%s",imeIzhoda);
    
    FILE* vhod=fopen(imeVhoda,"rb");
    FILE* izhod=fopen(imeIzhoda,"w");
    
    int rez1=0;
    int rez2=0;
    int rez3=0;
    int R,G,B;
    
    while(true){
        for(int j = 0; j<n; j++){
            R=fgetc(vhod);
            G=fgetc(vhod);
            B=fgetc(vhod);
            
            if(R>0 &&G==0 &&B==0){
                rez1++;
            }else if(R==0 && G>0 && B==0){
                rez2++;
            }else if (R==0 && G ==0 && B>0){
                rez3++;
            }
        }
        break;
    }
    
    fprintf(izhod,"%d\n%d\n%d",rez1,rez2,rez3);
    
    return 0;
}
