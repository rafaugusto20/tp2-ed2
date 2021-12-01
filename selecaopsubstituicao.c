#include <stdio.h>
#include <stdlib.h>
#include "selecaopsubstituicao.h"




//-----------------------------------------------------------------------------------------------------



void heapSort(Heap *heapPropriamenteDito, int n) {
    int i = n / 2, pai, filho;
    Heap temp;

    while(true) {
        if(i > 0) {
            i--;
            temp = heapPropriamenteDito[i];
        }
        else {
            n--;
            if(n <= 0) return;
            temp = heapPropriamenteDito[n];
            heapPropriamenteDito[n] = heapPropriamenteDito[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while(filho < n) {
            //contar transferencia
            if((filho + 1 < n) && (heapPropriamenteDito[filho + 1].marcado > heapPropriamenteDito[filho].marcado))
                filho++;
            //contar transferencia
            if(heapPropriamenteDito[filho].marcado > temp.marcado) {
                heapPropriamenteDito[pai] = heapPropriamenteDito[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }
            else {
                break;
            }
        }
        heapPropriamenteDito[pai] = temp;
    }
}

int main() {
    converter_para_binario(20);
    FILE* texto = fopen("binario", "rb");
    //selecaoPorSubstituicao(texto, 100);
    return 0;
}

void selecaoPorSubstituicao(FILE *arquivo, int quantidadeDeAlunos) {
    Fita fitaDeEntrada[FITAS];
    Fita fitaDeSaida[FITAS];
    Aluno alunos[REGISTROS];
    inicializaFitas(fitaDeEntrada);
    inicializaFitas(fitaDeSaida);
    geraBlocoInicialOrdenado(arquivo, quantidadeDeAlunos, fitaDeEntrada);
}

void geraBlocoInicialOrdenado(FILE *arquivo, int quantidadeDeAlunos, Fita *fita) {
    Heap funcionamentoDoHeap[REGISTROS];
    for (int i = 0; i < REGISTROS; i++) {
        //contar transferencia
        fread(&funcionamentoDoHeap[i].registro, sizeof(Aluno), 1, arquivo);
        funcionamentoDoHeap[i].marcado = funcionamentoDoHeap[i].registro.nota;
    }
    int valorDeRegistrosBase = 0;
    int count = 0;
    while(quantidadeDeAlunos) {
        heapSort(funcionamentoDoHeap, REGISTROS-valorDeRegistrosBase);
        /* if(count < FITAS && fitas[count % FITAS].arquivo == NULL) {
            sprintf(nomeArq, "fita-%d.bin", count + 1);
            fitas[count % FITAS].arquivo = fopen(nomeArq, "w+b");
        }

        else {
            sprintf(nomeArq, "fita-%d.bin", (count % FITAS) + 1);
            fseek(fitas[count % FITAS].arquivo, 0, SEEK_END);
        }

        if(marcaTudo(regHeap, length, reg)) {
            desmarcaTudo(regHeap, length, reg);
            fitas[count % FITAS].qtdBlocos++;
            int* aux = malloc((count / FITAS + 1) * sizeof(int));
            if((count / FITAS + 1) == 1) {
                aux[0] = countReg;
                fitas[count % FITAS].numReg = aux;
            }
            else {
                for(int i = 0; i < count / FITAS; i++)
                    aux[i] = fitas[count % FITAS].numReg[i];
                aux[count / FITAS] = countReg;
                fitas[count % FITAS].numReg = aux;
            }
            count++;
            countReg = 0;
        }
        else {

        } */
    }

}

/* bool marcaTudo(Heap* vetor, int tamanho, int reg) {
    for(int i = 0; i < REG - reg; i++) {
        if(vetor[i].marcado <= tamanho / 2)
            return false;
    }

    return true;
} */

/* void desmarcaTudo(Heap* vetor, int tamanho, int reg) {
    for(int i = 0; i < REG - reg; i++)
        vetor[i].marcado -= tamanho;
} */

void inicializaFitas(Fita* fitaEmQuestao) {
    for(int i = 0; i < FITAS; i++) {
        fitaEmQuestao[i].arquivo = NULL;
        fitaEmQuestao[i].qtdBlocos = 0;
        fitaEmQuestao[i].numReg = NULL;
    }
}

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





