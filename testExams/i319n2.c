
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // dopolnite ...
    int visina=0;
    int maxVisina=0;
    int n=0;
    scanf("%d\n",&n);
    
    char tab[n];
    char curr;
    
    for(int i = 0; i<n; i++){
        scanf("%c",&curr);
        tab[i]=curr;
        
        if(curr=='D'){
            if(visina>maxVisina){
                maxVisina=visina;
            }
            visina--;
        }else if(curr=='G'){
            visina++;
        }
    }

    int arr[maxVisina][n];
    int indeks1=(maxVisina-1);
    int indeks2=0;
    
    for(int i = 0; i<maxVisina; i++){
         for(int j = 0; j<n; j++){
             arr[i][j]='.';
        }
    }   
    
    char iter;
    
    for(int i = 0; i<n; i++){
        iter=tab[i];
        if(iter=='G'){
            arr[indeks1][indeks2]='/';
            indeks1--;
        }else if(iter=='D'){
            indeks1++;
            arr[indeks1][indeks2]='\\';
            
        }
        indeks2++;
    }
    
    for(int i = 0; i<maxVisina; i++){
        for(int j = 0; j<n; j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
