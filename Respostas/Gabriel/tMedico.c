#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tMedico.h"
#include "tLogin.h"

struct tMedico{
    tPessoa* dadosDoMedico;
    tLogin* login;
    int id;
    char CRM[12];
};

tMedico* criaMedico()
{
    tMedico* medico = (tMedico*) calloc (1, sizeof(tMedico));
    medico -> dadosDoMedico = criaPessoa();
    medico -> login = criaLogin();
    return medico;
}

void lerMedico(tMedico* m)
{
    lerPessoa(m);
    scanf("%12s", m -> CRM);
}

void escreveBinMedico(tMedico* m, const char* caminho)
{

}

void lerBinMedico(tMedico* m, const char* caminho)
{
    
}

bool comparaCPFMedico(tMedico* m, const char* cpf)
{
    return strcmp(obtemCPFMedico(m), cpf);
}

char* obtemCPFMedico(tMedico* m)
{
    return obtemCPFPessoa(m -> dadosDoMedico);
}

int obtemIdMedico(tMedico* m)
{
    return m -> id;
}

char* obtemNomeMedico(tMedico* m)
{
    return obtemCPFPessoa(m -> dadosDoMedico);
}

char* obtemCRMMedico(tMedico* m)
{
    return m -> CRM;
}

void defineIdMedico(tMedico* m)
{
    scanf("%d", &m -> id);
}

char* retornaLoginMedico(void* me)
{
	tMedico* medico = (tMedico*) me;
	return obterLogin(medico -> login);
}

char* retornaSenhaMedico(void* me)
{
	tMedico* medico = (tMedico*) me;
	return obterSenha(medico -> login);
}

void adicionaMedicoSade(void** m, void* adicionar, int qtdMedicos)
{
    tMedico** medicos = (tMedico**) m;
    tMedico* medicoAdd = (tMedico*) adicionar;
    medicos = (tMedico**) realloc (medicos, sizeof(tMedico*) * (qtdMedicos));
    medicos[qtdMedicos-1] = medicoAdd;
}

void desalocaMedico(void* medico)
{
    tMedico* m = (tMedico*) medico;
    desalocaPessoa(m -> dadosDoMedico);
    free(m);
}
