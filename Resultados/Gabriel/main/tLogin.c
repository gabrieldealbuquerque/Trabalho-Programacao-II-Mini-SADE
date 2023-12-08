#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

bool autenticaLogin(tLogin* login, tSistema* sistema)
{
	for (int i = 0; i < sistema -> qtdLogins; i++)
	{
		if (!strcmp(sistema -> listaDeLogins[i] -> login, login -> login))
		{
			if (!strcmp(sistema -> listaDeLogins[i] -> senha, login -> senha))
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

void leLogin(tLogin* login)
{
	scanf("%s", login -> login);
	scanf("%s", login -> senha);
}