#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tLogin.h"
#include "tSecretario.h"

struct tSecretario{
	tPessoa* dadosSecretario;
	tLogin* login;
	char nivel[15];
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
	printf("Nivel de poder:\n");
	scanf("%s", s -> nivel);
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