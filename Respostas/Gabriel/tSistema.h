#ifndef _TSISTEMA_H_
#define _TSISTEMA_H_

#include "tMedico.h"
#include "tSecretario.h"
#include "tPaciente.h"
#include "tDocumento.h"
#include <stdbool.h>
#include "tLogin.h"

typedef struct tSistema tSistema;

void Sistema();

void InicializaSade(tSistema* sistema);

//void adicionaLesaoSade();

//void adicionaConsultaSade();

int buscaSecretarioPorCPF(const char* cpf, tSistema* sistema);

int buscaMedicoPorCPF(const char* cpf, tSistema* sistema);

int buscaPacientePorCPF(const char* cpf, tSistema* sistema);

int buscaPacientePorNome(const char* nome, tSistema* sistema);

//void printDadosSade();

char* obtemPathBD(tSistema* sistema);

//void salvarColecaoBD(tSistema* sistema);

//void carregarColecaoBD(tSistema* sistema);

void executaCadastroSecretario(tSistema* sistema);

void executaCadastroMedico(tSistema* sistema);

void executaCadastroPaciente(tSistema* sistema);

void executaConsultaMedica(tSistema* sistema, int idMedico);

void executaFilaImpressao(tSistema* sistema, void* documento);

void executaBuscaPaciente(tSistema* sistema);

void executaRelatorioGeral(tSistema* sistema);

void desalocaDadosSade(tSistema* sistema);

int obterQtdLogins(tSistema* sistema);

char* obterNomeLogin(tSistema* sistema, int i);

char* obterSenhaLogin(tSistema* sistema, int i);

void ImprimeMenuPrincipal(int);

void TrataOpcao(int opcao, tSistema* sistema, int);

void TrataOpcaoConsulta(int opcao, int idPaciente, int idMedico, tSistema* sistema);

void atualizaListaDeLoginsGenerico(void* pessoa, tSistema* sistema, char* (*retornaLogin)(void*), char* (*retornaSenha)(void*), char* (*retornaAcesso)(void*));

void atualizaListadeHumanos(void** lista, void* adicionar, int qtd, void (*funcaoAdicionar)(void**, void*, int));

void ImprimeMenuConsulta();

#endif