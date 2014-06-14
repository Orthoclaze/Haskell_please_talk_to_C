#include <HsFFI.h>
#ifdef __GLASGOW_HASKELL__
#include "Safe_stub.h"
extern void __stginit_Safe(void);
#endif
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    hs_init(&argc, &argv);
#ifdef __GLASGOW_HASKELL__
    hs_add_root(__stginit_Safe);
#endif

  int i,n;
  i=30;
  char * olga;
  char * molta;
  char * result;

  olga = (char*) malloc (i+1);
  molta = (char*) malloc (i+1);
  result = (char*) malloc (2*i+1);
   
  for (n=0; n<i; n++) {
    olga[n]=rand()%26+'a';
    molta[n]=rand()%26+'a';
  }
  olga[i]='\0'; 
  molta[i]='\0'; 

  printf ("olga: %s\n",olga);
  printf ("molta: %s\n",molta);

  printf ("olga: %p\n",olga);
  printf ("molta: %p\n",molta);


    int x = fibonacci_hs(olga,molta,result);

    printf("b\n");

    printf("Fibonacci: %s\n", *result);
    hs_exit();

    free(olga);
    free(molta);
    free(result);

    return 0;
}
