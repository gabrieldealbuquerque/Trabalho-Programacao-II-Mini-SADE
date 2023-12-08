#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLogin.h"
#include "tSistema.h"

struct tLogin{
	char login[100];
	char senha[100];
	NivelPermissao acesso;
};

void TelaLogin()
{
	printf("######################## ACESSO MINI-SADE ######################\n");
	printf("DIGITE SEU LOGIN: DIGITE SUA SENHA:\n ###############################################################\n");
}

//tem que ter uma lista de logins dentro de tSistema, então eu só passo tSistema aqui e resolvo o resto lá (tLogin** listaDeLogins, int qtdLogins)

tLogin* criaLogin()
{
	tLogin* login = (tLogin*) calloc (1, sizeof(tLogin));
	return login;
}

bool autenticaLogin(tLogin* login, void* sis)
{
	tSistema* sistema = (tSistema*) sis;
	for (int i = 0; i < obterQtdLogins(sistema); i++)
	{
		if (!strcmp(obterNomeLogin(sistema, i), login -> login))
		{
			if (!strcmp(obterSenhaLogin(sistema, i), login -> senha))
			{
				return true;
			}
		}
	}
	return false;
}

void leLogin(tLogin* login)
{
	printf("Digite o nome do Login:\n");
	scanf("%s", login -> login);
	printf("Digite a senha:\n");
	scanf("%s", login -> senha);
}

char* obterLogin(tLogin* login)
{
	return login -> login;
}

char* obterSenha(tLogin* login)
{
	return login -> senha;
}

void atualizaLogin(tLogin* login, const char* novoLogin)
{
	strcpy(login -> login, novoLogin);
}

void atualizaSenha(tLogin* login, const char* novaSenha)
{
	strcpy(login -> senha, novaSenha);
}

void desalocaLogin(void* login)
{
	tLogin* l = (tLogin*) login;
	free(l);
}