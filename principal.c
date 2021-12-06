/*Gabriel Catizani Faria Oliveira (20.1.4004)
Lucas Gomes dos Santos (20.1.4108)
Rafael Augusto Freitas Oliveira (20.1.4038)
Robson Novato Lobão (20.1.4018)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "imprime.h"
#include "selecaopsubstituicao.h"
#include "quick_sort.h"

/*
#include "balanceada1.h"
*/

int main (int argc, const char *argv[]) {
    int metodo = atoi(argv[1]);
    long int quantidade = atoi (argv[2]);
    int situ = atoi (argv[3]);
    int argOpc = 0;

    int contLeitura = 0; 
    int contEscrita = 0; 
    int contComp = 0;
    double tProce = 0.0; 
    double tTotal = 0.0;

    clock_t Processamento;
    //clock_t FinalProcessamento;
    //clock_t Pesquisa;
    //clock_t FinalPesquisa;

    //char nome[6];

    if (quantidade <= 0){
        printf ("ERRO: o arquivo deve ter no minimo 1 registro\n");
        exit(1);

    }

    if (argc < 4){
        printf("ERRO: Poucos comandos digitados...\n");
        printf("Os argumentos são: ordena <metodo> <quantidade> <situacao> [-P]\n");
        printf ("OBS: [-P] é opcional\n");
        exit(1);
    }

    if (argc > 5){
        printf("ERRO: Muitos comandos digitados...\n");
        printf("Os argumentos são: ordena <metodo> <quantidade> <situacao> [-P]\n");
        printf ("OBS: [-P] é opcional\n");
        exit(1);
    }

    if (metodo < 1 || metodo > 4){

        printf ("ERRO: Argumento (método) inválido!\n");
        printf ("Metodo deve ser digitado como '1' para intercalação balanceada de varios caminhos com algum metodo de ordenação interna, '2' para intercalação balanceada de varios caminhos utilizando a técnica de seleção por substituição, '3' para Quicksort externo\n");
        exit(1);
    }

    if (situ < 1 || situ > 3){
        printf("ERRO: Argumento (situação) inválido!\n");
        printf("Situação deve ser digitada como '1' para arquivo arquivo ordenado ascendentemente , '2' para arquivo ordenado descendentemente e '3' para arquivo desordenado aleatoriamente pelas notas\n");
        exit(1);

    }

     /*vemos se foi ou nao digitado o argumento opcional. Se sim, ele passa a ser 1 (verdadeiro), para mais na frente
    realizarmos a impressao de todas as chaves do arquivo*/
    if(argc == 6){
        if(strcmp(argv[5],"[-P]") == 0)
            argOpc = 1;
        else{
            printf("ERRO: argumento opcional digitado errado!\n.");
            printf("Maneira correta é [-P]\n");
            exit(1);
        }
    }

    converter_para_binario(quantidade);

    FILE *arqReg = NULL;

    //vê qual arquivo iremos pegar
    switch (situ) {
        case 1:
            if((arqReg = fopen("binarioASC", "rb+")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;
            }
            break;

        case 2: 

            if((arqReg = fopen("binarioDES", "rb+")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;

            }
            break;

        case 3: 
           
            if((arqReg = fopen("binarioALE", "rb+")) == NULL){
                printf ("ERRO na abertura do arquivo \n");
                return 0;
            }
            break;
    }  

    int ordenado = 0;

    //Imprimindo o registro antes da ordenação
    if(argOpc == 1){
        imprimeTUDO(arqReg, ordenado, quantidade);
    }
    

    
    //Identifica qual método de ordenação sera utilizado
    switch (metodo){
        case 1: //Acesso sequencial indexado

            break;

        case 2: //Arvore binaria  
            
            break;

        case 3: //QuickSort Externo
            
            quick_sort(&arqReg, quantidade);

            break; 

    }
    

    ordenado = 1;
    //Imprimindo o registro depois da ordenação
    if(argOpc == 1){
        imprimeTUDO(arqReg, ordenado, quantidade);
    }

    tProce = (double)(Processamento/1000.0);

    tTotal = (tProce)/1000.0;

    imprimirExperimento (contComp, contLeitura, contEscrita, tTotal);

    fclose(arqReg);
    
    return 0;
}



