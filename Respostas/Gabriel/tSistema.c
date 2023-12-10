#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tLesao.h"
#include "tReceita.h"
#include "tSistema.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tFila.h"

struct tSistema{

    char path[1000];

    tMedico** medicos;
    tSecretario** secretarios;
    tPaciente** pacientes;

    tLogin** listaDeLogins;

    int qtdMedicos;
    int qtdSecretarios;
    int qtdPacientes;
    int qtdLogins;

    tFila* fila;

    int nLoginLogado;
};

void Sistema()
{
    tSistema* sistema = (tSistema*) calloc (1, sizeof(tSistema));
    InicializaSade(sistema);
    // se não tiver o binário na pasta, deve-se ver isso aqui
    tSecretario* secretarioInicial = criaSecretario();
    lerSecretario(secretarioInicial);
    defineIdSecretario(secretarioInicial, sistema -> qtdSecretarios);
    defineIdLoginSecretario(secretarioInicial, (sistema -> qtdMedicos + sistema -> qtdSecretarios));
    sistema -> qtdSecretarios++;
    sistema -> secretarios = (tSecretario**) realloc(sistema -> secretarios, sizeof(tSecretario*) * sistema -> qtdSecretarios);
    atualizaListaDeLoginsGenerico(secretarioInicial, sistema, retornaLoginSecretario, retornaSenhaSecretario, retornaAcessoSecretario);

    int TipodeAcesso = -1;
    while (1)
    {
        printf("######################## ACESSO MINI-SADE ######################");
        printf("DIGITE SEU LOGIN:\n");
        char login[100]; 
        scanf("%s", login);
        printf("DIGITE SUA SENHA:\n");
        char senha[100];
        scanf("%s", senha);
        printf("###############################################################\n");
        int nLogin = autenticaLogin(login, senha, sistema);
        printf("NLOGIN:%d", nLogin);
        if (nLogin >= 0)
        {
            sistema -> nLoginLogado = nLogin;
            TipodeAcesso = retornaTipodeAcesso(sistema -> listaDeLogins[nLogin]);
            break;
        }
        else
        {
            printf("Login errado ai maluco\n");
        }
    }
    //retorna o id do login e com base nisso eu vejo qual é o nivel de acesso 
    //e prossigo
    //coloco uma variavel dentro de login, talvez um typedef enum
    //pra saber se é um médico ou um secretário que está usando
    //fazer um idlogin somando a qtd de secretario e medico
    //caso queira achar a quem pertence o login
    
    while (1)
    {
        printf("Quantidade de medicos:%d\n", sistema -> qtdMedicos);
        printf("Quantidade de secretarios:%d\n", sistema -> qtdSecretarios);
        printf("Quantidade de pacientes:%d\n", sistema -> qtdPacientes);
        printf("Quantidade de logins:%d\n", sistema -> qtdLogins);
        ImprimeMenuPrincipal(TipodeAcesso);
        int opcao;
        scanf("%d", &opcao);
        TrataOpcao(opcao, sistema, TipodeAcesso);
    }
}

void InicializaSade(tSistema* sistema)
{
    sistema -> fila = criaFila();
    sistema -> qtdSecretarios = 0;
    sistema -> qtdMedicos = 0;
    sistema -> qtdPacientes = 0;
    sistema -> qtdLogins = 0;
}

//void adicionaLesaoSade();

//void adicionaConsultaSade();

//void printDadosSade();

char* obtemPathBD(tSistema* sistema)
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

int EhMedicoLogado(tSistema* sistema)
{
    for (int i = 0; i < sistema -> qtdLogins; i++)
    {
        for (int j = 0; j < sistema -> qtdMedicos; j++)
        {
            if(mesmoIdLoginMedico(sistema -> medicos[j], retornaIdLogin(sistema -> listaDeLogins[i])))
            {
                return j;
            }   
        }
    }
    return -1;
}

char* obterSenhaLogin(tSistema* sistema, int i)
{
    return obterSenha(sistema -> listaDeLogins[i]);
}

