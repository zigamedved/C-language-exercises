#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(){
    
    //branje vhoda
    int n;
    scanf("%d",&n);
    
    char** datoteke = (char**)malloc(n*sizeof(char*));
    
    for(int i = 0; i<n; i++){
        datoteke[i] = (char*)malloc(101*sizeof(char));
        scanf("%s",datoteke[i]);
    }
    
    char* izhod = (char*)malloc(101*sizeof(char));
    scanf("%s",izhod);
    
    // odpiranje pointerjev...
    
    FILE* output = fopen(izhod,"w");
    
    FILE** pointerji = (FILE**)malloc(n*sizeof(FILE*));
    FILE* pointer;

    //INICIALIZACIJA POINTERJEV...
    for(int i = 0; i<n; i++){
        pointer=fopen(datoteke[i],"r");
        pointerji[i]=pointer;
    }
    
    int stPrebranih = 0;
    int* elementi = (int*)malloc(sizeof(int)*n);
    
    /*
    for(int i = 0; i<n; i++){
        printf("Zacetni elementi : %d\n",elementi[i]);
    }*/
    
    
    //pomoc iz Discorda
    while(stPrebranih<n){
        int min = INT_MAX;
        stPrebranih = 0;
        int ind=0;
        
        for(int i = 0; i<n; i++){
            //ce je 0 ga nadomestimo, ce ne uporabimo trenutnega
            if(elementi[i]==0){
                pointer=pointerji[i];
                fscanf(pointer,"%d",&elementi[i]);                
                //ce je se vedno nic vemo, da smo prisli pri tem 
                //fajlu do konca
                if(elementi[i]==0){
                    stPrebranih++;
                }
                
            }
        }
        
        if(stPrebranih==n)break;
        
        
        for(int j = 0; j<n; j++){
            if(elementi[j]<min && elementi[j]>0){
                min=elementi[j];
                ind=j;
            }
        }
        
        //zapisemo trenuten minimum;
        fprintf(output,"%d\n",min);
        
        //pomaknemo kazalec tistega fajla v katerem smo nasli minimum
        //za enega naprej?
        pointer=pointerji[ind];
        
        //ce pridemo do konca fajla vanj zapisemo 0?,ker ob koncu vrne //itak -1
        //int vmesno;
        if(fscanf(pointer,"%d",&elementi[ind])<0){
            //vmesno=elementi[ind];
            //printf("Na koncu fajla je: %d\n",vmesno);
            elementi[ind]=0;
        }
        
        //resetiramo minimum za naslednjo rundo
        min=INT_MAX;
        
    }
    //end pomoc
    
    /*
    for(int i = 0; i<n; i++){
        free(datoteke[i]);
        free(pointerji[i]);
        
    }
    fclose(output);
    free(pointer);
    */
    
    
    
    return 0;
}

