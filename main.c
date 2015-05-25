#include <stdio.h>

#include "almalloc.h"

int main(int argc, char** args)
{

  void* al;

  al = aligned_malloc(16,1024);

  printf("ptr: %lx\n", (unsigned long)al);

  aligned_free(al);  


  return 0;
}
