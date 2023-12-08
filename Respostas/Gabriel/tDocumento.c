#include <stdio.h>
#include <stdlib.h>
#include "tDocumento.h"

struct tDocumento
{
    void *dado;
    func_ptr_imprimeNaTela imprimeNaTela;
    func_ptr_imprimeEmArquivo imprimeEmArquivo;
    func_ptr_desaloca desaloca;
};

tDocumento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                          func_ptr_imprimeEmArquivo imprimeEmArquivo,
                          func_ptr_desaloca desaloca)
{
    tDocumento *novoDocumento = (tDocumento *)malloc(sizeof(tDocumento));
    if (novoDocumento == NULL)
    {
        printf("Falha de alocacao de memoria no criaDocumento\n");
        exit(1);
    }
        novoDocumento->dado = dado;
        novoDocumento->imprimeNaTela = imprimeNaTela;
        novoDocumento->imprimeEmArquivo = imprimeEmArquivo;
        novoDocumento->desaloca = desaloca;

    return novoDocumento;
}

void desalocaDocumento(void *d)
{
    tDocumento* doc = (tDocumento*) d;
    if (doc != NULL)
    {
        if (doc->desaloca != NULL)
        {
            doc->desaloca(doc->dado);
        }

        free(doc);
    }
    else
    {
        printf("Documento está sendo passado como NULL pro desalocaDocumento\n");
        exit(1);
    }
}

void imprimeNaTelaDocumento(void *d)
{
    tDocumento* doc = (tDocumento*) d;
    if (doc != NULL && doc->imprimeNaTela != NULL)
    {
        doc->imprimeNaTela(doc->dado);
    }
    else
    {
        printf("Documento está sendo passado como NULL pro imprimeNaTelaDocumento\n");
        exit(1);
    }
}

void imprimeEmArquivoDocumento(void *d, char *path)
{
    tDocumento* doc = (tDocumento*) d;
    if (doc != NULL && doc->imprimeEmArquivo != NULL)
    {
        doc->imprimeEmArquivo(doc->dado, path);
    }
    else
    {
        printf("Documento está sendo passado como NULL pro imprimeEmArquivoDocumento\n");
        exit(1);
    }
}