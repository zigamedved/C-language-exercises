#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    scanf("%d",&n);
    //int* tabela = (int*)malloc(n*sizeof(int));
    int* tabela = (int*)calloc(n,sizeof(int));
    int iter;
    
    for(int i = 0; i<n; i++){
        
        scanf("%d",&iter);
        tabela[iter]++;
    }
    
    for(int i = 0; i<n; i++){
        if(tabela[i]>=n){
            printf("NE\n");
            exit(0);
        }
        if(tabela[i]!=1){
            printf("NE\n");
            break;
        }else if(i==n-1){
            printf("DA\n");
        }
    }
    
    free(tabela);
    
    return 0;
}
