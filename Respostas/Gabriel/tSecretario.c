#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tSecretario.h"
#include "tLogin.h"

struct tSecretario{
	tPessoa* dadosSecretario;
	tLogin* login;
	char nivel[15];
};

tSecretario* criaSecretario()
{
	tSecretario* secretario = (tSecretario*) calloc (1, sizeof(tSecretario));
	return secretario;
}

void lerSecretario(tSecretario* s)
{
	lerPessoa(s -> dadosSecretario);
	leLogin(s -> login);
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