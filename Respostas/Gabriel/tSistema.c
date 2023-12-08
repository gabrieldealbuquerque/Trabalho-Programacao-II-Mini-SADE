#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSistema.h"

struct tSistema{

    char path[1000];

    void** medicos;
    void** secretarios;
    void** pacientes;

    tLogin** listaDeLogins;

    int qtdMedicos;
    int qtdSecretarios;
    int qtdPacientes;
    int qtdLogins;

};

void Sistema()
{
    tSistema* sistema = (tSistema*) calloc (1, sizeof(tSistema));
    InicializaSade(sistema);
    // se não tiver o binário na pasta, deve-se ver isso aqui
    tSecretario* secretarioInicial = criaSecretario();
    lerSecretario(secretarioInicial);
    sistema -> qtdSecretarios++;
    atualizaListaqualquer(sistema -> secretarios, secretarioInicial, sistema -> qtdSecretarios, adicionaSecretarioSade);
    atualizaListaDeLoginsGenerico(secretarioInicial, sistema, retornaLoginSecretario, retornaSenhaSecretario);
    while (1)
    {
        int opcao;
        printf("Quantidade de medicos:%d\n", sistema -> qtdMedicos);
        printf("Quantidade de secretarios:%d\n", sistema -> qtdSecretarios);
        printf("Quantidade de pacientes:%d\n", sistema -> qtdPacientes);
        printf("Quantidade de logins:%d\n", sistema -> qtdLogins);
        ImprimeMenuPrincipal();
        scanf("%d", &opcao);
        TrataOpcao(opcao, sistema);
    }
}

void InicializaSade(tSistema* sistema)
{
    sistema -> qtdSecretarios = 0;
    sistema -> qtdMedicos = 0;
    sistema -> qtdPacientes = 0;
    sistema -> qtdLogins = 0;
}

//void adicionaLesaoSade();

//void adicionaConsultaSade();

bool buscaSecretarioPorCPF(const char* cpf, tSistema* sistema)
{

}

bool buscaMedicoPorCPF(const char* cpf, tSistema* sistema)
{

}

bool buscaPacientePorCPF(const char* cpf, tSistema* sistema)
{

}

bool buscaPacientePorNome(const char* nome, tSistema* sistema)
{

}

//void printDadosSade();

char* obtemPathBD(tSistema* sistema)
{

}

//void salvarColecaoBD(tSistema* sistema);

//void carregarColecaoBD(tSistema* sistema);

void executaCadastroSecretario(tSistema* sistema)
{

}

void executaCadastroMedico(tSistema* sistema)
{

}

void executaCadastroPaciente(tSistema* sistema)
{

}

void executaConsultaMedica(tSistema* sistema)
{

}

void executaFilaImpressao(tSistema* sistema)
{

}

void executaBuscaPaciente(tSistema* sistema)
{

}

void executaRelatorioGeral(tSistema* sistema)
{

}

void desalocaDadosSade(tSistema* sistema)
{

}

int obterQtdLogins(tSistema* sistema)
{
    return sistema -> qtdLogins;
}

char* obterNomeLogin(tSistema* sistema, int i)
{
    return obterLogin(sistema -> listaDeLogins[i]);
}

char* obterSenhaLogin(tSistema* sistema, int i)
{
    return obterSenha(sistema -> listaDeLogins[i]);
}

void ImprimeMenuPrincipal()
{
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) CADASTRAR SECRETARIO\n");
    printf("\t(2) CADASTRAR MEDICO\n");
    printf("\t(3) CADASTRAR PACIENTE\n");
    printf("\t(4) REALIZAR CONSULTA\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}
void TrataOpcao(int opcao, tSistema* sistema)
{
        switch (opcao) {
        case 1:
            printf("Opção 1 selecionada: CADASTRAR SECRETARIO\n");
            tSecretario* secretario = criaSecretario();
            lerSecretario(secretario);
            sistema -> qtdSecretarios++;
            atualizaListaqualquer(sistema -> secretarios, secretario, sistema -> qtdSecretarios, adicionaSecretarioSade);
            atualizaListaDeLoginsGenerico(secretario, sistema, retornaLoginSecretario, retornaSenhaSecretario);
            break;
        case 2:
            printf("Opção 2 selecionada: CADASTRAR MEDICO\n");
            tMedico* medico = criaMedico();
            lerMedico(medico);
            sistema -> qtdMedicos++;
            atualizaListaqualquer(sistema -> medicos, medico, sistema -> qtdMedicos, adicionaMedicoSade);
            atualizaListaDeLoginsGenerico(medico, sistema, retornaLoginMedico, retornaSenhaMedico);
            break;
        case 3:
            printf("Opção 3 selecionada: CADASTRAR PACIENTE\n");
            tPaciente* paciente = criaPaciente();
            lerPaciente(paciente);
            sistema -> qtdPacientes++;
            atualizaListaqualquer(sistema -> pacientes, paciente, sistema -> qtdPacientes, adicionaPacienteSade);
            break;
        case 4:
            printf("Opção 4 selecionada: REALIZAR CONSULTA\n");
            
            break;
        case 5:
            printf("Opção 5 selecionada: BUSCAR PACIENTES\n");
            
            break;
        case 6:
            printf("Opção 6 selecionada: RELATORIO GERAL\n");
            
            break;
        case 7:
            printf("Opção 7 selecionada: FILA DE IMPRESSAO\n");
            
            break;
        case 8:
            printf("Opção 8 selecionada: FINALIZAR O PROGRAMA\n");
            desalocaDadosSade(sistema);
            exit(1);
        default:
            printf("Opção inválida.\n");
            
            break;
    }
}

void atualizaListaDeLoginsGenerico(void* pessoa, tSistema* sistema, char* (*retornaLogin)(void*), char* (*retornaSenha)(void*))
{
    sistema->qtdLogins++;
    sistema->listaDeLogins = (tLogin**)realloc(sistema->listaDeLogins, sizeof(tLogin*) * sistema->qtdLogins);
    sistema->listaDeLogins[sistema->qtdLogins - 1] = criaLogin();
    atualizaLogin(sistema->listaDeLogins[sistema->qtdLogins - 1], retornaLogin(pessoa));
    atualizaSenha(sistema->listaDeLogins[sistema->qtdLogins - 1], retornaSenha(pessoa));
}

void atualizaListaqualquer(void** lista, void* adicionar, int qtd, void (*funcaoAdicionar)(void**, void*, int))
{
    funcaoAdicionar(lista, adicionar, qtd);
}