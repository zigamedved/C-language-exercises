#include <stdio.h>

int preveri(int n){
    
    int vsota = 0;
    for(int i = 1;i<=((n/2)+1);i++){
        if(n%i==0){
            vsota+=i;
        }
    }
    return vsota;
}

int main(){
    
    int n,friend;
    scanf("%d",&n);
    
    friend=preveri(n);
    
    if(n==preveri(friend)){
        printf("%d\n",friend);
    }else{
        printf("NIMA\n");
    }
    
    return 0;
}
