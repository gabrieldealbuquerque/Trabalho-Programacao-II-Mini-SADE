#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tLesao.h"
#include "tReceita.h"
#include "tSistema.h"
#include "tBiopsia.h"
#include "tRelatorio.h"
#include "tEncaminhamento.h"
#include "tFila.h"

struct tLista_busca {
    char** nomes;
    int qtd;
};

struct tSistema{

    char path[1000];
    char saidaBinario[1000];

    tMedico** medicos;
    tSecretario** secretarios;
    tPaciente** pacientes;

    tLogin** listaDeLogins;

    int qtdMedicos;
    int qtdSecretarios;
    int qtdPacientes;
    int qtdLogins;

    tFila* fila;
    char nomeLogin[100];
    char nomeMedico[100];
    char crmLogin[100];
    char senhaLogin[100];
    int loginMedico;
    int nLoginLogado;
};

int verificaArquivoExistente(const char* caminho, const char* caminhoBin) {
    char filePath[1500];  // Adjust the size as needed
    sprintf(filePath, "%s/%s%s", caminho, caminhoBin,"sistema.bin");
    printf("CAMINHO:%s", filePath);
    FILE* arquivo = fopen(filePath, "rb");
    if (arquivo != NULL) {
        printf("\ncucucucuu\n");
        fclose(arquivo);
        return 1; // Arquivo existe
    }
    printf("\nbuvecuecuaecu\n");
    return 0; // Arquivo não existe
}

void Sistema(const char* caminho)
{
    tSistema* sistema = (tSistema*) calloc (1, sizeof(tSistema));
    InicializaSade(sistema);
    strcpy(sistema -> path, caminho);  
    int TipodeAcesso = -1;
    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS:\n");
    printf("################################################\n");
    scanf(" %s", sistema -> saidaBinario);
    printf("Caminho do banco de dados: %s\n", sistema -> path);
    printf("Caminho da pasta de saida: %s\n", sistema -> saidaBinario);
    if (verificaArquivoExistente(caminho, sistema -> saidaBinario)) {
        printf("ARQUIVO PATH:%s\n", sistema -> path);
        ler_sistema_de_binario(sistema, sistema -> path, sistema -> saidaBinario);
        strcpy(sistema -> path, caminho);  
        printf("QTD PACIETNE:%d\n", sistema -> qtdPacientes);
        for (int i = 0; i < sistema -> qtdPacientes; i++)
        {
            printf("PACIENTE[%d]:%s", i, obtemNomePaciente(sistema -> pacientes[i]));
        }
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
            strcpy(sistema -> nomeLogin, login);
            strcpy(sistema -> senhaLogin, senha);
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
        exit(1);
    } else {

        tSecretario* secretarioInicial = criaSecretario();
        lerSecretario(secretarioInicial);
        defineIdSecretario(secretarioInicial, sistema -> qtdSecretarios);
        defineIdLoginSecretario(secretarioInicial, (sistema -> qtdMedicos + sistema -> qtdSecretarios));
        sistema -> qtdSecretarios++;
        sistema -> secretarios = (tSecretario**) realloc(sistema -> secretarios, sizeof(tSecretario*) * sistema -> qtdSecretarios);
        sistema -> secretarios[sistema -> qtdSecretarios-1] = secretarioInicial;
        atualizaListaDeLoginsGenerico(secretarioInicial, sistema, retornaLoginSecretario, retornaSenhaSecretario, retornaAcessoSecretario);
    }
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
    sistema -> loginMedico = 0;
    sistema -> medicos = NULL;
    sistema -> secretarios = NULL;
    sistema -> pacientes = NULL;
    sistema -> listaDeLogins = NULL;
}

//void adicionaLesaoSade();

//void adicionaConsultaSade();

//void printDadosSade();



int obterQtdLogins(tSistema* sistema)
{
    return sistema -> qtdLogins;
}

char* obterNomeLogin(tSistema* sistema, int i)
{
    return obterLogin(sistema -> listaDeLogins[i]);
}

