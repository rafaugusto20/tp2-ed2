#ifndef quick_sort_H
#define quick_sort_H

#include <stdio.h>
#include <stdlib.h>
#include "imprime.h"

#define TAMAREA 20
#define FALSE 0
#define TRUE 1

typedef struct{
    int tam;
    Aluno vetor[TAMAREA];
}TipoArea;

void quick_sort(FILE **ArqLi, int quantidade);

void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir);

void LeSup(FILE **ArqLEs, Aluno *UltLido, int *Ls, short *OndeLer);

void LeInf(FILE **ArqLi, Aluno *UltLido, int *Li, short *OndeLer);

void InserirArea(TipoArea *Area, Aluno *UltLido, int *NRArea);

void EscreveMax(FILE **ArqLEs, Aluno R, int *Es);

void EscreveMin(FILE **ArqEi, Aluno R, int *Ei);

void RetiraMax(TipoArea *Area, Aluno *R, int *NRArea);

void RetiraMin(TipoArea *Area, Aluno *R, int *NRArea);

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j);

void insert_sort(TipoArea *area);

void FAVazia(TipoArea *Area);

void InsereItem(Aluno *UltLido,TipoArea *Area);

int ObterNumCelOcupadas(TipoArea *Area);

void RetiraUltimo(TipoArea *Area, Aluno *R);

void RetiraPrimeiro(TipoArea *Area, Aluno *R);

#endif