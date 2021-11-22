# ifndef impri_h
# define impri_h

#include <stdio.h>
#include <time.h>

typedef double TChave;

typedef struct TipoRegistro{
    long int nInscri;
    TChave nota; //double
    char estado[2];
    char cidade[50];
    char curso[30];
} TipoRegistro;

void imprimeRegistro(TipoRegistro registro);

void imprimeTUDO (FILE *arg, int orde, long int quantidade);

void imprimirExperimento(int contComp, int contLeitura, int contEscrita, double tTotal);

#endif