void ImprimeMenuPrincipal(int TipodeAcesso)
{
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO:\n");

    if (TipodeAcesso == 1)
        printf("\t(1) CADASTRAR SECRETARIO\n");
    if (TipodeAcesso == 0 || TipodeAcesso == 1)
    {
        printf("\t(2) CADASTRAR MEDICO\n");
        printf("\t(3) CADASTRAR PACIENTE\n");
    }
    printf("\t(4) REALIZAR CONSULTA\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}
void TrataOpcao(int opcao, tSistema* sistema, int TipodeAcesso)
{
        int idMedico = -1;
        switch (opcao) {
        case 1:
            if(TipodeAcesso == 0)
            {
                printf("Opcao invalida\n");
                break;
            }
            printf("Opcao 1 selecionada: CADASTRAR SECRETARIO\n");
            tSecretario* secretario = criaSecretario();
            lerSecretario(secretario);
            defineIdSecretario(secretario, sistema -> qtdSecretarios);
            defineIdLoginSecretario(secretario, (sistema -> qtdMedicos + sistema -> qtdSecretarios));
            sistema -> qtdSecretarios++;
            sistema -> secretarios = (tSecretario**) realloc(sistema -> secretarios, sizeof(tSecretario*) * sistema -> qtdSecretarios);
            atualizaListaDeLoginsGenerico(secretario, sistema, retornaLoginSecretario, retornaSenhaSecretario, retornaAcessoSecretario);
            break;
        case 2:
            if(TipodeAcesso == 2)
            {
                printf("Opcao invalida\n");
                break;
            }
            printf("Opcao 2 selecionada: CADASTRAR MEDICO\n");
            tMedico* medico = criaMedico();
            lerMedico(medico);
            defineIdMedico(medico, sistema -> qtdMedicos);
            defineIdLoginMedico(medico, (sistema -> qtdMedicos + sistema -> qtdSecretarios));
            sistema -> qtdMedicos++;
            sistema->medicos = (tMedico**)realloc(sistema->medicos, sizeof(tMedico*) * sistema->qtdMedicos);
            atualizaListaDeLoginsGenerico(medico, sistema, retornaLoginMedico, retornaSenhaMedico, retornaAcessoMedico);
            break;
        case 3:
            if(TipodeAcesso == 2)
            {
                printf("Opcao invalida\n");
                break;
            }
            printf("Opcao 3 selecionada: CADASTRAR PACIENTE\n");
            tPaciente* paciente = criaPaciente();
            lerPaciente(paciente);
            sistema -> qtdPacientes++;
            sistema -> pacientes = (tPaciente**)realloc(sistema->pacientes, sizeof(tPaciente*) * sistema->qtdPacientes);
            sistema -> pacientes[sistema -> qtdPacientes-1] = paciente;
            //atualizaListadeHumanos(sistema -> pacientes, paciente, sistema -> qtdPacientes, adicionaPacienteSade);

            break;
        case 4:
        if(TipodeAcesso == 2)
        {
            idMedico = EhMedicoLogado(sistema);
        }
            printf("Opcao 4 selecionada: REALIZAR CONSULTA\n");
            executaConsultaMedica(sistema, idMedico);
            break;
        case 5:
            printf("Opcao 5 selecionada: BUSCAR PACIENTES\n");
            
            break;
        case 6:
            printf("Opcao 6 selecionada: RELATORIO GERAL\n");
            
            break;
        case 7:
            printf("Opcao 7 selecionada: FILA DE IMPRESSAO\n");
            
            break;
        case 8:
            printf("Opcao 8 selecionada: FINALIZAR O PROGRAMA\n");
            desalocaDadosSade(sistema);
            exit(1);
        default:
            printf("Opcao invalida.\n");
            
            break;
    }
}

void atualizaListaDeLoginsGenerico(void* pessoa, tSistema* sistema, char* (*retornaLogin)(void*), char* (*retornaSenha)(void*), char* (*retornaAcesso)(void*))
{
    sistema->qtdLogins++;
    sistema->listaDeLogins = (tLogin**)realloc(sistema->listaDeLogins, sizeof(tLogin*) * sistema->qtdLogins);
    sistema->listaDeLogins[sistema->qtdLogins - 1] = criaLogin();
    atualizaLogin(sistema->listaDeLogins[sistema->qtdLogins - 1], retornaLogin(pessoa));
    atualizaSenha(sistema->listaDeLogins[sistema->qtdLogins - 1], retornaSenha(pessoa));
    atualizaAcesso(sistema->listaDeLogins[sistema->qtdLogins - 1], retornaAcesso(pessoa));
}

void atualizaListadeHumanos(void** lista, void* adicionar, int qtd, void (*funcaoAdicionar)(void**, void*, int))
{
    funcaoAdicionar(lista, adicionar, qtd);
}

void executaConsultaMedica(tSistema* sistema, int idMedico)
{
    printf("PACIENTE");
    tConsulta* consulta = criaConsulta();
    char cpf[50];
    scanf("%s", cpf);
    printf("PACIENTE");
    int idPaciente = buscaPacientePorCPF(cpf, sistema);
    printf("PACIENTE");
    if (idPaciente != -1)
    {
        printf("#################### CONSULTA MEDICA #######################\n");
        printf("CPF DO PACIENTE: ---\n");
        printf("-NOME: %s\n", obtemNomePaciente(sistema -> pacientes[idPaciente]));
        printf("-DATA DE NASCIMENTO: %s\n", obtemDataPaciente(sistema -> pacientes[idPaciente]));
        printf("---\n");
        printf("###############################################################\n");
        leConsulta(consulta);
        printf("PASSOU");

        adicionarConsultaPaciente(sistema -> pacientes[idPaciente], consulta);
        if (idMedico == -1)
            ConsultaSemMedico(consulta);
        else
            defineMedicoConsulta(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), sistema -> medicos[idMedico]);
        ImprimeMenuConsulta();
        while(1)
        {
            int opcao;
            ImprimeMenuConsulta();
            scanf("%d", &opcao);
            TrataOpcaoConsulta(opcao, idPaciente, idMedico, sistema);
        }
    }   
    else
    {
        printf("PACIENTE SEM CADASTRO\n");
    }
}

void ImprimeMenuConsulta()
{
    printf("#################### CONSULTA MEDICA #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) CADASTRAR LESAO\n");
    printf("\t(2) GERAR RECEITA MEDICA\n");
    printf("\t(3) SOLICITACAO DE BIOPSIA\n");
    printf("\t(4) ENCAMINHAMENTO\n");
    printf("\t(5) ENCERRAR CONSULTA\n");
    printf("############################################################\n");
}

int buscaPacientePorCPF(const char* cpf, tSistema* sistema)
{
    for (int i = 0; i < sistema -> qtdPacientes; i++)
    {
        printf("id:%d\n", i);
        
        char* cpfa = obtemCPFPaciente(sistema -> pacientes[i]);
        printf("id:%d\n", i);
        if (!(strcmp(cpf, cpfa)))
        {
            return i;
        }
    }
    return -1;
}

int buscaSecretarioPorCPF(const char* cpf, tSistema* sistema)
{
    for (int i = 0; i < sistema -> qtdSecretarios; i++)
    {
        char* cpfa = obtemCPFSecretario(sistema -> secretarios[i]);
        if (!(strcmp(cpf, cpfa)))
        {
            return i;
        }
    }
    return -1;
}

int buscaMedicoPorCPF(const char* cpf, tSistema* sistema)
{
    for (int i = 0; i < sistema -> qtdMedicos; i++)
    {
        char* cpfa = obtemCPFMedico(sistema -> medicos[i]);
        if (!(strcmp(cpf, cpfa)))
        {
            return i;
        }
    }
    return -1;
}

int buscaPacientePorNome(const char* nome, tSistema* sistema)
{
    for (int i = 0; i < sistema -> qtdPacientes; i++)
    {
        char* nomea = obtemNomePaciente(sistema -> pacientes[i]);
        if (!(strcmp(nome, nomea)))
        {
            return i;
        }
    }
    return -1;
}

void TrataOpcaoConsulta(int opcao, int idPaciente, int idMedico, tSistema* sistema)
{
    switch (opcao) {
            case 1:
                printf("Opcao escolhida: CADASTRAR LESAO\n");
                adicionarLesaoConsulta(retornaConsultaPaciente(sistema -> pacientes[idPaciente]));
                printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                break;
            case 2:
                printf("Opcao escolhida: GERAR RECEITA MEDICA\n");
                if (idMedico != -1)
                    tratarReceita(obtemNomePaciente(sistema -> pacientes[idPaciente]), retornaConsultaPaciente(sistema -> pacientes[idPaciente]), sistema -> medicos[idMedico]);
                else
                {
                    tMedico* medico = criaMedicoVazio();
                    tratarReceita(obtemNomePaciente(sistema -> pacientes[idPaciente]), retornaConsultaPaciente(sistema -> pacientes[idPaciente]), medico);
                }
                insereDocumentoFila(sistema -> fila, (retornaReceita(retornaConsultaPaciente(sistema -> pacientes[idPaciente]))), imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
                printf("#################### CONSULTA MEDICA #######################\n");
                printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");
                break;
            case 3:
                printf("Opcao escolhida: SOLICITACAO DE BIOPSIA\n");
                tratarBiopsia(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), obtemNomePaciente(sistema -> pacientes[idPaciente]), obtemCPFPaciente(sistema -> pacientes[idPaciente]));
                insereDocumentoFila(sistema -> fila, (retornaBiopsia(retornaConsultaPaciente(sistema -> pacientes[idPaciente]))), imprimeNaTelaBiopsia, imprimeEmArquivoBiopsia, desalocaBiopsia);
                printf("#################### CONSULTA MEDICA #######################\n");
                printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");
                break;
            case 4:
                printf("Opcao escolhida: ENCAMINHAMENTO\n");
                tratarEncaminhamento(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), obtemNomePaciente(sistema -> pacientes[idPaciente]), obtemCPFPaciente(sistema -> pacientes[idPaciente]));
                insereDocumentoFila(sistema -> fila, (retornaEncaminhamento(retornaConsultaPaciente(sistema -> pacientes[idPaciente]))), imprimeNaTelaEncaminhamento, imprimeEmArquivoEncaminhamento, desalocaEncaminhamento);
                break;
            case 5:
                printf("Opcao escolhida: ENCERRAR CONSULTA\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
    }
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

void executaFilaImpressao(tSistema* sistema, void* documento)
{
    //vai dar errado se fizer assim, é melhor tirar tudo daqui jogar lá pra fora
    //o criaFila tem que estar no criaSADE, pq se nao vai ser craido um monte de vez
    //e vai dar problema de ponteiro, nesta função de executafila
    //é melhor eu só deixar a parte pra imprimir a fila
    //imprimeFila(sistema -> fila, path);

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