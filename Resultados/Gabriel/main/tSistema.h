#ifndef _TSISTEMA_H_
#define _TSISTEMA_H_

#include "tMedico.h"
#include "tSecretario.h"
#include "tPaciente.h"
#include "tDocumento.h"
#include <stdbool.h>
#include "tLogin.h"

typedef struct tSistema tSistema;
typedef struct tLista_busca tLista_busca;

tLista_busca* criaListaBusca();
void desalocaListaBuscaGenerico(void* lista);
void desalocaListaBusca(void* lista);
void imprimeNaTelaListaBusca(void* lista);
void imprimeEmArquivoListaBusca(void* lista, char* nomeArquivo);
int obterTamanhoLista(void* l);


void Sistema(const char* caminho);

void InicializaSade(tSistema* sistema);

//void adicionaLesaoSade();

//void adicionaConsultaSade();

int buscaSecretarioPorCPF(const char* cpf, tSistema* sistema);

int buscaMedicoPorCPF(const char* cpf, tSistema* sistema);

int buscaPacientePorCPF(const char* cpf, tSistema* sistema);

int buscaPacientePorNome(const char* nome, tSistema* sistema);

//void printDadosSade();

char* obtemPathBD(tSistema* sistema);

void salvar_sistema_em_binario(tSistema* sistema, const char* caminho, const char* caminhoBin);

void ler_sistema_de_binario(tSistema* sistema, const char* caminho, const char*  caminhoBin);

//void carregarColecaoBD(tSistema* sistema);

tLista_busca* adicionaResultadoBusca(tSistema* sistema, char* nome);

void executaCadastroSecretario(tSistema* sistema);

void executaCadastroMedico(tSistema* sistema);

void executaCadastroPaciente(tSistema* sistema);

void executaConsultaMedica(tSistema* sistema, int idMedico);

void executaFilaImpressao(tSistema* sistema);

void executaBusca(tSistema* sistema);

void executaRelatorioGeral(tSistema* sistema);

void desalocaDadosSade(tSistema* sistema);

int obterQtdLogins(tSistema* sistema);

char* obterNomeLogin(tSistema* sistema, int i);

char* obterSenhaLogin(tSistema* sistema, int i);

void ImprimeMenuPrincipal(int);

void TrataOpcao(int opcao, tSistema* sistema, int);

int TrataOpcaoConsulta(int opcao, int idPaciente, int idMedico, tSistema* sistema);

void atualizaListaDeLoginsGenerico(void* pessoa, tSistema* sistema, char* (*retornaLogin)(void*), char* (*retornaSenha)(void*), char* (*retornaAcesso)(void*));

void atualizaListadeHumanos(void** lista, void* adicionar, int qtd, void (*funcaoAdicionar)(void**, void*, int));

int obtemQtdPacientes(tSistema* sistema);

tPaciente** obtemPacientes(tSistema* sistema);

void ImprimeMenuConsulta();

void ler_lista_de_binario(tLista_busca *lista, FILE* arquivo);

void salvar_lista_em_binario(tLista_busca *lista, FILE* arquivo);

#endif