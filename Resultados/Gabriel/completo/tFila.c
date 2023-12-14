#include <stdio.h>
#include <stdlib.h>
#include "tDocumento.h"
#include "tFila.h"

struct tFila{
    tDocumento** documento;
    int tamanho;
};

tFila *criaFila()
{
    tFila* fila = (tFila*) calloc(1, sizeof(tFila));
    if (fila == NULL)
    {
        printf("Problema de alocacao de memoria no criaFila\n");
        exit(1);
    }
    return fila;
}

void desalocaFila(void* fi)
{
    tFila* f = (tFila*) fi;
    if (f != NULL)
    {
        if (f -> documento != NULL)
        {
            for (int i = 0; i < f -> tamanho; i++)
            {
                if (f -> documento[i] != NULL)
                    desalocaDocumento(f -> documento[i]);
            }
            free(f -> documento);
        }
        free(f);
    }
}

void insereDocumentoFila(void *fi, void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                         func_ptr_imprimeEmArquivo imprimeEmArquivo,
                         func_ptr_desaloca desaloca)
{
    tFila* f = (tFila*) fi;
    f->tamanho++;

    tDocumento** temp = (tDocumento**)realloc(f->documento, f->tamanho * sizeof(tDocumento*));
    
    if (temp == NULL) {
        printf("Problema de alocacao de memoria no insereDocumentoFila\n");
        exit(1);
    }

    f->documento = temp;

    // Create and add the new document
    f->documento[f->tamanho - 1] = criaDocumento(dado, imprimeNaTela, imprimeEmArquivo, desaloca);
}

int quantidadeDocumentosNaFila(void *fi)
{
    tFila* f = (tFila*) fi;
    return f -> tamanho;
}

void imprimeFila(void *fi, char *path)
{
    tFila* f = (tFila*) fi;
    for (int i = 0; i < f -> tamanho; i++)
    {
        imprimeNaTelaDocumento(f -> documento[i]);
        imprimeEmArquivoDocumento(f -> documento[i], path);
    } 
}