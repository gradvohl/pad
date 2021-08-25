/**
 * Exemplo simples para ilustrar os semaforos com threads.
 *
 * O programa cria varios threads para calcular a soma dos
 * elementos de um vetor e armazenar em uma variaval global.
 *
 * Prof. Andre Leon S. Gradvohl, Dr.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define TAMANHO  1000
#define NTHREADS 4

/* Estrutura que armazena os parametros para o threads*/
typedef struct
{
  unsigned int inicio;
  unsigned int fim;
  unsigned int tempoSono;
  double *vetor;
} parametros;

/* Variavel global com a soma total.*/
double somaTotal = 0;

/* Semaforo (variavel) global. */
sem_t mutex;

/**
 * Thread que soma os elementos de um vetor. O thread recebe
 * como parametros a posicao de inicial, a posicao final e
 * o vetor com os elementos a serem somados. Tambem recebe
 * como parametro o "tempo de sono", o tempo que a thread 
 * vai "dormir" apos o calculo da soma dos elementos.
 */
void *soma(void *args)
{
  unsigned int inicio = ((parametros *) args)->inicio;
  unsigned int fim = ((parametros *) args)->fim;
  unsigned int tempoSono = ((parametros *) args)->tempoSono;
  double *vetor = ((parametros *) args)->vetor;

  double somaParcial = 0;
  register int i;

  free(args);

  for (i = inicio; i <= fim; i++)
    somaParcial += vetor[i];

  sleep(tempoSono);

  sem_wait(&mutex);             // Inicio da regiao critica.

  somaTotal = somaTotal + somaParcial;

  sem_post(&mutex);             // Fim da regiao critica.

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  register int i;
  pthread_t threads[NTHREADS];
  double *vetor;
  parametros *p;

  /* Inicializacao do semaforo. */
  sem_init(&mutex, 0, 1);

  /* Criacao do vetor na memoria. */
  if ((vetor = (double *) malloc(sizeof(double) * TAMANHO)) == NULL)
  {
    fprintf(stderr, "Problemas na alocacao de memoria\n");
    exit(EXIT_FAILURE);
  }

  /* Preenchendo os elementos do vetor */
  for (i = 0; i < TAMANHO; i++)
    vetor[i] = i;

  /* Criando os threads, cada uma com seus parametros especificos */
  for (i = 0; i < NTHREADS; i++)
  {
    /* Alocacao da estrutura para armazenar os parametros na memoria. */
    if ((p = (parametros *) malloc(sizeof(parametros))) == NULL)
    {
      fprintf(stderr, "Problemas na alocacao de memoria\n");
      exit(EXIT_FAILURE);
    }

    /* Preenchimento dos campos na estrutura recem criada. */
    p->inicio = i * (TAMANHO / NTHREADS);
    p->fim = (i + 1) * (TAMANHO / NTHREADS) - 1;
    p->tempoSono = (rand() % NTHREADS);
    p->vetor = vetor;

    /* Instanciacao do thread */
    if (pthread_create(&threads[i], NULL, soma, (void *) p))
    {
      fprintf(stderr, "Problemas na instanciacao do thread.\n");
      exit(EXIT_FAILURE);
    }
  }

  /* Juntando os threads ao thread principal */
  for (i = 0; i < NTHREADS; i++)
  {
    if (pthread_join(threads[i], NULL))
    {
      fprintf(stderr, "Problemas na juncao do thread %d.\n", i);
      exit(EXIT_FAILURE);
    }
  }

  printf("A soma dos elementos do vetor e: %lf\n", somaTotal);

  /* Desalocacao do semaforo. */
  sem_destroy(&mutex);
  return 0;
}
