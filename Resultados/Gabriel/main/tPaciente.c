#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPessoa.h"
#include "tPaciente.h"

struct tPaciente{
	tPessoa* dadosDoPaciente;
	tConsulta** consultas;
	int qtdConsultas;
	//int id;
};

tPaciente* criaPaciente()
{
	tPaciente* paciente = calloc(1, sizeof(tPaciente));
	return paciente;
}

void lerPaciente(tPaciente* p)
{
	lerPessoa(p -> dadosDoPaciente);
}

void adicionarConsultaPaciente(tPaciente* p, tConsulta* consulta)
{
	p -> qtdConsultas++;
	p -> consultas = (tConsulta**) realloc (p -> consultas, sizeof(tConsulta*) * p -> qtdConsultas)
	p -> consulta[p -> qtdConsultas - 1] = consulta;
}

/*void lerDadosComplementaresPaciente(tPaciente* p)
{

}*/

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

char* obtemCPFPaciente(tPaciente* p)
{
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

bool comparaGeneroPaciente(tPaciente* p, const char* genero)
{
	return comparaCPFPessoa(p, genero);
}

void desalocaPaciente(tPaciente* p)
{
	desalocaPessoa(p -> dadosDoPaciente);
	desalocaConsultas(p -> consultas, p -> qtdConsultas);
	free(p);
}