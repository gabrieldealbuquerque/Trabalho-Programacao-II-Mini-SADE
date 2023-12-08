#ifndef _TSISTEMA_H_
#define _TSISTEMA_H_

#include "tMedico.h"
#include "tSecretario.h"
#include "tPaciente.h"
#include <stdbool.h>
#include "tLogin.h"

typedef struct tSistema tSistema;

void Sistema();

void InicializaSade(tSistema* sistema);

//void adicionaLesaoSade();

//void adicionaConsultaSade();

bool buscaSecretarioPorCPF(const char* cpf, tSistema* sistema);

bool buscaMedicoPorCPF(const char* cpf, tSistema* sistema);

bool buscaPacientePorCPF(const char* cpf, tSistema* sistema);

bool buscaPacientePorNome(const char* nome, tSistema* sistema);

//void printDadosSade();

char* obtemPathBD(tSistema* sistema);

//void salvarColecaoBD(tSistema* sistema);

//void carregarColecaoBD(tSistema* sistema);

void executaCadastroSecretario(tSistema* sistema);

void executaCadastroMedico(tSistema* sistema);

void executaCadastroPaciente(tSistema* sistema);

void executaConsultaMedica(tSistema* sistema);

void executaFilaImpressao(tSistema* sistema);

void executaBuscaPaciente(tSistema* sistema);

void executaRelatorioGeral(tSistema* sistema);

void desalocaDadosSade(tSistema* sistema);

int obterQtdLogins(tSistema* sistema);

char* obterNomeLogin(tSistema* sistema, int i);

char* obterSenhaLogin(tSistema* sistema, int i);

void ImprimeMenuPrincipal();

void TrataOpcao(int opcao, tSistema* sistema);

void atualizaListaDeLoginsGenerico(void* pessoa, tSistema* sistema, char* (*retornaLogin)(void*), char* (*retornaSenha)(void*));

void atualizaListaAdequadaGenericamente(void** lista, void* adicionar, int i);

void atualizaListaqualquer(void** lista, void* adicionar, int qtd, void (*funcaoAdicionar)(void**, void*, int));

#endif