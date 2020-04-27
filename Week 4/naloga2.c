#include <stdio.h>


int main(){

    long num,target;
    scanf("%ld %ld",&num,&target);
    
    long table[num];
    
    for(long i = 0; i<num; i++){
        scanf("%ld",&table[i]);
    }
    
    long res=0;
    long count=0;
    long num2;
    long prev=0;
    
    for(long i = 0; i<num; i++){
        num2=table[i];
        
        if(prev!=num2){
            count=0;
                for(long j = i+1; j<num; j++){
                    if(num2+table[j]==target){
                            count++;
                    }
                }
                res+=count;
        }else if(prev==num2){
            if(prev+num2==target){
                count--;
                res+=count;
            }else{
                res+=count;
            }
            
        }  
        
        prev=num2;
    }
    
    printf("%ld",res);
    
    return 0;
}

