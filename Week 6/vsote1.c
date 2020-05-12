#include <stdio.h>

long memo[402][402];

long vsote(int n,int k){
    //izhodni pogoj
    if(n<=0 || k<=0){
        if(n==0 && k>=0){
            return 1;
        }else
            return 0;
    }
    
    if(memo[n][k]==0){
        long z = vsote(n-k,k);
        long brez = vsote(n,k-1);
        memo[n][k] = z+brez;
        return (z+brez);
    }else
        return memo[n][k];
    
}


int main(){
    
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%ld\n",vsote(n,k));
    
    return 0;
}
