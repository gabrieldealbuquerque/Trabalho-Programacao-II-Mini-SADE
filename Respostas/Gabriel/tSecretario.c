#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPessoa.h"
#include "tSecretario.h"
#include "tLogin.h"

struct tSecretario{
	tPessoa* dadosSecretario;
	tLogin* login;
	NivelPermissao nivel;
};

tSecretario* criaSecretario()
{
	tSecretario* secretario = (tSecretario*) calloc (1, sizeof(tSecretario));
	return secretario;
}

void lerSecretario()
{

}

void printSecretario()
{

}

void escreveBinSecretario()
{

}

void lerBinSecretario()
{

}