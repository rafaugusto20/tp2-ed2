#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "imprime.h"

//O robas é muito delicioso e eu como ele todo dia
//Imprime todasa as chaves de pesquisa do arquivo
void imprimeTUDO(FILE *arq, int orde, long int quantidade){
    TipoRegistro reg;

    long int contChave = 1;

    rewind(arq);

    if(orde == 0){
        while(fscanf(arq, "%ld %lf", &reg.nInscri, &reg.nota) != EOF){

            fgets(reg.estado, 2, arq);
            fgets(reg.cidade, 50, arq);
            fgets(reg.curso, 30, arq);
            fgets("\n", 1, arq);

            if(contChave == quantidade){
                break;
            }

            printf("\nALUNO %d\n", contChave);
            printf("\t Numero de Inscrição: %ld\n", reg.nInscri);
            printf("\t Nota: %.1lf\n", reg.nota);
            printf("\t Estado: %s\n", reg.estado);
            printf("\t Cidade: %s\n", reg.cidade);
            printf("\t Curso: %s\n", reg.curso);
            printf("\n--------------\n");
            contChave++;
        }
    }

    else {
        while(fscanf(&reg, "%ld %lf", &reg.nInscri, &reg.nota) != EOF ){

            fgets(reg.estado, 2, arq);
            fgets(reg.cidade, 50, arq);
            fgets(reg.curso, 30, arq);
            fgets("\n", 1, arq);

            if(contChave == quantidade){
                break;
            }

            printf("\n%dº Lugar\n", contChave);
            printf("\t Numero de Inscrição: %ld\n", reg.nInscri);
            printf("\t Nota: %.1lf\n", reg.nota);
            printf("\t Estado: %s\n", reg.estado);
            printf("\t Cidade: %s\n", reg.cidade);
            printf("\t Curso: %s\n", reg.curso);
            printf("\n--------------\n");
            contChave++;
        }

    }

    rewind(arq);
}

//Imprime os valores dos contadores de transferencias e o tempo de execução tanto da pesquisa quanto do pre-processamento
//do metodo utilizado
void imprimirExperimento(int contComp, int contLeitura, int contEscrita, double tTotal){
    printf("EXPERIMENTO\n");
    printf("Transferencias de leitura: %d\n", contLeitura);
    printf("Transferencias de escrita: %d\n", contEscrita);
    printf("Comparações entre chaves: %d\n", contComp);
    printf("Tempo total: %.3lf s\n", tTotal);
}

