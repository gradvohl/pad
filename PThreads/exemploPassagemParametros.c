/**
 * Exemplo de passagem de parametros para um thread.
 *
 * Prof. Andre Leon S. Gradvohl
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

/* Definicao de estrutura para conter os parametros a serem
 * enviados as threads.
 */
typedef struct
{
  int inicio;
  int fim;
} parametros;

/**
 * Thread que recebe parametros.
 */
void *somaParametros(void *args)
{
  /* Declaração do ponteiro p para receber os parametros
   * passados para a thread. 
   */
  parametros *p = (parametros *) args;
  int inicio, fim;

  /* Alocacao de variavel de retorno */
  int *retorno = (int *) malloc(sizeof(int));

  /* Transferencia de valores para variaveis internas da thread */
  inicio = p->inicio;
  fim = p->fim;

  printf("Id: %ld Inicio: %d fim: %d\n", pthread_self(), inicio, fim);
  *retorno = inicio + fim;

  /* Desalocacao dos argumentos passados para a thread.
   * CUIDADO, pois pode haver consequencias fora da thread.
   */
  free(args);

  /* Retorna o endereco de memoria que contem o resultado 
   * do processamento 
   */
  pthread_exit((void *) retorno);
}


int main(int argc, char *argv[])
{
  /*Vetor com os identificadores dos threads. */
  pthread_t threads[NUM_THREADS];

  /*Parametros a serem passados para os threads. */
  parametros *p;

  /*Ponteiro que armazenara o endereco de memoria
   *com o conteudo devolvido pelo thread 
   */
  void *retorno;
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++)
  {
    /* Declaracao e alocacao da estrutura que armazenara os parametros */
    p = (parametros *) malloc(sizeof(parametros));

    p->inicio = t;
    p->fim = t + 3;

    /* Criacao das threads, passando os parametros */
    rc = pthread_create(&threads[t], NULL, somaParametros, (void *) p);

    /* Verificacao de erros */
    if (rc)
    {
      printf("ERRO: retorno do pthread_create() e %d\n", rc);
      exit(EXIT_FAILURE);
    }
  }

  printf("Juntando as threads %ld\n", t);

  for (t = 0; t < NUM_THREADS; t++)
  {
    /* Aguardando a thread t terminar. 
     * O retorno ficara na variavel retorno.
     */
    rc = pthread_join(threads[t], &retorno);

    /* Verificacao de erros */
    if (rc)
    {
      printf("ERRO: retorno do pthread_join() e %d\n", rc);
      exit(EXIT_FAILURE);
    }

    /* Impressao do resultado que esta na variavel retorno.
     * Note a conversao de tipos.
     */
    printf("Retorno do thread %ld com status %d\n", t, *((int *) retorno));
  }

  return 0;
}
