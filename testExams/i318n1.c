#include <stdio.h>



int main(){
    
    int n;
    scanf("%d ",&n);
    
    char res[n];
    int razlika='A'-'a';
    int flag=0;
    char curr;
    
    for(int i = 0; i<n; i++){
        scanf("%c",&curr);
       
        if(curr=='_'){
            res[i]=curr;
            flag=0;
        }else if(curr!='_' && flag==0){
            if(curr>='A'&&curr<='Z'){
                res[i]=curr;
            }else{
                res[i]=curr+razlika;
            }
            flag=1;
        }else{
            res[i]=curr;
        }
        
        printf("%c",res[i]);
    }
    
    
    return 0;
}
