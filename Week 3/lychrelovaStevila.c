#include <stdio.h>



long palindrom(long n){
    long copy1=n;
    long check=0;
    
    while(copy1>0){
        check*=10;
        check+=(copy1%10);
        copy1/=10;
    }
    return check;
}

long obrat(long n){
    if(n==palindrom(n)){
      return 1;
    }else return 0;
}

int preveri(long stevilo,int ponovitve){
    int stevec = 0;
    
    do{
        stevilo+=palindrom(stevilo);
        stevec++;
        
    }while((stevilo<100000000000000001) && stevec<ponovitve && (obrat(stevilo)!=1) );
    
    if(obrat(stevilo)){
        return 1;
    }
    
    return 0;
}

int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    int stevec = 0;
    
    for(long i = a; i<=b; i++){
            if(preveri(i,n)==1){
                    continue;
            }else
                stevec++;
    }
    printf("%d\n",stevec);
    
    return 0;
}
