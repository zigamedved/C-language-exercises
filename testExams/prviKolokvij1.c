
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // dopolnite ...
   int n; 
   scanf("%d",&n);
   int povprecje = 0;
   int povprecje2 = 0;
   int trenutni = 0;
   int indeks = 0;
   
   scanf("%d",&trenutni);
   povprecje += trenutni;
   povprecje2 = povprecje;
   int flag = 1;
   for(int i = 2;i<=n; i++){
        indeks++;
           scanf("%d",&trenutni);
           povprecje += trenutni;
           povprecje2 = povprecje/i;
           if(trenutni>povprecje2){
               continue;
            }else{
                printf("%d",indeks);
                flag=0;
                break;
            }
    }
    if(flag==1){
        printf("%d",n);
        
    }
    return 0;
}
