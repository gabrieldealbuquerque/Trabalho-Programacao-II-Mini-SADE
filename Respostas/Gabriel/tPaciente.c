#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPessoa.h"
#include "tPaciente.h"

struct tPaciente{
	tPessoa* dadosDoPaciente;
	tConsulta** consultas;
};

tPaciente* criaPaciente()
{
	tPaciente* paciente = calloc(1, sizeof(tPaciente));
	return paciente;
}

void lerPaciente(tPaciente* p)
{

}

void adicionarConsultaPaciente(tPaciente* p)
{

}

void lerDadosComplementaresPaciente(tPaciente* p)
{

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

}

char* obtemCPFPaciente(tPaciente* p)
{

}

tPessoa* obtemPessoaPaciente(tPaciente* p)
{

}

int obtemIdPaciente(tPaciente* p)
{

}

void defineIdPaciente(tPaciente* p)
{

}

char* obtemNomePaciente(tPaciente* p)
{

}

int obtemIdConsultasPaciente(tPaciente* p)
{

}

int obtemQtdConsultasPaciente(tPaciente* p)
{

}

int calculaIdadePaciente(tPaciente* p)
{
    
}

bool comparaGeneroPaciente(tPaciente* p)
{

}

void desalocaPaciente(tPaciente* p)
{

}