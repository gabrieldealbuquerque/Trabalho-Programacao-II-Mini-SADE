#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLogin.h"
#include "tSecretario.h"

struct tSecretario{
	tPessoa* dadosSecretario;
	tLogin* login;
	int idLogin;
	int id;
};

tSecretario* criaSecretarioLeitura()
{
	tSecretario* secretario = (tSecretario*) calloc (1, sizeof(tSecretario));
	return secretario;
}

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

size_t tamanhoSecretario(tSecretario* m)
{
    return sizeof(*m);
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

void salvar_secretario_em_binario(tSecretario* secretario, FILE* arquivo) {
    fwrite(secretario, sizeof(tSecretario), 1, arquivo);
    escreveBinPessoa(secretario->dadosSecretario, arquivo);
    salvar_login_em_binario(secretario->login, arquivo);
}

// Função para ler um secretário de binário
void ler_secretario_de_binario(tSecretario* secretario, FILE* arquivo) {
    fread(secretario, sizeof(tSecretario), 1, arquivo);
    secretario -> dadosSecretario = lerBinPessoa(arquivo);
    secretario->login = criaLogin();
    ler_login_de_binario(secretario->login, arquivo);
}

int calculaidadeSecretario(tSecretario* secretario)
{
    return calculaIdadePessoa(secretario -> dadosSecretario);
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

char* obtemNomeSecretario(void* secre)
{
	tSecretario* secretario = (tSecretario*) secre;
	return obtemNomePessoa(secretario -> dadosSecretario);	
}

void adicionaSecretarioSade(void** s, void* adicionar, int qtdSecretarios)
{
    tSecretario** secretarios = (tSecretario**) s;
    tSecretario* secretarioAdd = (tSecretario*) adicionar;
    secretarios = (tSecretario**) realloc(secretarios, sizeof(tSecretario*) * (qtdSecretarios));
    secretarios[qtdSecretarios - 1] = secretarioAdd;
}

int obtemGeneroSecretario(tSecretario* secretario)
{
	return comparaGeneroPessoa(secretario -> dadosSecretario);
}

tPessoa* retornaPessoa(tSecretario* secretario)
{
	return secretario -> dadosSecretario;
}

void desalocaSecretario(void* sec)
{
	tSecretario* s = (tSecretario*) sec;
	desalocaPessoa(s -> dadosSecretario);
	desalocaLogin(s -> login);
	free(s);
}