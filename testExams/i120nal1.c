void obrni(FILE *vhod,FILE* izhod){
    char** tabela=(char**)malloc(1000*sizeof(char*));
    
    for(int i = 0; i<1000;i++){
        tabela[i]=(char*)malloc(1000*sizeof(char));
    }

    char* vrstica = (char*)malloc(1000*sizeof(char));

    int trenuten;
    int indeks=0;
    int poved=0;

    while((trenuten=fgetc(vhod))!=EOF){
        if(trenuten=='\n'){
            vrstica[indeks]='\0';
            strcpy(tabela[poved],vrstica);
            vrstica=(char*)malloc(1000*sizeof(char));
            poved++;
            indeks=0;
            continue;
        }
        
        vrstica[indeks]=trenuten;
        indeks++;
    }
    free(vrstica);

    for(int i = poved-1; i>=0; i--){
        fprintf(izhod,"%s\n",tabela[i]);
        free(tabela[i]);
    }

    free(tabela);
    
}