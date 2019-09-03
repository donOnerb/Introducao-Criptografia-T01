#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char ordem_incidencia[] = "aeosrdnitmulcvpgqbfhjxzkyw";

typedef struct estatistica{
    char letra;
    int quantidade;
}Estatistica;

char* ler_entrada();
void faz_estatistica(char *entrada, Estatistica* estatistica);
void printa_estatistica(Estatistica *estatistica);
int cmp(const void *value0, const void *value1);
char* troca_carecteres_de_entrada(char *entrada, Estatistica *estatistica);
char* troca_carecter_de_entrada(char *entrada, char trocaA, char trocaB);

void main(){
    char *entrada, *saida, trocaA, trocaB;
    Estatistica estatistica[26];

    entrada = ler_entrada();
    faz_estatistica(entrada, estatistica);
    printa_estatistica(estatistica);
    saida = troca_carecteres_de_entrada(entrada, estatistica);
    scanf("\n%c%c", &trocaA, &trocaB);
    while(trocaA != '#'){
        saida = troca_carecter_de_entrada(saida, trocaA, trocaB);
        scanf("\n%c%c", &trocaA, &trocaB);
    }
    
}

char* ler_entrada() {
    char carecterAux;
    char* entrada = (char *) malloc(5 * sizeof(char));
    int i = 0;
    carecterAux = getchar();
    while(carecterAux != '#'){
        entrada[i] = carecterAux;
        i++;
        if( i % 5 == 0) {
            entrada = (char *) realloc(entrada, (i+5) * sizeof(char));
        }
        carecterAux = getchar();
    }
    entrada[i] = '#';
    if( i % 5 == 0) {
            entrada = (char *) realloc(entrada, (i+1) * sizeof(char));
    }
    entrada[i+1] = '\0';
    return entrada;
    
}

void faz_estatistica(char* entrada, Estatistica* estatistica){
    int i;
    for( i = 0; i < 26; i++){
        estatistica[i].letra = 'a' + i;
        estatistica[i].quantidade = 0;
    }
    
    i = 0;
    while(entrada[i] != '#') {
        estatistica[entrada[i] - 'a'].quantidade++;
        i++;
    }
}

void printa_estatistica(Estatistica* estatistica){
    int i;
    printf("\nAlfabética\n");
    for(i = 0; i < 26; i++){
        printf("%c %d\n", estatistica[i].letra, estatistica[i].quantidade);
    }

    qsort(estatistica, 26, sizeof(Estatistica), cmp);
    printf("\nOrdernada\n");
    for(i = 0; i < 26; i++){
        printf("%c %d\n", estatistica[i].letra, estatistica[i].quantidade);
    }
}

char* troca_carecteres_de_entrada(char *entrada, Estatistica *estatistica){
    int len = strlen(entrada);
    char *saida = (char*) malloc(sizeof(char) * len);
    int i, j;
    for(i = 0; i < 26; i++) {
        for(j =0; j < len; j++) {
            if(entrada[j] == estatistica[i].letra)
                saida[j] = ordem_incidencia[i];
        }
    }
    printf("%s\n", saida);
    return saida;
}

char* troca_carecter_de_entrada(char *entrada, char trocaA, char trocaB) {
    int j, len = strlen(entrada);
    char *saida = (char*) malloc(sizeof(char) * len);
    for(j =0; j < len; j++) {
        if(entrada[j] == trocaA)
            saida[j] = trocaB;
        else if(entrada[j] == trocaB)
            saida[j] = trocaA;
        else 
            saida[j] = entrada[j];
    }
    printf("%s\n", saida);
    return saida;
}

int cmp(const void *value0, const void *value1) {
    if((*(Estatistica*) value0).quantidade > (*(Estatistica*) value1).quantidade) {
        return -1;
    } else if((*(Estatistica*) value0).quantidade < (*(Estatistica*) value1).quantidade) {
        return 1;
    }else {
        return 0;
    }
}


