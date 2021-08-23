/**
 * Este programa ilusta a medicao de tempo fisico (wall clock time)
 * de um trecho de codigo.
 *
 * Autor: Andre Leon S. Gradvoh, Dr.
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Função para gerar um número real psuedo-aleatório entre mínimo and maximo.
 * @param min Valor mínimo.
 * @param max Valor máximo.
 * @return Número real aleatório.
 */ 
double randDouble(double min, double max) 
{ 
    if (min>max) 
        return (rand()/((double)(RAND_MAX)+1))*(min-max)+max;     
    else 
        return (rand()/((double)(RAND_MAX)+1))*(max-min)+min; 
}
 
int main()
{
  // Variaveis necessarias para contabilizar o tempo
  clock_t inicio; // Armazena o horario de inicio
  clock_t fim;    // Armazena o horario de fim
  double tempoProcessamento;

  // Vetores usados para realizar algum processamento
  double *vet1, *vet2, *soma;
  const unsigned int tamanho = 1000000;

  register unsigned int i;

  // Obtendo o horario de inicio (atual).
  inicio = clock();

  // Criando e executanco operacoes com os vetores
  vet1 = (double *) malloc (sizeof(double)*tamanho);

  vet2 = (double *) malloc (sizeof(double)*tamanho);

  soma = (double *) malloc (sizeof(double)*tamanho);

  for (i=0; i<tamanho; i++)
  {
    vet1[i] = randDouble(0, 10);
    vet2[i] = randDouble(0, 10);
    soma[i] = vet1[i] + vet2[i];
  }

  // Removendo os vetores da memoria
  free(vet1);
  free(vet2);
  free(soma);

  // Obtendo o horario de fim (atual).
  fim = clock();

  // Calcula o tempo gasto em segundos e microssegundos.
  tempoProcessamento = (double)(fim - inicio) / CLOCKS_PER_SEC;

  // imprime o resultado
  printf("As operacoes com vetores levaram %lf segundos para executar\n", tempoProcessamento);
  return 0;
}
