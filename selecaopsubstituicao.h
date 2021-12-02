#ifndef selecaosubstituicao_H
#define selecaosubstituicao_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "imprime.h"

#define REGISTROS 20
#define FITAS 20

typedef struct {
    Aluno registro;
    double marcado;
} Heap;


void selecaoPorSubstituicao(FILE *arquivo, int quantidadeDeAlunos);
void inicializaFitas(Fita* fitaEmQuestao);
void heapSort(Heap *heapPropriamenteDito, int n);
void geraBlocoInicialOrdenado(FILE *arquivo, int quantidadeDeAlunos, Fita *fita);
void converter_para_binario(int quantidade);

#endif