#pragma once

#include <stdlib.h>

void* aligned_malloc(int aligment_bytes, long size)
{
  void* ptr;
  void* aligned_ptr;
  int ptr_size;

  ptr_size = sizeof(long);

  ptr = malloc(aligment_bytes + size + ptr_size);
  aligned_ptr = ptr;
  aligned_ptr += ptr_size;
  aligned_ptr += (long)aligned_ptr % (long)aligment_bytes;

  //printf("offset %lx\n", (unsigned long)((long)aligned_ptr % (long)aligment_bytes));
  //printf("ptr_size %lx\n", (unsigned long) ptr_size);
  //printf("ptr %lx\n", (unsigned long)ptr);
  //printf("aligned_ptr %lx\n", (unsigned long)aligned_ptr);
  
  *(long*)(aligned_ptr - ptr_size) = (long)ptr;

  return aligned_ptr;

}

void aligned_free(void* aligned_memory)
{
  int ptr_size = sizeof(long);
  long* ptr;

  ptr = (long*)(aligned_memory - ptr_size);

  ptr =(long*) *ptr;

  //printf("to be free %lx\n", (unsigned long)ptr);

  free(ptr);

}
