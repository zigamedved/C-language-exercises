Vozlisce* prepisi(int* t){
    if(!t)return NULL;

    Vozlisce* zacetek = (Vozlisce*)malloc(sizeof(Vozlisce));
    Vozlisce* rezultat = zacetek;

    int indeks=0;
    while(t[indeks]!=0){
        zacetek->element=t[indeks];
        indeks++;
        Vozlisce* next = (Vozlisce*)malloc(sizeof(Vozlisce));
        zacetek->naslednje=next;
        zacetek=zacetek->naslednje;
    }
    zacetek=NULL;

    return rezultat;
}