#include "../include/debug.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// protected function, that only this .c can use
int comparator_func(const void *a, const void *b) {
  return (uint8_t *)a - (uint8_t *)b;
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) {
  if (!data_array || value_count <= 0) {
    return false;
  }

  qsort(data_array, value_count, sizeof(uint16_t), comparator_func);

  return true;
}
