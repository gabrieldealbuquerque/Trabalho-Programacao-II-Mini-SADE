#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPaciente.h"

struct tPaciente{
	tPessoa* dadosDoPaciente;
	tConsulta** consultas;
	int qtdConsultas;
	int id;
};

tPaciente* criaPacienteLeitura()
{
	tPaciente* paciente = calloc(1, sizeof(tPaciente));
	return paciente;
}

tPaciente* criaPaciente()
{
	tPaciente* paciente = calloc(1, sizeof(tPaciente));
	paciente -> dadosDoPaciente = criaPessoa();
	return paciente;
}

void lerPaciente(tPaciente* p)
{
	lerPessoa(p -> dadosDoPaciente);
}

size_t tamanhoPaciente(tPaciente* m)
{
    return sizeof(*m);
}

void adicionarConsultaPaciente(tPaciente* p, tConsulta* consulta)
{
	p -> qtdConsultas++;
	p -> consultas = (tConsulta**) realloc (p -> consultas, sizeof(tConsulta*) * p -> qtdConsultas);
	p -> consultas[p -> qtdConsultas - 1] = consulta;
}

/*void lerDadosComplementaresPaciente(tPaciente* p)
{

}*/

tConsulta* retornaConsultaDesejada(tPaciente* p, int qual)
{
	if (p -> consultas[qual] != NULL)
		return p -> consultas[qual];
	return retornaConsultaPaciente(p);
}

tConsulta* retornaConsultaPaciente(void *p)
{
	tPaciente* paciente = (tPaciente*) p;
	return paciente -> consultas[paciente -> qtdConsultas-1];
}

void printPaciente(tPaciente* p)
{
	printf("%s:%s\n", obtemNomePessoa(p -> dadosDoPaciente), obtemCPFPaciente(p));
}

void salvar_paciente_em_binario(tPaciente* paciente, FILE* arquivo) {
	
    fwrite(paciente, sizeof(tPaciente), 1, arquivo);
	fwrite(&paciente -> qtdConsultas, sizeof(int), 1, arquivo);
	escreveBinPessoa(paciente -> dadosDoPaciente, arquivo);
	for (int i = 0; i < paciente -> qtdConsultas; i++)
	{
		salvar_consulta_em_binario(paciente -> consultas[i], arquivo);
	}
}

// Função para ler um paciente de binário
void ler_paciente_de_binario(tPaciente* paciente, FILE* arquivo) {
    
	fread(paciente, sizeof(tPaciente), 1, arquivo);
	fread(&paciente->qtdConsultas, sizeof(int), 1, arquivo);
	paciente -> dadosDoPaciente =lerBinPessoa(arquivo);

	 printf("NEEEOME:%s\n", obtemNomePaciente(paciente));
	if (paciente -> qtdConsultas > 0)
	{
		paciente -> consultas = (tConsulta**) malloc(sizeof(tConsulta*) * paciente -> qtdConsultas);
		for (int i = 0; i < paciente -> qtdConsultas; i++)
		{
			paciente -> consultas[i] = criaConsulta();
			ler_consulta_de_binario(paciente -> consultas[i], arquivo);
		}
	}
}


bool comparaCPFPaciente(tPaciente* p, const char* cpf)
{
	return (comparaCPFPessoa(p -> dadosDoPaciente, cpf));
}

char* obtemCPFPaciente(void* pa)
{
	tPaciente* p = (tPaciente*) pa;
	return obtemCPFPessoa(p -> dadosDoPaciente);
}

tPessoa* obtemPessoaPaciente(tPaciente* p)
{
	return (p -> dadosDoPaciente);
}

/*int obtemIdPaciente(tPaciente* p)
{
	return p -> id;
}

void defineIdPaciente(tPaciente* p, int id)
{
	p -> id = id;
}*/

char* obtemNomePaciente(tPaciente* p)
{
	return obtemNomePessoa(p -> dadosDoPaciente);
}

char* obtemDataPaciente(tPaciente* p)
{
	return obtemDataPessoa(p -> dadosDoPaciente);
}

/*int obtemIdConsultasPaciente(tPaciente* p)
{
	
}*/

int obtemQtdConsultasPaciente(tPaciente* p)
{
	return p -> qtdConsultas;
}

int calculaIdadePaciente(tPaciente* p)
{
	return calculaIdadePessoa(p -> dadosDoPaciente);
}

int obtemGeneroPaciente(tPaciente* paciente)
{
	return comparaGeneroPessoa(paciente -> dadosDoPaciente);
}

void adicionaPacienteSade(void** p, void* adicionar, int qtdPacientes)
{
    tPaciente** pacientes = (tPaciente**) p;
    tPaciente* pacienteAdd = (tPaciente*) adicionar;
    pacientes = (tPaciente**) realloc(pacientes, sizeof(tPaciente*) * (qtdPacientes));
    pacientes[qtdPacientes - 1] = pacienteAdd;
}

void desalocaPaciente(void* pa)
{
	tPaciente* p = (tPaciente*) pa;
	if (p != NULL)
	{
		if (p -> dadosDoPaciente != NULL)
			desalocaPessoa(p -> dadosDoPaciente);
		for (int i = 0; i < p -> qtdConsultas; i++)
		{
			desalocaConsulta(p -> consultas[i]);
		}
		if (p -> consultas != NULL)
			free(p -> consultas);
		free(p);
	}
}