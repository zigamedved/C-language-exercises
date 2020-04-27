#include <stdio.h>

long potenca(long stevilo){
   
    long rezultat=1;
    for(long i = 0; i<stevilo; i++){
        rezultat*=2;
    }
    return rezultat;
}

long logaritem(long long stevilo){
    long rezultat = 0;
    long stevec = 0;
    long vsota=0;
    //printf("Stevilo je: %ld\n",stevilo);
    
    while(stevilo>0){
            long stevka = stevilo%10;
        
            if(stevka == 1){
                vsota=potenca(stevec);
                rezultat+=vsota;
            }
            stevilo=stevilo/10;
            stevec++;
            vsota=0;
    }
    return rezultat;
}

long goku(long cifra){
    
   
    long double c = (long double)cifra;
    long res=0;
    while(c>1){
        c/=2;
        res++;
    }
    return res;
}
void printej(long stevilo){
    if(stevilo==0){
        return;
    }
    if(stevilo>0){
        printej(stevilo/10);
    }
    putchar(stevilo%10+'0');
}

int main(){
    
    long long int cifra=0;
    char ch;
    int flag = 0;
    ch=getchar();
   
    while(ch!='\n'){
        //printf("Trenutna cifra %lld",cifra);
        if(cifra>0){
            flag=1;
        }
        if(flag == 0){
            cifra=0;
        }
        
        cifra*=10;
        cifra+=(ch-'0');
        ch=getchar();
    }
    

    long kua = logaritem(cifra);
    //printf("Stevilo je: %ld\n",kua);
    long lmao = goku(kua);
    
    
    if(lmao==0){
        putchar('0');
    }else
        printej(lmao);
    
    
    
    
    return 0;
}

