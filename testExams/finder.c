
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    // dopolnite ...
    FILE* vhod = fopen(argv[1],"r");
    
    int vrstica=atoi(argv[2])-1;
    int beseda=atoi(argv[3])-1;
    
    int curr;
    char* result = (char*)malloc(1000*sizeof(char));
    int index=0;
    
    while((curr=fgetc(vhod))!=EOF){
       if(vrstica==0&&beseda==0){
            if(curr==' ' || curr=='\n'){
                result[index]='\0';
                break;
            }
            result[index]=curr;
            index++;
        }
        if(vrstica==0&&beseda>0&&curr==' ')beseda--;
        if(curr=='\n'){
            vrstica--;
        }
    }
    
    for(int i = 0; i<index; i++){
        printf("%c",result[i]);
    }
    printf("\n");
    
    
    return 0;
}
