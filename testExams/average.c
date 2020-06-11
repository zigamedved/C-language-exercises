
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // dopolnite ...
    int n;
    scanf("%d",&n);
    
    int povprecje=0;
    int trenuten=0;
    int vsota=0;
    
    for(int i = 0; i<n; i++){
        scanf("%d",&trenuten);
        
        if(trenuten<=povprecje){
            printf("%d\n",i);
            break;
        }
        
        vsota+=trenuten;
        povprecje=vsota/(i+1);        
        
        if(i==n-1)printf("%d\n",n);
    }
    
    

    return 0;
}
