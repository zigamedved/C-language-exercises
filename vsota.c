 
#include <stdio.h>

int main(){
    
    char a,b,c;
    int res;
    char d;
    
    a = getchar()-'0';
    b = getchar();
    c = getchar()-'0';
    
    //a = (int)a;
    //c = (int)c;
    d = a+c;
    d = d%10;
   
   putchar(d+'0');
    
    return 0;
}
