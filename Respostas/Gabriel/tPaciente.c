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

void adicionarConsultaPaciente(tPaciente* p, tConsulta* consulta)
{
	p -> qtdConsultas++;
	p -> consultas = (tConsulta**) realloc (p -> consultas, sizeof(tConsulta*) * p -> qtdConsultas);
	p -> consultas[p -> qtdConsultas - 1] = consulta;
}

/*void lerDadosComplementaresPaciente(tPaciente* p)
{

}*/

tConsulta* retornaConsultaPaciente(void *p)
{
	tPaciente* paciente = (tPaciente*) p;
	return paciente -> consultas[paciente -> qtdConsultas-1];
}

void printPaciente(tPaciente* p)
{

}

void escreveBinPaciente(tPaciente* p)
{

}

void lerBinPaciente(tPaciente* p)
{

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
	return (obtemNomePessoa(p -> dadosDoPaciente));
}

char* obtemDataPaciente(tPaciente* p)
{
	return (obtemDataPessoa(p -> dadosDoPaciente));
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

/*bool comparaGeneroPaciente(tPaciente* p, const char* genero)
{
	return comparaGeneroPaciente(p -> dadosDoPaciente, genero);
}*/

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
	desalocaPessoa(p -> dadosDoPaciente);
	for (int i = 0; i < p -> qtdConsultas; i++)
	{
		desalocaConsulta(p -> consultas[i]);
	}
	free(p -> consultas);
	free(p);
}