#ifndef _TLOGIN_H_
#define _TLOGIN_H_

typedef struct tLogin tLogin;

//Imprime a tela até receber um login válido
void TelaLogin();

tLogin* criaLogin();
//Autentica login vendo se o login dado existe na lista de logins do sistema
int autenticaLogin(const char* login, const char* senha, void* sis);

void leLogin(tLogin* login);

tLogin* leLoginAcesso();

void AtribuiTipoAcesso(tLogin* login, int EhSecretario);

int retornaTipodeAcesso(tLogin* login);

void adicionaIdLogin(tLogin* login, int id);

char* obterLogin(tLogin* login);

char* obterSenha(tLogin* login);

char* obterAcesso(tLogin* login);

void atualizaLogin(tLogin* login, const char* novoLogin);

void atualizaSenha(tLogin* login, const char* novaSenha);

void atualizaAcesso(tLogin* login, const char* acesso);

int retornaIdLogin(tLogin* login);

void desalocaLogin(void* login);

#endif