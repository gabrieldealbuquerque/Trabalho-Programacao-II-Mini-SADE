#ifndef _TLOGIN_H_
#define _TLOGIN_H_

typedef struct tLogin tLogin;

typedef enum{
    USER,
    ADMIN
} NivelPermissao;

//Imprime a tela até receber um login válido
void TelaLogin();

//Autentica login vendo se o login dado existe na lista de logins do sistema
bool autenticaLogin(tLogin* login, tSistema* sistema);

#endif