#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

typedef struct tConsulta tConsulta;

#include "tReceita.h"
#include "tBiopsia.h"
#include "tMedico.h"
#include "tEncaminhamento.h"

tConsulta* criaConsulta();

void ConsultaSemMedico(tConsulta* consulta);

void leConsulta(tConsulta* c);

void printConsulta(tConsulta* c);

void escreveBinConsulta(tConsulta* c);

void lerBinConsulta(tConsulta* c);

void adicionarLesaoConsulta(tConsulta* c);

int obtemIdConsulta(tConsulta* c);

tMedico* retornaMedico(tConsulta* c);

void defineIdConsulta(tConsulta* c, int id);

int obtemQtdAtualLesaoConsulta(tConsulta* c);

//int obtemIdLesoesConsulta(tConsulta* c);

char* obtemDataConsulta(tConsulta* c);

void tratarReceita(char* nomePaciente, tConsulta*c, void* m);

void tratarBiopsia(tConsulta* consulta, char* nome, char* cpf);

void tratarEncaminhamento(tConsulta* consulta, char* nome, char* cpf);

void defineMedicoConsulta(tConsulta* c, void* m);

tReceita* retornaReceita(tConsulta* c);

tBiopsia** retornaBiopsia(tConsulta* c);

tEncaminhamento* retornaEncaminhamento(tConsulta* c);

void desalocaConsulta(tConsulta* c);

#endif