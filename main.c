#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "suffix.h"

int main(int argc, char **argv){
    FILE* entrada;                                          //Arquivo de entrada para o sistema
    FILE* saida;                                            //Arquivo de saida
    int opt;
    
    //Abre o arquivo de Entrada e o de Saida
    entrada = fopen(argv[2], "r+");
    saida = fopen("saida.txt", "a+");

    //Verifica se o arquivo de Entrada é existente
    if (entrada == NULL) {
        printf("\n\tErro Arquivo de entrada não encontrado\n\n");
        return 0;
    }
    int N;
    fscanf(entrada, "%d", &N);
    
    char text[N];
    char palavra[100];
    fscanf(entrada, "%s", text);
    while (fscanf(entrada, "%s", palavra) != EOF){        
        strcat(text, " ");
        strcat(text, palavra);
    }
    String* texto;
    Suffix** aSuf;
    while ((opt = getopt(argc, argv, "aorcs")) != -1){
        switch (opt) {
            case 'a':
                texto = create_string(text);
                aSuf = create_suf_array(texto, N);
                
                print_suf_array(aSuf, N);
                
                destroy_suf_array(aSuf, N);
                break;
            case 'o':
                texto = create_string(text);
                aSuf = create_suf_array(texto, N);
                
                sort_suf_array(aSuf, N);
                print_suf_array(aSuf, N);
                
                //destroy_suf_array(aSuf, N);
                break;
            case 'r':
                break;
            case 'c':
                break;
            case 's':
                break;
            default:
                break;
        }
    }

    fclose(entrada);
    fclose(saida);
    return EXIT_SUCCESS;
}
