#include <stdio.h>


int main(){
    
    int a,b;
    scanf("%d %d",&a,&b);
    
    int odgovor;
    int rez;
    
    do{
        rez=(a+b)/2;
        
        //printf("Spodnja meja %d, zgornja meja %d\n",a,b);
        //printf("Povprecje %d\n",rez);
        
        scanf("%d",&odgovor);
        if(odgovor==1){
            a=rez+1;
        }else if(odgovor==-1){
            b=rez-1;
        }
        
    }while(odgovor!=0);
    
    if(b==a){
        printf("%d\n",rez);
    }else if(a<b){
        printf("%d %d\n",a,b);
    }else{
        printf("PROTISLOVJE\n");
    }
    
    return 0;
}
