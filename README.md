# Mini-SADE — sistema de atendimento em C

Projeto acadêmico de terminal para simular o atendimento de uma clínica, com cadastro de pessoas, consultas dermatológicas, geração de documentos e fila de impressão. A implementação de Gabriel de Albuquerque está em [Respostas/Gabriel](Respostas/Gabriel).

O trabalho exercita tipos abstratos de dados, alocação dinâmica, callbacks e persistência em arquivos. O código original e os materiais de correção foram preservados como registro da disciplina de Programação II da UFES.

## Funcionalidades

- Cadastro de secretários, médicos e pacientes, com login e níveis de acesso no menu.
- Registro de consultas e lesões, incluindo indicação de cirurgia e crioterapia.
- Busca de pacientes e relatório geral do atendimento.
- Emissão de receitas, solicitações de biópsia e encaminhamentos.
- Fila de documentos com impressão no terminal e em arquivos de texto.
- Gravação e leitura do estado em `sistema.bin`.

## Organização e arquitetura

| Caminho | Responsabilidade |
| --- | --- |
| [main.c](Respostas/Gabriel/main.c) e [tSistema.c](Respostas/Gabriel/tSistema.c) | Entrada, menus, coordenação do atendimento e persistência do sistema. |
| [tPessoa.c](Respostas/Gabriel/tPessoa.c), [tPaciente.c](Respostas/Gabriel/tPaciente.c), [tMedico.c](Respostas/Gabriel/tMedico.c) e [tSecretario.c](Respostas/Gabriel/tSecretario.c) | Dados pessoais e entidades do domínio. |
| [tConsulta.c](Respostas/Gabriel/tConsulta.c) e [tLesao.c](Respostas/Gabriel/tLesao.c) | Informações de atendimento e lesões. |
| [tDocumento.h](Respostas/Gabriel/tDocumento.h) e [tFila.h](Respostas/Gabriel/tFila.h) | Documento genérico com callbacks de impressão/desalocação e fila de documentos heterogêneos. |
| [Casos](Casos) | Entradas e saídas de referência do material acadêmico. |
| [Includes](Includes), [Gabarito-obj](Gabarito-obj) e [correcao.sh](correcao.sh) | Interfaces, artefatos de referência e infraestrutura de correção da disciplina. |
| [Resultados](Resultados) e [Resultado.csv](Resultado.csv) | Registros históricos de correção; não equivalem a uma validação atual. |

O fluxo parte do terminal, passa por `tSistema` e pelas entidades de atendimento e encaminha documentos à fila. `tDocumento` associa um dado genérico a funções de impressão e liberação, permitindo tratar tipos diferentes pela mesma interface em C.

## Compilar e executar

Requisitos: ambiente Linux ou WSL, GCC e biblioteca padrão C. A compilação utiliza a biblioteca matemática (`-lm`); não há dependências a baixar.

Na raiz do repositório:

```bash
gcc -Wall Respostas/Gabriel/*.c -lm -o /tmp/mini-sade
```

Execute em um diretório separado para manter os arquivos gerados fora dos materiais originais:

```bash
workdir=$(mktemp -d /tmp/mini-sade-demo.XXXXXX)
cd "$workdir"
mkdir -p saida
/tmp/mini-sade .
```

O argumento `.` indica o diretório usado pelo sistema. Na primeira pergunta, informe `./` como caminho do banco: nessa configuração, o arquivo será `./sistema.bin`. A pasta `saida` recebe os documentos impressos.

No primeiro uso, cadastre um secretário com dados fictícios, login, senha e nível `ADMIN`. Entre com essas credenciais e use o menu para cadastrar pacientes, registrar consultas e imprimir documentos. A opção `8` grava o estado e encerra o programa. Para reabrir os dados, execute novamente no mesmo diretório e informe o mesmo caminho do banco.

## Correção acadêmica e limites

O repositório deriva do template do Trabalho Prático 2 — Etapa 1 de Programação II. As instruções gerais originais estão no [repositório da disciplina](https://github.com/prog-II-ufes/exercicios-gerais); a descrição completa foi distribuída pelo Classroom.

O [script de correção](correcao.sh) foi mantido, mas recria resultados e altera arquivos de log. Seu modo de comparação por módulos espera objetos `.o` de referência, enquanto este snapshot contém apenas o executável em `Gabarito-obj`. Para estudar o programa, use a compilação direta acima; para reproduzir a correção, obtenha primeiro os materiais compatíveis da disciplina e trabalhe em uma cópia.

Esta é uma implementação acadêmica, com mensagens de depuração e limitações de validação de entrada e autenticação. Use somente dados fictícios: o código pode exibir credenciais no terminal e a persistência binária não é criptografada nem tem formato portátil entre versões/arquiteturas. O cálculo de idade em `tPessoa.c` usa a data fixa de referência `09/11/2023`.

A opção de encerramento retorna código `1` no código original, mesmo após salvar o estado. Compilar e percorrer um cadastro simples não demonstra a correção de todos os fluxos nem substitui os casos da disciplina.

## Créditos

Implementação em [Respostas/Gabriel](Respostas/Gabriel): **Gabriel de Albuquerque**. Template, interfaces, casos e infraestrutura de avaliação têm origem no material de Programação II da UFES; suas referências e arquivos originais permanecem no repositório.
