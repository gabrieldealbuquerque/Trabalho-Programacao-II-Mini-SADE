#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
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

size_t tamanhoMedico(tMedico* m)
{
    return sizeof(*m);
}

void lerMedico(tMedico* m)
{
    lerPessoa(m -> dadosDoMedico);
    printf("CRM:\n");
    scanf("%12s", m -> CRM);
    leLogin(m -> login);
    AtribuiTipoAcesso(m -> login, 0);
}

tMedico* CriaMedicoLeitura()
{
    tMedico* medico = (tMedico*) calloc (1, sizeof(tMedico));
    return medico;  
}

tMedico* criaMedicoVazio()
{
    tMedico* medico = (tMedico*) calloc (1, sizeof(tMedico));
    medico -> dadosDoMedico = criaPessoa();
    medico -> login = criaLogin();
    return medico;
}

void escreveBinMedico(tMedico* medico, FILE* arquivo)
{
    fwrite(medico, sizeof(tMedico), 1, arquivo);

    escreveBinPessoa(medico->dadosDoMedico, arquivo);

    salvar_login_em_binario(medico->login, arquivo);
}

void lerBinMedico(tMedico* medico, FILE* arquivo)
{
    fread(medico, sizeof(tMedico), 1, arquivo);
    medico -> dadosDoMedico = lerBinPessoa(arquivo);

     medico->login = criaLogin();
     
    ler_login_de_binario(medico->login, arquivo);
}

bool comparaCPFMedico(tMedico* m, const char* cpf)
{
    return strcmp(obtemCPFMedico(m), cpf);
}

char* obtemCPFMedico(tMedico* m)
{
    return obtemCPFPessoa(m -> dadosDoMedico);
}

bool comparaCRMMedico(tMedico*m, const char* crm)
{
    return strcmp(obtemCPFMedico(m), crm);
}

int obtemIdMedico(tMedico* m)
{
    return m -> id;
}

char* obtemNomeMedico(tMedico* m)
{
    return obtemNomePessoa(m -> dadosDoMedico);
}

char* obtemCRMMedico(tMedico* m)
{
    return m -> CRM;
}

int mesmoIdLoginMedico(tMedico* m, int id)
{
    return m -> id == id;
}

int obtemIdLoginMedico(tMedico* m)
{
    return m -> idLogin;
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

int calculaidadeMedico(tMedico* medico)
{
    return calculaIdadePessoa(medico -> dadosDoMedico);
}

int obtemGeneroMedico(tMedico* medico)
{
	return comparaGeneroPessoa(medico -> dadosDoMedico);
}

void adicionaMedicoSade(void** m, void* adicionar, int qtdMedicos)
{
    tMedico** medicos = (tMedico**) m;
    tMedico* medicoAdd = (tMedico*) adicionar;
    medicos = (tMedico**) realloc (medicos, sizeof(tMedico*) * (qtdMedicos));
    medicos[qtdMedicos-1] = medicoAdd;
}

void atribuiNomeMedico(tMedico* medico, const char* nome)
{
    atribuiNome(medico -> dadosDoMedico, nome);
}

void atribuiCRMMedico(tMedico* medico, const char* crm)
{
    strcpy(medico -> CRM, crm);
}


void desalocaMedico(void* medico)
{
    tMedico* m = (tMedico*) medico;
    if (m != NULL)
    {
        if (m -> dadosDoMedico != NULL)
            desalocaPessoa(m -> dadosDoMedico);
        if (m -> login != NULL)
            desalocaLogin(m -> login);
        free(m);
    }
}
