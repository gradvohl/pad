# Informações sobre os tarefas de programação para a disciplina Processamento de Alto Desempenho 
Este é o repositório padrão para a disciplina Processamento de Alto Desempenho (FT077), oferecida no programa de pós-graduação da [Faculdade de Tecnologia](http://www.ft.unicamp.br) da [UNICAMP](http://www.unicamp.br). Nesse repositório estão as informações gerais sobre os tarefas de programação a serem desenvolvidas na disciplina e alguns códigos fonte básicos que os estudantes podem usar nessas tarefas, se desejarem.

Os estudantes podem utilizar esse repositório como base para seus próprios repositórios da disciplina. No entanto, **é muito importante** que os estudantes adaptem/ajustem a estrutura desse repositório para seus trabalhos específicos.

## Estrutura do repositório
O repositório está dividido em quatro diretórios principais:
- :file_folder: PThreads: diretório com exemplos sobre PThreads.
- :file_folder: OpenMP: diretório com exemplos sobre OpenMP.
- :file_folder: OpenACC: diretório com exemplos sobre OpenACC.
- :file_folder: MPI: diretório com exemplos sobre MPI.

Além dos diretórios principais, há outros dois diretórios auxiliares descritos a seguir:
- :file_folder: aux: arquivos e programas auxiliares.
- :file_folder: exemplos: alguns arquivos e programas exemplos para ajudar aos alunos.

Sugere-se que, em cada diretório para uma biblioteca específica, haja os seguintes diretórios:
- :file_folder: src: com o código fonte do laboratório.
- :file_folder: bin: com o código objeto gerado a partir do código fonte do laboratório.

## Informações gerais sobre os tarefas de programação
Os estudantes matriculados na disciplina Processamento de Alto Desempenho deverão realizar, **individualmente**, três tarefas de programação. As tarefas estão descritas em arquivos específicos.

* A primeira tarefa envolve a programação com a biblioteca POSIX Threads e está descrita em [Projeto 1](Projeto1.md);
* A segunda tarefa envolve a programação com a biblioteca OpenMP e está descrita em [Projeto 2](Projeto2.md);
* A terceira tarefa envolve a programação com a biblioteca OpenACC e está descrita em [Projeto 3](Projeto3.md); 
* A última tarefa envolve a programação com a biblioteca MPI e está descrita em [Projeto 4](Projeto4.md); 

### Entrega dos relatórios das tarefas 
Para cada uma das tarefas, o estudante deverá produzir um relatório com o resultado da tarefa. O relatório deve ser publicado no Ambiente Virtual de Aprendizagem -- Moodle, em até uma semana (7 dias) após a última aula sobre a biblioteca específica que a tarefa de programação usuará.

Além do envio pelo Moodle, o relatório **também** deverá estar disponível no próprio repositório do estudante, no diretório da biblioteca a que aquele relatório se refere.

### Detalhamento dos produtos do projeto
Os produtos que devem ser entregues como resultado do projeto são os seguintes:
1. O código fonte do programa completo, documentado e pronto para ser compilado em sistemas Linux.
2. Um relatório contendo a descrição da solução do problema (algoritmo em alto nível); gráficos com os tempos de execução do programa; e as conclusões a respeito dos resultados obtidos.

Para o item (1), a sugestão é a utilização de um `Makefile` que facilite a compilação em sistemas Linux/Unix. 

Para o item (2), o relatório deve estar no formato PDF ou disponível no próprio servidor Git usando um arquivo na sintaxe Markdown. Outros formatos não serão aceitos.

**Observação**: Ao medir o tempo de processamento, desconsidere o tempo utilizado nas operações de entrada/saída de dados (I/O). Como sugestão, utilize como base o trecho de código a seguir:
```c
#include <time.h>

...

/* Entrada  dos dados */

...

clock_t inicio = clock();

/* Processsamento dos dados*/

clock_t fim = clock();

double tempoProc = (double)(fim - inicio) / CLOCKS_PER_SEC;
...
```

A falta de qualquer um dos itens acarretará em nota zero nesse componente de avaliação.

## Informações complementares
No _site_/repositório [Aloca Matrizes](https://gradvohl.github.io/alocaMatrizes) (https://gradvohl.github.io/alocaMatrizes), há uma discussão a respeito da alocação de matrizes na memória (como um vetor). :point_right: **Recomenda-se a leitura!** :point_left:

### Plágio
:no_entry_sign: _**O plágio é condenável!**_: Qualquer forma de plágio, independentemente da quantidade de linhas, acarretará em zero no item de avaliação em que foi detectado o plágio para todos os envolvidos, sem distinção entre plagiador e plagiado.
