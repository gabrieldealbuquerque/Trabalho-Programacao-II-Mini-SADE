#ifndef _TMEDICO_H_
#define _TMEDICO_H_

#include <stdio.h>
#include <stdbool.h>

// Definição do tipo de dado tMedico
typedef struct tMedico tMedico;

// Cria um novo objeto tMedico e retorna um ponteiro para ele
tMedico* criaMedico();

tMedico* criaMedicoVazio();

// Lê informações do médico a partir do usuário e atualiza o objeto tMedico
void lerMedico(tMedico* m);

// Imprime as informações do médico, dado um ponteiro para o objeto tMedico e a quantidade de médicos
void printMedico(tMedico* m, int qtdMedico);

// Escreve as informações do médico em um arquivo binário
void escreveBinMedico(tMedico* m, const char* caminho);

//Lê as informações do médico de um arquivo binário
void lerBinMedico(tMedico* m, const char* caminho);

// Compara o CPF do médico com uma string fornecida e retorna verdadeiro se forem iguais
bool comparaCPFMedico(tMedico* m, const char* cpf);

// Obtém o CPF do médico como uma string
char* obtemCPFMedico(tMedico* m);

int mesmoIdLoginMedico(tMedico* m, int id);

// Obtém o ID do médico como uma string
void defineIdMedico(tMedico* m, int id);

void defineIdLoginMedico(tMedico* m, int id);

// Obtém o nome do médico como uma string
char* obtemNomeMedico(tMedico* m);

// Obtém o CRM do médico como uma string
char* obtemCRMMedico(tMedico* m);

char* retornaLoginMedico(void* me);

char* retornaSenhaMedico(void* me);

char* retornaAcessoMedico(void *me);

void adicionaMedicoSade(void** m, void* adicionar, int qtdSecretarios);
// Libera a memória alocada para o objeto tMedico
void desalocaMedico(void* medico);

#endif
