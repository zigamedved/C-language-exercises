#include <stdio.h>
#include <stdlib.h>


int main(){
        
    int n;
    scanf("%d",&n);
    int tab[n];
    
    for(int i = 0; i<n; i++){
        scanf("%d",&tab[i]);
    }
    
    int rez=0;
    int tren;
    int flag=0;
    for(int i = 0; i<n; i++){
        //printf("%d",tab[i]);
        tren=tab[i];
        for(int j = i; j<n; j++){
            if(tren<tab[j]){
                flag=1;
            }
        }
        if(flag){
            flag=0;
        }else{
            rez++;
        }
    }
    
    printf("%d\n",rez);
    
    
    
    
    
    return 0;
}
