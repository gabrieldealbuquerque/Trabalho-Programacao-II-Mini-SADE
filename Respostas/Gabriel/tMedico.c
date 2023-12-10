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
    int idLogin;
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
    lerPessoa(m -> dadosDoMedico);
    printf("CRM:\n");
    scanf("%12s", m -> CRM);
    leLogin(m -> login);
    AtribuiTipoAcesso(m -> login, 0);
}

tMedico* criaMedicoVazio()
{
    tMedico* medico = (tMedico*) calloc (1, sizeof(tMedico));
    medico -> dadosDoMedico = criaPessoa();
    return medico;
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

int mesmoIdLoginMedico(tMedico* m, int id)
{
    return m -> id == id;
}

void defineIdMedico(tMedico* m, int id)
{
    m -> id = id;
}

void defineIdLoginMedico(tMedico* m, int id)
{
    m -> idLogin = id;
    adicionaIdLogin(m -> login, id);
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

char* retornaAcessoMedico(void *me)
{
	tMedico* medico = (tMedico*) me;
	return obterAcesso(medico -> login);
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
