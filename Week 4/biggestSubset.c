#include <stdio.h>


int main(){
    
    int n;
    scanf("%d",&n);
    
    int sum=0;
    int maxSum=-2147483648;
    int curr;
    
    for(int i = 0; i<n; i++){
        scanf("%d",&curr);
        sum+=curr;

        if(sum>maxSum){
            maxSum=sum;
        }
        if(sum<0){
            sum=0;
        }
        
    }
    
    printf("%d\n",maxSum);
    
    return 0;
}
