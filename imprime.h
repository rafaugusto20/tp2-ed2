# ifndef impri_h
# define impri_h

#include <stdio.h>
#include <time.h>

typedef double TChave;

typedef struct{
    FILE* arquivo;
    int qtdBlocos;
    int* numReg;
} Fita;

typedef struct Aluno{
    long int numero;
    float nota;
    char estado[2];
    char cidade[50];
    char curso[30];
} Aluno;

void converter_para_binario(int quantidade);

void imprimeRegistro(Aluno registro);

void imprimeTUDO (FILE *arg, int orde, long int quantidade);

void imprimirExperimento(int contComp, int contLeitura, int contEscrita, double tTotal);

#endif