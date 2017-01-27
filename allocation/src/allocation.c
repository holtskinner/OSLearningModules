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
    ptr = (void*)malloc(member_size * nmember);
  }

  // return null if failed, ptr otherwise
  return !ptr ? NULL : ptr;
}

void* reallocate_array(void* ptr, size_t size) {
  if (size <= 0) {
    free(ptr);
    return NULL;
  }

  ptr = (void*)realloc(ptr, size);

  return !ptr ? NULL : ptr;
}

void deallocate_array(void** ptr) {
  if (!ptr || !*ptr) {
    return;
  }

  free(*ptr);
  *ptr = NULL;
  ptr = NULL;
  return;
}

char* read_line_to_buffer(char* filename) {
  if (!filename) {
    return NULL;
  }

  //   int file = open(filename, O_RDONLY);

  //   if (file < 0 || lseek(file, offset, 0) < 0 || read(file, dst, dst_size) <
  //   0) {
  //     close(file);
  //     return false;
  //   }

  //   close(file);

  // TODO try reading in one byte at a time and realloc

  return NULL;
}
