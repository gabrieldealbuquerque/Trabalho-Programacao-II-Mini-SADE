#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

typedef struct tConsulta tConsulta;

#include "tReceita.h"
#include "tBiopsia.h"
#include "tMedico.h"
#include "tEncaminhamento.h"

tConsulta* criaConsulta();

void ConsultaSemMedico(tConsulta* consulta);

void atribuiMedicoConsulta(tConsulta* consulta, tMedico* medico);

void leConsulta(tConsulta* c);

void printConsulta(tConsulta* c);

void ler_consulta_de_binario(tConsulta* consulta, FILE* arquivo);

void salvar_consulta_em_binario(tConsulta* consulta, FILE* arquivo);

void adicionarLesaoConsulta(tConsulta* c);

int obtemIdConsulta(tConsulta* c);

tMedico* retornaMedico(tConsulta* c);

void defineIdConsulta(tConsulta* c, int id);

int obtemQtdAtualLesaoConsulta(tConsulta* c);

//int obtemIdLesoesConsulta(tConsulta* c);

char* obtemDataConsulta(tConsulta* c);

void tratarReceita(char* nomePaciente, tConsulta*c, void* m);

int tratarBiopsia(tConsulta* consulta, char* nome, char* cpf);

void tratarEncaminhamento(tConsulta* consulta, char* nome, char* cpf);

void defineMedicoConsulta(tConsulta* c, void* m);

tReceita* retornaReceita(tConsulta* c);

tBiopsia* retornaBiopsia(tConsulta* c);

tLesao** retornaLesoes(tConsulta* l);

tEncaminhamento* retornaEncaminhamento(tConsulta* c);

void desalocaConsulta(tConsulta* c);

#endif