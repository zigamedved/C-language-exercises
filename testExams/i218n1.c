#include <stdio.h>


int main(){

    int n;
    scanf("%d ",&n);

    int plusi=0;
    int vse=0;
    int flag=0;
    int buffered=0;
    char curr;    
    
    for(int i = 0; i<n; i++){
        scanf("%c",&curr);
        if(flag==0&&curr=='+'){
            flag=1;
            continue;
        }
        
        if(flag==1 && curr=='+'){
            vse+=buffered;
            buffered=1;
            plusi++;
        }else if(flag==1 && curr=='-'){
            buffered++;
        }
        
    }
    
    //printf("%d %d\n",vse,plusi);
    printf("%d\n",(vse+1)/plusi);
 
    return 0;
}
