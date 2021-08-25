/**
 * Exemplo Geral basico para demonstrar a criacao de Threads.
 *
 * Obs: Embora funcione corretamente, esse exemplo nao 
 * utiliza corretamente a passagem de parametros.
 *
 * Prof. Andre Leon S. Gradvohl
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

void *printHello(void *threadid)
{
  long tid;

  tid = (long) threadid;
  printf("Ola Mundo! Sou o thread #%ld!\n", tid);

  pthread_exit((void *) tid);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  void *status;

  for (t = 0; t < NUM_THREADS; t++)
  {
    printf("Criando thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, printHello, (void *) t);

    if (rc)
    {
      printf("ERRO: retorno do pthread_create() e %d\n", rc);
      exit(-1);
    }
  }

  printf("Juntando as threads %ld\n", t);

  for (t = 0; t < NUM_THREADS; t++)
  {
    rc = pthread_join(threads[t], &status);

    if (rc)
    {
      printf("ERRO: retorno do pthread_join() e %d\n", rc);
      exit(-1);
    }
    printf("Retorno do thread %ld com status %ld\n", t, (long) status);
  }

  return 0;
}
