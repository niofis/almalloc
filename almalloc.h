#pragma once

#include <stdlib.h>
#include <stdint.h>

void* aligned_malloc(int aligment_bytes, long size)
{
  void* ptr;
  void* aligned_ptr;
  int ptr_size;

  ptr_size = sizeof(uint64_t);

  ptr = malloc(aligment_bytes + size + ptr_size);
  aligned_ptr = ptr;
  aligned_ptr += ptr_size;
  aligned_ptr += (uint64_t)aligned_ptr % (uint64_t)aligment_bytes;

  //printf("offset %lx\n", (unsigned long)((long)aligned_ptr % (long)aligment_bytes));
  //printf("ptr_size %lx\n", (unsigned long) ptr_size);
  //printf("ptr %lx\n", (unsigned long)ptr);
  //printf("aligned_ptr %lx\n", (unsigned long)aligned_ptr);
  
  *((uint64_t*)aligned_ptr - 1) = (uint64_t)ptr;

  return aligned_ptr;

}

void aligned_free(void* aligned_memory)
{
  uint64_t* ptr;

  ptr = ((uint64_t*)aligned_memory - 1);

  ptr = (uint64_t*) *ptr;

  //printf("to be free %lx\n", (unsigned long)ptr);

  free(ptr);

}
