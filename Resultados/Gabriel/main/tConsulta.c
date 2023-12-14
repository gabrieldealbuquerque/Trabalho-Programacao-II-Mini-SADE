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
    tBiopsia* biopsia;
    tEncaminhamento* encaminhamento;
    int qtdbiopsias;
    int qtdLesoes;
    int medicoVazio;
};

tConsulta* criaConsulta()
{
    tConsulta* consulta = (tConsulta*)calloc(1, sizeof(tConsulta));
    consulta -> qtdLesoes = 0;
    consulta -> qtdbiopsias = 0;
    if (consulta == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed for tConsulta.\n");
        exit(1);  // Or return NULL, depending on your error-handling strategy
    }
    return consulta;
}

void ConsultaSemMedico(tConsulta* consulta)
{
    consulta -> medico = criaMedicoVazio();
    consulta -> medicoVazio = 1;
}

void atribuiMedicoConsulta(tConsulta* consulta, tMedico* medico)
{
    consulta -> medico = medico;
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

void salvar_consulta_em_binario(tConsulta* consulta, FILE* arquivo) {
    fwrite(consulta, sizeof(tConsulta),1, arquivo);
    fwrite(&consulta -> qtdbiopsias, sizeof(int), 1, arquivo);
    fwrite(&consulta -> qtdLesoes, sizeof(int), 1, arquivo);
    if (!consulta -> medicoVazio)
    escreveBinMedico(consulta -> medico, arquivo);
    if (consulta -> qtdbiopsias == 0)
    {
        if (consulta->qtdLesoes > 0)
        {
            for (int i = 0; i < consulta->qtdLesoes; ++i) {
                escreveBinLesao(consulta->lesoes[i], arquivo);
            }
            
        }
    }
}

// Função para ler uma consulta de binário
void ler_consulta_de_binario(tConsulta* consulta, FILE* arquivo) {
    fread(consulta, sizeof(tConsulta), 1, arquivo);
    fread(&consulta->qtdbiopsias, sizeof(int), 1, arquivo);
    fread(&consulta->qtdLesoes, sizeof(int), 1, arquivo);
    consulta -> medico = criaMedico();
    printf("bbbbbbbbb");
    if (!consulta -> medicoVazio)
        lerBinMedico(consulta -> medico, arquivo);
    
     printf("AAAAAA");
    if (consulta -> qtdbiopsias == 0)
    {
        if (consulta->qtdLesoes > 0)
        {
            consulta->lesoes = (tLesao**)malloc(consulta->qtdLesoes * sizeof(tLesao*));
            printf("AAAAAA");
            for (int i = 0; i < consulta->qtdLesoes; ++i) {
                consulta -> lesoes[i] = criaLesao();
                lerBinLesao(consulta->lesoes[i], arquivo);
            }
        }
    }
    printf("AAAAAA");
}

void adicionarLesaoConsulta(tConsulta* c)
{
    c -> qtdLesoes++;
    c -> lesoes = (tLesao**) realloc(c -> lesoes, c -> qtdLesoes * sizeof(tLesao*));
    c -> lesoes[c -> qtdLesoes-1] = criaLesao();
    lerLesao(c -> lesoes[c -> qtdLesoes-1]);
    defineIdLesao(c -> lesoes[c -> qtdLesoes-1], c -> qtdLesoes);
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
    int dia = 0,mes = 0,ano = 0;
    sscanf(obtemDataConsulta(c), "%d/%d/%d", &dia, &mes, &ano);
    sprintf(obtemDataConsulta(c), "%d/%02d/%d", dia,mes,ano);
    c -> receita = criaReceita(nomePaciente, tipoUso, nomeMedicamento, tipoMedicamento, instrucoes, qtd, obtemNomeMedico(medico), obtemCRMMedico(medico), obtemDataConsulta(c));
}

int tratarBiopsia(tConsulta* consulta, char* nome, char* cpf)
{  
    int cirurgia = 0;
    if (consulta -> qtdLesoes > 0)
    {
        for (int i = 0; i < consulta -> qtdLesoes; i++)
        {
            if (obtemCirurgiaLesao(retornaLesoes(consulta)[i]))
            {
                cirurgia++;
            }
        }
    }
    if(cirurgia)
    {
        consulta -> qtdbiopsias = consulta -> qtdLesoes;
        consulta -> biopsia = criaBiopsia();
        atribuiValoresBiopsia(consulta -> biopsia, nome, cpf, consulta -> qtdLesoes, 
        consulta -> lesoes, obtemNomeMedico(consulta -> medico), obtemCRMMedico(consulta -> medico), obtemDataConsulta(consulta));
        imprimeNaTelaBiopsia(consulta -> biopsia);
        return 1;
    }
    else
    {
        printf("Sem lesoes para gerar biopsia.\n");
    }
    return 0;
}

void tratarEncaminhamento(tConsulta* consulta, char* nome, char* cpf)
{
    consulta -> encaminhamento = criaEncaminhamento(nome, cpf, obtemNomeMedico(consulta -> medico), obtemCRMMedico(consulta -> medico), obtemDataConsulta(consulta));
}

tReceita* retornaReceita(tConsulta* c)
{
    return c -> receita;
}

tBiopsia* retornaBiopsia(tConsulta* c)
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

tLesao** retornaLesoes(tConsulta* c)
{
    return c -> lesoes;
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
    if (c != NULL)
    {
        if (c->medico != NULL)
        {
            desalocaMedico(c->medico);
        }
        if (c -> lesoes != NULL && c -> biopsia == NULL)
        {
            for(int i = 0; i < c -> qtdLesoes; i++)
            {
                desalocaLesao(c -> lesoes[i]);
            }
            free(c -> lesoes);
        }
        free(c);
    }
}