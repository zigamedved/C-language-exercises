 
#include <stdio.h>

int main(){
    
    int flag,n,prvo,trenutno;
    flag = 1;
    
    scanf("%d",&n);
    
    for(int i = 0; i<n; i++){
        if(i == 0){
            scanf("%d",&prvo);
            trenutno=prvo;
        }else{
            scanf("%d",&trenutno);
        }
        
        if(prvo!=trenutno){
            flag=0;
            break;
        }
        
        
        
        
    }
    printf("%d",flag);
    
    return 0;
}
