#include <stdio.h>
#include <limits.h>

#include "quick_sort.h"

void quick_sort(FILE **ArqLi, int quantidade){

    rewind(*ArqLi);

    FILE *ArqEi = NULL,  *ArqLEs = NULL;
    ArqEi = ArqLEs = *ArqLi;

    if(ArqLEs == NULL){
        printf("Error 2\n");
        return;
    }

    if(ArqEi == NULL){
        printf("Error 3\n");
        return;
    }

    QuicksortExterno(ArqLi, &ArqEi, &ArqLEs, 1, quantidade);

    fflush(*ArqLi);
    fflush(ArqEi);
    fflush(ArqLEs);

    fclose(ArqEi);
    fclose(ArqLEs);

}


void QuicksortExterno(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, int Esq, int Dir){
    int i, j;

    TipoArea Area;

    if((Dir - Esq) < 1){
        return;
    }

    FAVazia(&Area);

    Particao(ArqLi, ArqEi, ArqLEs, Area, Esq, Dir, &i, &j);

    if((i - Esq) < (Dir - j)){
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
    }else{
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, j, Dir);
        QuicksortExterno(ArqLi, ArqEi, ArqLEs, Esq, i);
    }
}

void LeSup(FILE **ArqLEs, Aluno *UltLido, int *Ls, short *OndeLer){
    fseek(*ArqLEs, (*Ls - 1) * sizeof(Aluno), SEEK_SET);
    fread(UltLido, sizeof(Aluno), 1, *ArqLEs);
    (*Ls)--;
    *OndeLer = FALSE;
}

void LeInf(FILE **ArqLi, Aluno *UltLido, int *Li, short *OndeLer){
    fread(UltLido, sizeof(Aluno), 1, *ArqLi);
    (*Li)++;
    *OndeLer = TRUE;
}

void InserirArea(TipoArea *Area, Aluno *UltLido, int *NRArea){
    InsereItem(UltLido, Area);
    *NRArea = ObterNumCelOcupadas(Area);
}

void EscreveMax(FILE **ArqLEs, Aluno R, int *Es){
    fseek(*ArqLEs, (*Es-1) * sizeof(Aluno), SEEK_SET);
    fwrite(&R, sizeof(Aluno), 1, *ArqLEs);
    (*Es)--;
}

void EscreveMin(FILE **ArqEi, Aluno R, int *Ei){
    fwrite(&R, sizeof(Aluno), 1, *ArqEi);
    (*Ei)++;
}

void RetiraMax(TipoArea *Area, Aluno *R, int *NRArea){
    RetiraUltimo(Area, R);
    *NRArea = ObterNumCelOcupadas(Area);
}

void RetiraMin(TipoArea *Area, Aluno *R, int *NRArea){
    RetiraPrimeiro(Area, R);
    *NRArea = ObterNumCelOcupadas(Area);
}

void Particao(FILE **ArqLi, FILE **ArqEi, FILE **ArqLEs, TipoArea Area, int Esq, int Dir, int *i, int *j){
    int Ls = Dir, Es = Dir, Li = Esq, Ei = Esq, NRArea = 0;
    double Linf = INT_MIN, Lsup = INT_MAX;

    short OndeLer = TRUE;
    Aluno UltLido, R;

    fseek(*ArqLi, (Li-1) * sizeof(Aluno), SEEK_SET);
    fseek(*ArqEi, (Ei-1)* sizeof(Aluno), SEEK_SET);

    *i = Esq-1;
    *j = Dir+1;

    while(Ls >= Li){
        if(NRArea < TAMAREA-1){
            if(OndeLer)
            LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
            else LeInf(ArqLi, &UltLido, &Li, &OndeLer);
            InserirArea(&Area, &UltLido, &NRArea);
            continue;
        }

        if(Ls == Es)
        LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
        else if(Li == Ei) LeInf(ArqLi, &UltLido, &Li, &OndeLer);
            else if(OndeLer) LeSup(ArqLEs, &UltLido, &Ls, &OndeLer);
                else LeInf(ArqLi, &UltLido, &Li, &OndeLer);
        
        if(UltLido.nota > Lsup){
            *j = Es;
            EscreveMax(ArqLEs, UltLido, &Es);
            continue;
        }

        if(UltLido.nota < Linf){
            *i = Ei;
            EscreveMin(ArqEi, UltLido, &Ei);
            continue;
        }

        InserirArea(&Area, &UltLido, &NRArea);

        if(Ei-Esq < Dir-Es){
            RetiraMin(&Area, &R, &NRArea);
            EscreveMin(ArqEi, R, &Ei);
            Linf = R.nota;
        }
        else{
            RetiraMax(&Area, &R, &NRArea);
            EscreveMax(ArqLEs, R, &Es);
            Lsup = R.nota;
        }
    }

    while(Ei <= Es){
        RetiraMin(&Area, &R, &NRArea);
        EscreveMin(ArqEi, R, &Ei);
    }
}

void FAVazia(TipoArea *Area){
    for(int i = 0; i < TAMAREA; i++){
        Area->vetor[i].nota = INT_MAX;
    }
    Area->tam = 0;
}

void InsereItem(Aluno *UltLido,TipoArea *Area){
    Area->vetor[Area->tam] = *UltLido;
    Area->tam = Area->tam + 1;

    insert_sort(Area);
}

int ObterNumCelOcupadas(TipoArea *Area){
    return Area->tam;
}

void RetiraUltimo(TipoArea *Area, Aluno *R){
    if(Area->tam == 0){
        printf("ERRO retira ultimo 0\n");
        return;
    }

    *R = Area->vetor[Area->tam - 1];
    Area->vetor[Area->tam - 1].nota = INT_MAX;

    insert_sort(Area);

    Area->tam = Area->tam - 1;
}

void RetiraPrimeiro(TipoArea *Area, Aluno *R){
    if(Area->tam == 0){
        printf("ERRO retira primeiro 0\n");
        return;
    }

    *R= Area->vetor[0];
    Area->vetor[0].nota = INT_MAX;

    insert_sort(Area);

    Area->tam = Area->tam - 1;
}

void insert_sort(TipoArea *area){

    Aluno aux;
    int j, i;
    for(i = 1; i < TAMAREA; i++){
        aux = area->vetor[i];
        j = i-1;

        while((j >= 0) && (aux.nota < area->vetor[j].nota)){
            area->vetor[j+1] = area->vetor[j];
            j--;
        }

        area->vetor[j+1] = aux;
    }
}
