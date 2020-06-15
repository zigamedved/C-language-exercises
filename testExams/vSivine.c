#include <stdio.h>
#include <stdlib.h>


int main(int argc,char** argv){
    
    FILE* vhod = fopen(argv[1],"rb");
    FILE* izhod = fopen(argv[2],"wb");
    
    int sirina;
    int visina;
    int sum = 0;
    unsigned char R,G,B;
    
    fscanf(vhod,"%*s %d %d %*s\n",&sirina,&visina);
    fprintf(izhod,"P5\n");
    fprintf(izhod,"%d %d\n",sirina,visina);
    fprintf(izhod,"255\n");
    
    
    for(int i = 0; i<visina; i++){
        for(int j = 0; j<sirina; j++){
            sum=0;
            R=fgetc(vhod);
            G=fgetc(vhod);
            B=fgetc(vhod);
            sum=(30*R+59*G+11*B)/100;
        
            fprintf(izhod,"%c",sum);
            
		}
    }
    
    fclose(vhod);
    fclose(izhod);
    
    
    return 0;
}
