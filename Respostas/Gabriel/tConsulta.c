#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"
#include "tEncaminhamento.h"
#include "tConsulta.h"
#include "tSistema.h"
#include "tPaciente.h"

struct tConsulta{
    int id;
    char data[20];
    tMedico* medico;
    int diabetes;
    int fumante;
    int alergia;
    int historicoCancer;
    char pele[3];
    void* receita;
    tLesao** lesoes;
    tBiopsia** biopsia;
    tEncaminhamento* encaminhamento;
    int qtdLesoes;
};

tConsulta* criaConsulta()
{
    tConsulta* consulta = (tConsulta*)malloc(sizeof(tConsulta));

    if (consulta == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed for tConsulta.\n");
        exit(1);  // Or return NULL, depending on your error-handling strategy
    }

    consulta->qtdLesoes = 0;
    return consulta;
}

void ConsultaSemMedico(tConsulta* consulta)
{
    consulta -> medico = criaMedicoVazio();
}



void leConsulta(tConsulta* c)
{
    printf("DATA DA CONSULTA:\n");
    scanf("%19s", c -> data);
    printf("POSSUI DIABETES:\n");
    scanf("%d", &c -> diabetes);
    printf("FUMANTE:\n");
    scanf("%d", &c -> fumante);
    printf("ALERGIA A MEDICAMENTO:\n");
    scanf("%d", &c -> alergia);
    printf("HISTORICO DE CANCER:\n");
    scanf("%d", &c -> historicoCancer);
    printf("TIPO DE PELE:\n");
    scanf("%2s", c -> pele);
}

void printConsulta(tConsulta* c)
{

}

void escreveBinConsulta(tConsulta* c)
{

}

void lerBinConsulta(tConsulta* c)
{

}

void adicionarLesaoConsulta(tConsulta* c)
{
    c -> qtdLesoes++;
    c -> lesoes = (tLesao**) realloc(c -> lesoes, c -> qtdLesoes * sizeof(tLesao*));
    c -> lesoes[c -> qtdLesoes-1] = criaLesao();
    lerLesao(c -> lesoes[c -> qtdLesoes-1]);
}

int obtemIdConsulta(tConsulta* c)
{
    return c -> id;
}

void defineIdConsulta(tConsulta* c, int id)
{
    c -> id = id;
}

int obtemQtdAtualLesaoConsulta(tConsulta* c)
{  
    return c -> qtdLesoes;
}

/*int obtemIdLesoesConsulta(tConsulta* c)
{

}*/

void tratarReceita(char* nomePaciente, tConsulta*c, void* m)
{
    tMedico* medico = (tMedico*) m;
    eTipoUso tipoUso;
    char tipo[10];
    printf("TIPO DE USO:\n");
    scanf("%s", tipo);
    if (!strcmp(tipo, "ORAL"))
    {
        tipoUso = ORAL;
    }
    if (!strcmp(tipo, "TOPICO"))
    {
        tipoUso = TOPICO;
    }
    char nomeMedicamento[50];
    char tipoMedicamento[50];
    int qtd;
    char instrucoes[300];
    printf("DIGITE O NOME DO MEDICAMENTO:\n");
    scanf(" %49[^\n]", nomeMedicamento);
    printf("TIPO DO MEDICAMENTO:\n");
    scanf(" %49[^\n]", tipoMedicamento);
    printf("QUANTIDADE:\n");
    scanf("%d", &qtd);
    printf("INSTRUCOES DE USO:\n");
    scanf(" %299[^\n]", instrucoes);
    c -> receita = criaReceita(nomePaciente, tipoUso, nomeMedicamento, tipoMedicamento, instrucoes, qtd, obtemNomeMedico(medico), obtemCRMMedico(medico), obtemDataConsulta(c));
}

void tratarBiopsia(tConsulta* consulta, char* nome, char* cpf)
{  
    consulta -> biopsia = (tBiopsia**) realloc (consulta -> biopsia, sizeof(tBiopsia*) * consulta -> qtdLesoes);
    for (int i = 0; i < consulta -> qtdLesoes; i++)
    {
        consulta -> biopsia[i] = criaBiopsia(nome, cpf, obtemRotuloLesao(consulta -> lesoes[i]), 
        obtemDiagnosticoLesao(consulta -> lesoes[i]), obtemRegiaoLesao(consulta -> lesoes[i]), obtemTamanhoLesao(consulta -> lesoes[i]),
        obtemNomeMedico(consulta -> medico), obtemCRMMedico(consulta -> medico), obtemDataConsulta(consulta));
    }
}

void tratarEncaminhamento(tConsulta* consulta, char* nome, char* cpf)
{
    consulta -> encaminhamento = criaEncaminhamento(nome, cpf, obtemNomeMedico(consulta -> medico), obtemCRMMedico(consulta -> medico), obtemDataConsulta(consulta));
}

tReceita* retornaReceita(tConsulta* c)
{
    return c -> receita;
}

tBiopsia** retornaBiopsia(tConsulta* c)
{
    return c -> biopsia;
}

tMedico* retornaMedico(tConsulta* c)
{
    return c -> medico;
}

tEncaminhamento* retornaEncaminhamento(tConsulta* c)
{
    return c -> encaminhamento;
}

char* obtemDataConsulta(tConsulta* c)
{
    return c -> data;
}

void defineMedicoConsulta(tConsulta* c, void* m)
{
    tMedico* medico = (tMedico*) m;
    c -> medico = medico;
}

void desalocaConsulta(tConsulta* c)
{
    desalocaMedico(c -> medico);
    desalocaReceita(c -> receita);
    for (int i = 0; i < c -> qtdLesoes; i++)
    {
        desalocaLesao(c -> lesoes[i]);
    }
    free(c -> lesoes);
    free(c);
}