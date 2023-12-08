#ifndef _TLOGIN_H_
#define _TLOGIN_H_

typedef struct tLogin tLogin;

typedef enum{
    USER,
    ADMIN
} NivelPermissao;

#include <stdbool.h>

//Imprime a tela até receber um login válido
void TelaLogin();

tLogin* criaLogin();
//Autentica login vendo se o login dado existe na lista de logins do sistema
bool autenticaLogin(tLogin* login, void* sis);

void leLogin(tLogin* login);

char* obterLogin(tLogin* login);

char* obterSenha(tLogin* login);

void atualizaLogin(tLogin* login, const char* novoLogin);

void atualizaSenha(tLogin* login, const char* novaSenha);

void desalocaLogin(void* login);

#endif