#include "../include/debug.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sort in increasing order
int comparator_func(const void *a, const void *b) {
  return *(uint8_t *)a - *(uint8_t *)b;
}

bool terrible_sort(uint16_t *data_array, const size_t value_count) {
  if (!data_array || value_count <= 0) {
    return false;
  }

  // got rid of the temp array, not needed

  // where the magic happens
  qsort(data_array, value_count, sizeof(uint16_t), comparator_func);

  for (size_t i = 1; i < value_count; ++i) {
    if (data_array[i] < data_array[i - 1]) {
      return false;
    }
  }
  return true;
}
