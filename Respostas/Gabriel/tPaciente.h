#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include <stdio.h>
#include "tPessoa.h"

typedef struct tPaciente tPaciente;

tPaciente* criaPaciente();

void lerPaciente(tPaciente* p);

void adicionarConsultaPaciente(tPaciente* p);

void lerDadosComplementaresPaciente(tPaciente* p);

void printPaciente(tPaciente* p);

void escreveBinPaciente(tPaciente* p);

void lerBinPaciente(tPaciente* p);

bool comparaCPFPaciente(tPaciente* p, const char* cpf);

char* obtemCPFPaciente(tPaciente* p);

tPessoa* obtemPessoaPaciente(tPaciente* p);

int obtemIdPaciente(tPaciente* p);

void defineIdPaciente(tPaciente* p);

char* obtemNomePaciente(tPaciente* p);

int obtemIdConsultasPaciente(tPaciente* p);

int obtemQtdConsultasPaciente(tPaciente* p);

int calculaIdadePaciente(tPaciente* p);

bool comparaGeneroPaciente(tPaciente* p);

void desalocaPaciente(tPaciente* p);


#endif
