#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include <stdbool.h>
#include "tPessoa.h"
#include "tConsulta.h"

typedef struct tPaciente tPaciente;

tPaciente* criaPaciente();

void lerPaciente(tPaciente* p);

void adicionarConsultaPaciente(tPaciente* p, tConsulta* consulta);

void lerDadosComplementaresPaciente(tPaciente* p);

void printPaciente(tPaciente* p);

void salvar_paciente_em_binario(tPaciente* paciente, FILE* arquivo);

void ler_paciente_de_binario(tPaciente* paciente, FILE* arquivo);

bool comparaCPFPaciente(tPaciente* p, const char* cpf);

char* obtemCPFPaciente(void* pa);

tPessoa* obtemPessoaPaciente(tPaciente* p);

char* obtemDataPaciente(tPaciente* p);

int obtemIdPaciente(tPaciente* p);

void defineIdPaciente(tPaciente* p);

char* obtemNomePaciente(tPaciente* p);

int obtemIdConsultasPaciente(tPaciente* p);

int obtemQtdConsultasPaciente(tPaciente* p);

size_t tamanhoPaciente(tPaciente* m);

tPaciente* criaPacienteLeitura();

int obtemGeneroPaciente(tPaciente* paciente);

int calculaIdadePaciente(tPaciente* p);

bool comparaGeneroPaciente(tPaciente* p, const char* genero);

char* retornaLoginPaciente(void* pac);

char* retornaSenhaPaciente(void* pac);

void adicionaPacienteSade(void** p, void* adicionar, int qtdPacientes);

tConsulta* retornaConsultaPaciente(void *p);

tConsulta* retornaConsultaDesejada(tPaciente* p, int qual);

void desalocaPaciente(void* p);

#endif
