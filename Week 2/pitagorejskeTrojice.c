#include <stdio.h>
//Program for calculating pythagorean triples
//Input numbers [1,1000];

int main(){
    
    int m,n,stevec,flag;
    stevec=0;
    flag = 0;
    scanf("%d %d",&m,&n);
    
    
    for(int i = m; i<=n; i++){
        for(int j = 1; j<i; j++){
            if(flag){
                j=n;
                continue;
            }
            for(int k = 1; k<i;k++){
                if(i*i==j*j+k*k){
                    flag=1;
                }
            }
        }
        if(flag){
            stevec++;
            flag=0;
        }
    }
    
    printf("%d\n",stevec);
    
    
    
    return 0;
}
