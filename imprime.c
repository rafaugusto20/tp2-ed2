#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "imprime.h"

void converter_para_binario(int quantidade){
    Aluno reg;
    char nome[] = "PROVAO.TXT";
    char nome_saida[] = "binario";

    FILE *arquivo_texto = NULL;
    arquivo_texto = fopen(nome, "r");
    if(arquivo_texto == NULL){
        printf("ERRO 1\n");
        exit(1);
    }

    FILE *saida = NULL;
    saida = fopen(nome_saida, "wb");
    if(saida == NULL){
        printf("ERRO 2\n");
        exit(1);
    }

    for(int i = 0; i < quantidade; i++){
        
        fscanf(arquivo_texto, "%ld %f", &reg.numero, &reg.nota);
        fgets(reg.estado, 2, arquivo_texto);
        fgets(reg.cidade, 50, arquivo_texto);
        fgets(reg.curso, 30, arquivo_texto);

        fwrite(&reg, sizeof(Aluno), 1, saida);
    }

    fclose(arquivo_texto);
    fclose(saida);

}



void imprimeTUDO(FILE *arq, int orde, long int quantidade){
    Aluno reg;

    long int contChave = 1;

    rewind(arq);

    if(orde == 0){
        while(fread(&reg, sizeof (Aluno), 1, arq) == 1){

            printf("\nALUNO %ld\n", contChave);
            printf("\t Numero de Inscrição: %ld\n", reg.numero);
            printf("\t Nota: %.1lf\n", reg.nota);
            printf("\t Estado: %s\n", reg.estado);
            printf("\t Cidade: %s\n", reg.cidade);
            printf("\t Curso: %s\n", reg.curso);
            printf("\n--------------\n");
            contChave++;
        }
    }

    else {
        while(fread(&reg, sizeof (Aluno), 1, arq) == 1){

            printf("\n%ldº Lugar\n", contChave);
            printf("\t Numero de Inscrição: %ld\n", reg.numero);
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

