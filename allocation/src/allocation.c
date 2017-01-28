#include "../include/allocation.h"
#include <stdio.h>
#include <stdlib.h>

void* allocate_array(size_t member_size, size_t nmember, bool clear) {
  if (member_size <= 0 || nmember <= 0) {
    return NULL;
  }

  void* ptr = NULL;

  if (clear) {
    ptr = (void*)calloc(nmember, member_size);
  } else {
    ptr = (void*)malloc(nmember * member_size);
  }

  // ptr will be NULL if calloc or malloc failed
  return ptr;
}

void* reallocate_array(void* ptr, size_t size) {
  if (size <= 0) {
    return NULL;
  }

  ptr = (void*)realloc(ptr, size);

  return ptr;
}

void deallocate_array(void** ptr) {
  if (!ptr) {
    return;
  }

  free(*ptr);
  *ptr = NULL;
  return;
}

char* read_line_to_buffer(char* filename) {
  if (!filename) {
    return NULL;
  }

  // Hopefully this is okay, didn't figure out how t read one line with sys
  // calls
  FILE* f = fopen(filename, "r");

  if (!f) {
    fclose(f);  // just to be safe
    return NULL;
  }

  char* buf = NULL;  // buffer
  int i = 0;         // parameter for getline

  // getline should be in stdio
  if (0 > getline(&buf, &i, f)) {
    fclose(f);
    return NULL;
  }

  fclose(f);
  return buf;
}
