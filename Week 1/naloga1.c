#include <stdio.h>



void printej(int a){
    if(a==0){
        return;
    }
    
    if(a>0){
        printej(a/10);
    }
        putchar((a%10)+'0');
}

int main(){
    //int i = 0;
    int prvoStevilo=0;
    char znak='+';
    char ch = getchar();
    
    if((ch=='-')){
        znak='-';
        
    }else{
        prvoStevilo=prvoStevilo*10;
        prvoStevilo+=(ch-'0');
    }
    
    while((ch=getchar())!=' '){
        prvoStevilo=prvoStevilo*10;
        prvoStevilo+=(ch-'0');
    }
    
    //putchar(znak);
    //printej(prvoStevilo);
    
    int drugoStevilo = 0;
    char znak2='+';
    ch = getchar();
    
    if(ch=='-'){
        znak2='-';
    }else{
        drugoStevilo=drugoStevilo*10;
        drugoStevilo+=(ch-'0');
        
    }
    ch = getchar();
    while(ch!='\n'){
        drugoStevilo=drugoStevilo*10;
        drugoStevilo+=ch-'0';
        ch=getchar();
        
    }
    
    int rezultat=0;
    
    if(znak=='-'){
        rezultat-=prvoStevilo;
    }else
        rezultat+=prvoStevilo;
    if(znak2=='-'){
        rezultat-=drugoStevilo;
    }else
        rezultat+=drugoStevilo;
    
    if(rezultat<0){
        putchar('-');
        rezultat=rezultat*-1;
    }
    if(rezultat==0){
        char b = '0';
        putchar(b);
    }else
        printej(rezultat);
    
    return 0;
}
