#include <stdio.h>

int main(){
    
    int max,n,rez,curr;
    max = 0; 
    rez = 0;
    
    scanf("%d",&n);
    
    for(int i = 0; i<n; i++){
        scanf("%d",&curr);
        
        if(curr>max){
            rez=max;
            max=curr;
        }else if(curr>rez){
            rez=curr;
        }
        
    }
    
    printf("%d\n",rez);
    
    
    
    return 0;
}
