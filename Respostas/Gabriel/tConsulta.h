#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

typedef struct tConsulta tConsulta;

tConsulta* criaConsulta();

void printConsulta(tConsulta* c);

void escreveBinConsulta(tConsulta* c);

void lerBinConsulta(tConsulta* c);

void adicionarLesaoConsulta(tConsulta* c);

int obtemIdConsulta(tConsulta* c);

void defineIdConsulta(tConsulta* c, int id);

int obtemQtdAtualLesaoConsulta(tConsulta* c);

//int obtemIdLesoesConsulta(tConsulta* c);

char* obtemDataConsulta(tConsulta* c);

void desalocaConsulta(tConsulta* c);

#endif