int engenhariaReversa(tSistema* sistema)
{
    for (int i = 0; i < sistema -> qtdLogins; i++)
    {
        for (int j = 0; j < sistema -> qtdMedicos; j++)
        {
            if(!strcmp(retornaLoginMedico(sistema -> medicos[i]), sistema -> nomeLogin))
            {
                if(!strcmp(retornaSenhaMedico(sistema -> medicos[i]), sistema -> senhaLogin))
                {
                    strcpy(sistema -> nomeMedico, obtemNomeMedico(sistema -> medicos[i]));
                    strcpy(sistema -> crmLogin, obtemCRMMedico(sistema -> medicos[i]));
                    sistema -> loginMedico = 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

char* obterLoginNome(tSistema* sis)
{
    return sis -> nomeLogin;
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
                    printf("Quantidade de medicos:%d\n", sistema -> qtdMedicos);
        printf("Quantidade de secretarios:%d\n", sistema -> qtdSecretarios);
        printf("Quantidade de pacientes:%d\n", sistema -> qtdPacientes);
        printf("Quantidade de logins:%d\n", sistema -> qtdLogins);
        char a;
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
            for (int i = 0; i < sistema -> qtdSecretarios; i++)
            {
                char* cpf; 
                cpf = strdup(obtemCPFSecretario(sistema -> secretarios[i]));
                if (!strcmp(obtemCPFSecretario(secretario), cpf))
                {
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    free(cpf);
                    desalocaSecretario(secretario);
                    return;
                }
                free(cpf);
            }
            defineIdSecretario(secretario, sistema -> qtdSecretarios);
            defineIdLoginSecretario(secretario, (sistema -> qtdMedicos + sistema -> qtdSecretarios));
            sistema -> qtdSecretarios++;
            sistema -> secretarios = (tSecretario**) realloc(sistema -> secretarios, sizeof(tSecretario*) * sistema -> qtdSecretarios);
            sistema -> secretarios[sistema -> qtdSecretarios-1] = secretario;
            atualizaListaDeLoginsGenerico(secretario, sistema, retornaLoginSecretario, retornaSenhaSecretario, retornaAcessoSecretario);
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
            scanf(" %c", &a);
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
            for (int i = 0; i < sistema -> qtdMedicos; i++)
            {
                char* cpf; 
                cpf = strdup(obtemCPFMedico(sistema -> medicos[i]));
                if (!strcmp(obtemCPFMedico(medico), cpf))
                {
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    free(cpf);
                    desalocaMedico(medico);
                    return;
                }
                free(cpf);
            }
            defineIdMedico(medico, sistema -> qtdMedicos);
            defineIdLoginMedico(medico, (sistema -> qtdMedicos + sistema -> qtdSecretarios));
            sistema -> qtdMedicos++;
            sistema->medicos = (tMedico**)realloc(sistema->medicos, sizeof(tMedico*) * sistema->qtdMedicos);
            sistema -> medicos[sistema -> qtdMedicos-1] = medico;
            atualizaListaDeLoginsGenerico(medico, sistema, retornaLoginMedico, retornaSenhaMedico, retornaAcessoMedico);
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
            scanf(" %c", &a);
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
            for (int i = 0; i < sistema -> qtdPacientes; i++)
            {
                char* cpf; 
                cpf = strdup(obtemCPFPaciente(sistema -> pacientes[i]));
                if (!strcmp(obtemCPFPaciente(paciente), cpf))
                {
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA.\n");
                    free(cpf);
                    desalocaPaciente(paciente);
                    return;
                }
                free(cpf);
            }
            printf("SISTEMA -> QTDPACIENTES:%d\n", sistema -> qtdPacientes);
            sistema -> qtdPacientes++;
            printf("SISTEMA -> QTDPACIENTES:%d\n", sistema -> qtdPacientes);
            sistema -> pacientes = (tPaciente**)realloc(sistema->pacientes, sizeof(tPaciente*) * sistema->qtdPacientes);
            sistema -> pacientes[sistema -> qtdPacientes-1] = paciente;
            //atualizaListadeHumanos(sistema -> pacientes, paciente, sistema -> qtdPacientes, adicionaPacienteSade);
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
            scanf(" %c", &a);
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
            executaBusca(sistema);
            scanf(" %c", &a);
            break;
        case 6:
            printf("Opcao 6 selecionada: RELATORIO GERAL\n");
            executaRelatorioGeral(sistema);
            scanf(" %c", &a);
            break;
        case 7:
            printf("Opcao 7 selecionada: FILA DE IMPRESSAO\n");
            executaFilaImpressao(sistema);
            break;
        case 8:
            printf("Opcao 8 selecionada: FINALIZAR O PROGRAMA\n");
            char filePath[1500];  // Adjust the size as needed
            printf("PATH:%s\n", sistema -> path);  
            sprintf(filePath, "%s/saida", sistema -> path);
            printf("PATH:%s", filePath);        
            imprimeFila(sistema -> fila, filePath);
            
            salvar_sistema_em_binario(sistema, sistema -> path, sistema -> saidaBinario);
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
        {
            printf("\n\n\n\nMEDICO MEIDCO MEIDCO MEIDOC:%s-%d\n\n\n", obtemNomeMedico(sistema -> medicos[idMedico]), obtemIdMedico(sistema -> medicos[idMedico]));
            defineMedicoConsulta(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), sistema -> medicos[idMedico]);
        }
        int a = 0;
        while(1)
        {
            int opcao;
            ImprimeMenuConsulta();
            scanf("%d", &opcao);
            a = TrataOpcaoConsulta(opcao, idPaciente, idMedico, sistema);
            printf("A:%d", a);
            if (a)
            {
                break;
            }
            else if (a == 0)
            {
                char b;
                scanf(" %c", &b);
            }
        }
    }   
    else
    {
        free(consulta);
        printf("PACIENTE SEM CADASTRO\n");
    }
}

void executaBusca(tSistema* sistema)
{
    char nome[100];
    printf("NOME DO PACIENTE:\n");
    scanf(" %99[^\n]", nome);

    //colocando o nome em maisculo

    int i = 0;
    while (nome[i])
    {
        nome[i] = toupper((unsigned char) nome[i]);
        i++;
    }
    printf("PACIENTES ENCONTRADOS: \n");
    tLista_busca* lista = adicionaResultadoBusca(sistema, nome);
    if (obterTamanhoLista(lista) == 0)
    {
        printf("#################### BUSCAR PACIENTES #######################\n");
        printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");
        desalocaListaBusca(lista);
        return;
    }
    else if (obterTamanhoLista(lista) > 0)
        imprimeNaTelaListaBusca(lista);

    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) ENVIAR LISTA PARA IMPRESSAO\n");
    printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
    printf("############################################################\n");

    int opcao = 0;
    scanf("%d", &opcao); 
    if (opcao == 1)
    {
        printf("#################### BUSCAR PACIENTES #######################\n");
        printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");
        printf("############################################################\n");
        insereDocumentoFila(sistema -> fila, lista, imprimeNaTelaListaBusca, imprimeEmArquivoListaBusca, desalocaListaBusca);
    }
    else if (opcao == 2)
    {
        desalocaListaBusca(lista);
        return;
    }
    else
        printf("NAO EXISTE ESTA OPCAO");

}

tLista_busca* adicionaResultadoBusca(tSistema* sistema, char* nome)
{
    tLista_busca* lista = criaListaBusca();

    for (int i = 0; i < sistema -> qtdPacientes; i++)
    {
        printf("%s E %s\n", obtemNomePaciente(sistema->pacientes[i]), nome);
        if (!strcmp(obtemNomePaciente(sistema->pacientes[i]), nome))
        {
            lista->qtd++;

            lista->nomes = (char**)realloc(lista->nomes, sizeof(char*) * lista->qtd);

            // Alocando espaço para o novo nome
            char* nomeFormatado = (char*)malloc(strlen(nome) + strlen(obtemCPFPaciente(sistema->pacientes[i])) + 5);

            // Copiando o nome original para a nova string
            strcpy(nomeFormatado, nome);

            // Concatenando o CPF formatado
            strcat(nomeFormatado, " (");
            strcat(nomeFormatado, obtemCPFPaciente(sistema->pacientes[i]));
            strcat(nomeFormatado, ")");
            printf("CUUUUUUUUUUU");
            lista->nomes[lista->qtd - 1] = nomeFormatado;
        }
    }

    return lista; 
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

int TrataOpcaoConsulta(int opcao, int idPaciente, int idMedico, tSistema* sistema)
{
    switch (opcao) {
            case 1:
                printf("Opcao escolhida: CADASTRAR LESAO\n");
                adicionarLesaoConsulta(retornaConsultaPaciente(sistema -> pacientes[idPaciente]));
                printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                return 0;
            case 2:
                printf("Opcao escolhida: GERAR RECEITA MEDICA\n");
                if (idMedico != -1)
                {
                    if(engenhariaReversa(sistema))
                    {
                        tMedico* medico = criaMedicoVazio();
                        atribuiNomeMedico(medico, sistema -> nomeMedico);
                        atribuiCRMMedico(medico, sistema -> crmLogin);
                        tratarReceita(obtemNomePaciente(sistema -> pacientes[idPaciente]), retornaConsultaPaciente(sistema -> pacientes[idPaciente]), medico);
                        atribuiMedicoConsulta(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), medico);
                        desalocaMedico(medico);
                    }
                    else
                    {
                        tratarReceita(obtemNomePaciente(sistema -> pacientes[idPaciente]), retornaConsultaPaciente(sistema -> pacientes[idPaciente]), sistema -> medicos[idMedico]);
                        atribuiMedicoConsulta(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), sistema -> medicos[idMedico]);
                    }
                }
                else
                {
                    tMedico* medico = criaMedicoVazio();
                    tratarReceita(obtemNomePaciente(sistema -> pacientes[idPaciente]), retornaConsultaPaciente(sistema -> pacientes[idPaciente]), medico);
                    desalocaMedico(medico);
                }
                insereDocumentoFila(sistema -> fila, (retornaReceita(retornaConsultaPaciente(sistema -> pacientes[idPaciente]))), imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
                printf("#################### CONSULTA MEDICA #######################\n");
                printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");
                return 0;
            case 3:
                printf("Opcao escolhida: SOLICITACAO DE BIOPSIA\n");
                int LesoesECirurgia = 0;
                LesoesECirurgia = tratarBiopsia(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), obtemNomePaciente(sistema -> pacientes[idPaciente]), obtemCPFPaciente(sistema -> pacientes[idPaciente]));
                if (LesoesECirurgia)
                {
                    insereDocumentoFila(sistema -> fila, (retornaBiopsia(retornaConsultaPaciente(sistema -> pacientes[idPaciente]))), imprimeNaTelaBiopsia, imprimeEmArquivoBiopsia, desalocaBiopsia);
                    printf("#################### CONSULTA MEDICA #######################\n");
                    printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                    printf("############################################################\n");
                }
                return 0;
            case 4:
                printf("#################### CONSULTA MEDICA #######################\n");
                printf("Opcao escolhida: ENCAMINHAMENTO\n");
                tratarEncaminhamento(retornaConsultaPaciente(sistema -> pacientes[idPaciente]), obtemNomePaciente(sistema -> pacientes[idPaciente]), obtemCPFPaciente(sistema -> pacientes[idPaciente]));
                insereDocumentoFila(sistema -> fila, (retornaEncaminhamento(retornaConsultaPaciente(sistema -> pacientes[idPaciente]))), imprimeNaTelaEncaminhamento, imprimeEmArquivoEncaminhamento, desalocaEncaminhamento);
                printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");
                return 0;
            case 5:
                printf("Opcao escolhida: ENCERRAR CONSULTA\n");
                return 1;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                return 0;
    }
}


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

void executaFilaImpressao(tSistema* sistema)
{
    while(1)
    {
        printf("################ FILA DE IMPRESSAO MEDICA ##################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1) EXECUTAR FILA DE IMPRESSAO\n");
        printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
        printf("############################################################\n");
        int opcao = 0;
        scanf(" %d", &opcao);
   
        if (opcao == 1)
        {
            imprimeFila(sistema -> fila, sistema -> path);
            printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");
            char a;
            scanf(" %c", &a);
            opcao = 0;
        }
        else if (opcao == 2)
        {
            return;
        }
        else
        {
            printf("NAO EXISTE ESSA OPCAO DOIDAO\n");
        }  
    }
}

int obtemQtdPacientes(tSistema* sistema) {
    return sistema->qtdPacientes;
}

// Função que retorna o vetor de pacientes
tPaciente** obtemPacientes(tSistema* sistema) {
    return sistema->pacientes;
}

void executaRelatorioGeral(tSistema* sistema)
{
            printf("AAAAAAA");
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;
    for (int i = 0; i < sistema -> qtdPacientes; i++)
    {
        if (obtemQtdConsultasPaciente(sistema -> pacientes[i]) > 0)
        {
            a1++;
        }
        a2 += calculaIdadePaciente(sistema -> pacientes[i]);
        
        if (obtemGeneroPaciente(sistema -> pacientes[i]) == 0)
        {
            a3++;
        }
        else if (obtemGeneroPaciente(sistema -> pacientes[i]) == 1)
        {
            a4++;
        }
        else if (obtemGeneroPaciente(sistema -> pacientes[i]) == 2)
        {
            a5++;
        }
        
        //calcular o tmanaho medio de lesoes e a quantidade delas
        for (int j = 0; j < obtemQtdConsultasPaciente(sistema -> pacientes[i]); j++)
        {
            
            a7 += obtemQtdAtualLesaoConsulta(retornaConsultaDesejada(sistema -> pacientes[i], j));
            int qtd = obtemQtdAtualLesaoConsulta(retornaConsultaDesejada(sistema -> pacientes[i], j));

            for (int k = 0; k < qtd; k++)
            {
                if (retornaLesoes(retornaConsultaPaciente(sistema -> pacientes[i]))[k] != NULL)
                {
                    a6 += obtemTamanhoLesao(retornaLesoes(retornaConsultaPaciente(sistema -> pacientes[i]))[k]);
                    if (obtemCirurgiaLesao(retornaLesoes(retornaConsultaPaciente(sistema -> pacientes[i]))[k]))
                    {
                        a8++;
                        printf("CIRUGRIA");
                    }
                    
                    if (obtemCrioterapiaLesao(retornaLesoes(retornaConsultaPaciente(sistema -> pacientes[i]))[k]))
                    {
                        
                        a9++;
                        printf("CRIO");
                    }
                }
            }
        }
        
    }
    if (a7 > 0)
    {
        a6 = a6/a7;
    }

    a2 = a2/sistema -> qtdPacientes;


    
    tRelatorio* relatorio = criaRelatorio(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    imprimeNaTelaRelatorio(relatorio);
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) ENVIAR PARA IMPRESSAO\n");
    printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
    printf("############################################################\n");

    int opcao;
    scanf(" %d", &opcao);
    printf("OPCAO:%d\n", opcao);
    if (opcao == 1)
    {
        insereDocumentoFila(sistema -> fila, relatorio, imprimeNaTelaRelatorio, imprimeEmArquivoRelatorio, desalocaRelatorioGenerico);
        printf("RELATÓRIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    }
    else if (opcao == 2)
    {
        desalocaRelatorioGenerico(relatorio);
    }
    else
    {
        printf("NAO EXISTE ESTA OPCAO\n");
    }
}
void desalocaDadosSade(tSistema* sistema)
{
    if (sistema == NULL) {
        return;
    }
    // Desaloca pacientes
    if (sistema->pacientes != NULL) {
        for (int i = 0; i < sistema->qtdPacientes; i++) {
            if (sistema->pacientes[i] != NULL) {
                desalocaPaciente(sistema->pacientes[i]);
            }
        }
        free(sistema->pacientes);
    }

    // Desaloca medicos
    if (sistema->medicos != NULL) {
        for (int i = 0; i < sistema->qtdMedicos; i++) {
            if (sistema->medicos[i] != NULL) {
                desalocaMedico(sistema->medicos[i]);
            }
        }
        free(sistema->medicos);
        
    }

    // Desaloca secretarios
    if (sistema->secretarios != NULL) {
        for (int i = 0; i < sistema->qtdSecretarios; i++) {
            if (sistema->secretarios[i] != NULL) {
                desalocaSecretario(sistema->secretarios[i]);
            }
        }
        free(sistema->secretarios);
        
    }

    // Desaloca logins
    if (sistema->listaDeLogins != NULL) {
        for (int i = 0; i < sistema->qtdLogins; i++) {
            if (sistema->listaDeLogins[i] != NULL) {
                desalocaLogin(sistema->listaDeLogins[i]);
            }
        }
        free(sistema->listaDeLogins);
        
    }

    if (sistema -> fila != NULL)
    {
        desalocaFila(sistema -> fila);
        
    }
    free(sistema);
    
}

tLista_busca* criaListaBusca() {
    tLista_busca* lista = (tLista_busca*)calloc(1, sizeof(tLista_busca));
    lista->qtd = 0;
    return lista;
}

int obterTamanhoLista(void* lista)
{
    if (lista != NULL)
    {
        tLista_busca* lista_busca = (tLista_busca*)lista;
        return lista_busca -> qtd;
    }
    return -1;
}


void desalocaListaBuscaGenerico(void* lista)
{
    if (lista != NULL)
    {
        desalocaListaBusca(lista);
    }
}

void desalocaListaBusca(void* lista)
{
    if (lista != NULL)
    {
        tLista_busca* lista_busca = (tLista_busca*)lista;
        for (int i = 0; i < lista_busca->qtd; ++i)
        {
            free(lista_busca->nomes[i]);
        }
        free(lista_busca->nomes);
        free(lista_busca);
    }
}

void imprimeNaTelaListaBusca(void* lista)
{
    tLista_busca* lista_busca = (tLista_busca*)lista;
    for (int i = 0; i < lista_busca->qtd; ++i)
    {
        printf("%d - %s\n", i + 1, lista_busca->nomes[i]);
    }
}

void imprimeEmArquivoListaBusca(void* lista, char* nomeArquivo)
{
    char filePath[1500];  // Adjust the size as needed
    sprintf(filePath, "%s/lista_busca.txt", nomeArquivo);

    FILE *arquivo = fopen(filePath, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    tLista_busca* lista_busca = (tLista_busca*)lista;
    for (int i = 0; i < lista_busca->qtd; ++i) {
        fprintf(arquivo, "%d - %s\n", i + 1, lista_busca->nomes[i]);
    }

    fclose(arquivo);
}

void salvar_lista_em_binario(tLista_busca *lista, FILE* arquivo) {

    fwrite(&lista->qtd, sizeof(int), 1, arquivo);
    for (int i = 0; i < lista->qtd; i++) {
        int comprimento = strlen(lista->nomes[i]);
        fwrite(&comprimento, sizeof(int), 1, arquivo);
        fwrite(lista->nomes[i], sizeof(char), comprimento, arquivo);
    }

    fclose(arquivo);
}

// Função para ler uma lista de binário
void ler_lista_de_binario(tLista_busca *lista, FILE* arquivo) {
    fread(&lista->qtd, sizeof(int), 1, arquivo);
    lista->nomes = (char**)malloc(lista->qtd * sizeof(char*));
    for (int i = 0; i < lista->qtd; i++) {
        int comprimento;
        fread(&comprimento, sizeof(int), 1, arquivo);
        lista->nomes[i] = (char*)malloc((comprimento + 1) * sizeof(char));
        fread(lista->nomes[i], sizeof(char), comprimento, arquivo);
        lista->nomes[i][comprimento] = '\0';  // Adiciona o caractere nulo ao final
    }
}

void salvar_sistema_em_binario(tSistema* sistema, const char* caminho, const char* caminhoBin) {
    char filePath[1500];  // Adjust the size as needed
    sprintf(filePath, "%s/%s%s", caminho,caminhoBin,"sistema.bin");

    FILE *arquivo = fopen(filePath, "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita binária");
        return;
    }

    fwrite(sistema, sizeof(tSistema), 1, arquivo);
    fwrite(&sistema -> qtdPacientes, sizeof(int), 1, arquivo);
    fwrite(&sistema -> qtdMedicos, sizeof(int), 1, arquivo);
    fwrite(&sistema -> qtdSecretarios, sizeof(int), 1, arquivo);
    fwrite(&sistema -> qtdLogins, sizeof(int), 1, arquivo);
    for (int i = 0; i < sistema->qtdPacientes; ++i) {
      
        salvar_paciente_em_binario(sistema->pacientes[i], arquivo);
    }

    for (int i = 0; i < sistema->qtdMedicos; i++) {
       escreveBinMedico(sistema -> medicos[i], arquivo);
    }


    for (int i = 0; i < sistema->qtdSecretarios; i++) {
        salvar_secretario_em_binario(sistema -> secretarios[i], arquivo);
    }

    for (int i = 0; i < sistema->qtdLogins; i++) {
        salvar_login_em_binario(sistema -> listaDeLogins[i], arquivo);
    }

    fclose(arquivo);
}

// Função para ler um sistema de binário
void ler_sistema_de_binario(tSistema* sistema, const char* caminho, const char*  caminhoBin) {
    char filePath[1500];  // Adjust the size as needed
    sprintf(filePath, "%s/%s%s", caminho, caminhoBin,"sistema.bin");
    FILE* arquivo = fopen(filePath, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura binária");
        exit(1);
    }

    fread(sistema, sizeof(tSistema), 1, arquivo);
    fread(&sistema->qtdPacientes, sizeof(int), 1, arquivo);
    fread(&sistema->qtdMedicos, sizeof(int), 1, arquivo);
    fread(&sistema->qtdSecretarios, sizeof(int), 1, arquivo);    
    fread(&sistema->qtdLogins, sizeof(int), 1, arquivo);  
    sistema->pacientes = (tPaciente**)malloc(sistema->qtdPacientes * sizeof(tPaciente*));

    for (int i = 0; i < sistema->qtdPacientes; ++i) {
        sistema->pacientes[i] = criaPacienteLeitura();
        ler_paciente_de_binario(sistema->pacientes[i], arquivo);
        printf("CONSULTAS:%d\n", obtemQtdConsultasPaciente(sistema -> pacientes[i]));
    }

    sistema->medicos = (tMedico**)malloc(sistema->qtdMedicos * sizeof(tMedico*));

    for (int i = 0; i < sistema->qtdMedicos; ++i) {
        sistema->medicos[i] = CriaMedicoLeitura();
        lerBinMedico(sistema->medicos[i], arquivo);
    }

    sistema->secretarios = (tSecretario**)malloc(sistema->qtdSecretarios * sizeof(tSecretario*));

    for (int i = 0; i < sistema->qtdSecretarios; ++i) {
        sistema->secretarios[i] = criaSecretarioLeitura();
        ler_secretario_de_binario(sistema->secretarios[i], arquivo);
    }

    sistema->listaDeLogins = (tLogin**)malloc(sistema->qtdLogins * sizeof(tLogin*));

    for (int i = 0; i < sistema->qtdLogins; ++i) {
        sistema->listaDeLogins[i] = criaLogin();
        ler_login_de_binario(sistema->listaDeLogins[i], arquivo);
    }
                printf("Quantidade de medicos:%d\n", sistema -> qtdMedicos);
        printf("Quantidade de secretarios:%d\n", sistema -> qtdSecretarios);
        printf("Quantidade de pacientes:%d\n", sistema -> qtdPacientes);
        printf("Quantidade de logins:%d\n", sistema -> qtdLogins);
        
    fclose(arquivo);
}