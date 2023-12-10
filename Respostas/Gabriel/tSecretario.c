#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tLogin.h"
#include "tSecretario.h"

struct tSecretario{
	tPessoa* dadosSecretario;
	tLogin* login;
	int idLogin;
	int id;
};

tSecretario* criaSecretario()
{
	tSecretario* secretario = (tSecretario*) calloc (1, sizeof(tSecretario));
	secretario -> dadosSecretario = criaPessoa();
	secretario -> login = criaLogin();
	return secretario;
}

void lerSecretario(tSecretario* s)
{
	printf("AAAA");
	lerPessoa(s -> dadosSecretario);
	leLogin(s -> login);
	printf("NIVEL DE ACESSO:\n");
	AtribuiTipoAcesso(s -> login, 1);
}

void defineIdSecretario(tSecretario* s, int id)
{
	s -> id = id;
}

void defineIdLoginSecretario(tSecretario* s, int id)
{
	s -> idLogin = id;
	adicionaIdLogin(s -> login, id);
}

void printSecretario(tSecretario* s)
{
	
}

void escreveBinSecretario()
{

}

void lerBinSecretario()
{

}

char* retornaLoginSecretario(void* secre)
{
	tSecretario* secretario = (tSecretario*) secre;
	return obterLogin(secretario -> login);
}

char* retornaSenhaSecretario(void* secre)
{
	tSecretario* secretario = (tSecretario*) secre;
	return obterSenha(secretario -> login);
}

char* retornaAcessoSecretario(void *secre)
{
	tSecretario* secretario = (tSecretario*) secre;
	return obterAcesso(secretario -> login);
}

char* obtemCPFSecretario(void* secre)
{
	tSecretario* secretario = (tSecretario*) secre;
	return obtemCPFPessoa(secretario -> dadosSecretario);	
}

void adicionaSecretarioSade(void** s, void* adicionar, int qtdSecretarios)
{
    tSecretario** secretarios = (tSecretario**) s;
    tSecretario* secretarioAdd = (tSecretario*) adicionar;
    secretarios = (tSecretario**) realloc(secretarios, sizeof(tSecretario*) * (qtdSecretarios));
    secretarios[qtdSecretarios - 1] = secretarioAdd;
}

void desalocaSecretario(void* sec)
{
	tSecretario* s = (tSecretario*) sec;
	desalocaPessoa(s -> dadosSecretario);
	desalocaLogin(s -> login);
	free(s);
}