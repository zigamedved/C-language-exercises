#include <stdio.h>

void presledki(int n){
    if(n==0){
        return;
    }
    printf(" ");
    presledki(n-1);
    
}

void zvezdice(int stevec,int stZvezd){
        if(stevec>=(2*stZvezd-1)){
            return;
        }
        printf("*");
        zvezdice(stevec+1,stZvezd);
}

void ponovitve(int n,int k){
    if(n==0)
        return;
    presledki(n-1);
    zvezdice(0,k+1);
    printf("\n");
    ponovitve(n-1,k+1);
    
}

int main(){
    int n;
    scanf("%d",&n);
    ponovitve(n,0);
    
    return 0;
}

 
 
