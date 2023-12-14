#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tLogin.h"
#include "tSistema.h"

struct tLogin{
	char login[100];
	char senha[100];
	char acesso[10];
	int id;
};

void TelaLogin()
{
	printf("######################## ACESSO MINI-SADE ######################\n");
	printf("DIGITE SEU LOGIN: DIGITE SUA SENHA:\n ###############################################################\n");
}

//tem que ter uma lista de logins dentro de tSistema, então eu só passo tSistema aqui e resolvo o resto lá (tLogin** listaDeLogins, int qtdLogins)

size_t tamanhoLogin(tLogin* m)
{
    return sizeof(*m);
}

tLogin* criaLogin()
{
	tLogin* login = (tLogin*) calloc (1, sizeof(tLogin));
	return login;
}

int autenticaLogin(const char* login, const char* senha, void* sis)
{
	tSistema* sistema = (tSistema*) sis;
	for (int i = 0; i < obterQtdLogins(sistema); i++)
	{
		printf("LOGIN:%s\n", obterNomeLogin(sistema, i));
		printf("SENHA:%s\n", obterSenhaLogin(sistema, i));
		if (!strcmp(obterNomeLogin(sistema, i), login))
		{
			if (!strcmp(obterSenhaLogin(sistema, i), senha))
			{
				return i;
			}
		}
		printf("I:%d", i);
	}
	return -1;
}

void leLogin(tLogin* login)
{
	printf("Digite o nome do Login:\n");
    scanf("%s", login -> login);
	printf("Digite a senha:\n");
    scanf("%s", login -> senha);
	printf("LOGIN:%s\nSENHA:%s\n", login -> login, login -> senha);
}

tLogin* leLoginAcesso()
{
	tLogin* acesso = criaLogin();
	printf("DIGITE SEU LOGIN:\n");
    scanf("%s", acesso -> login);
    printf("DIGITE SUA SENHA:\n");
    scanf("%s", acesso -> senha);

	return acesso;
}

void AtribuiTipoAcesso(tLogin* login, int EhSecretario)
{	
	if (EhSecretario)
	{
		scanf("%s", login -> acesso);
	
		int i = 0;
		while (login -> acesso[i])
		{
			login -> acesso[i] = toupper((unsigned char) login -> acesso[i]);
			i++;
		}
		printf("ACESSO:%s\n", login -> acesso);
	}
	else
	{
		strcpy(login -> acesso, "MEDICO");
	}
}

void adicionaIdLogin(tLogin* login, int id)
{
	login -> id = id;
}

int retornaIdLogin(tLogin* login)
{
	return login -> id;
}

int retornaTipodeAcesso(tLogin* login)
{
	printf("ACESSO:%s\n", login -> acesso);
	if (!(strcmp(login -> acesso, "ADMIN")))
	{
		printf("AAAAAAdmin\n");
		return 1;
	}
	else if(!(strcmp(login -> acesso, "MEDICO")))
	{
		return 2;
	}
	printf("AAAAAAAAAA");
	return 0;
}

char* obterLogin(tLogin* login)
{
	return login -> login;
}

char* obterSenha(tLogin* login)
{
	return login -> senha;
}

char* obterAcesso(tLogin* login)
{
	return login -> acesso;
}

void atualizaLogin(tLogin* login, const char* novoLogin)
{
	strcpy(login -> login, novoLogin);
}

void atualizaSenha(tLogin* login, const char* novaSenha)
{
	strcpy(login -> senha, novaSenha);
}

void atualizaAcesso(tLogin* login, const char* acesso)
{
	strcpy(login -> acesso, acesso);
}

void desalocaLogin(void* login)
{
	tLogin* l = (tLogin*) login;
	free(l);
}

void salvar_login_em_binario(tLogin *login, FILE* arquivo) {
    fwrite(login, sizeof(struct tLogin), 1, arquivo);
}

// Função para ler um login de binário
void ler_login_de_binario(tLogin *login, FILE* arquivo) {
    fread(login, sizeof(struct tLogin), 1, arquivo);
}