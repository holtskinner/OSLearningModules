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
  // temp array
  uint16_t *sorting_array = (uint16_t *)malloc(value_count * sizeof(uint16_t));

  if (!sorting_array) {
    return false;
  }

  size_t i = 0;
  for (i = 0; i < value_count; ++i) {
    sorting_array[i] = data_array[i];
  }
  // where the magic happens
  qsort(sorting_array, value_count, sizeof(uint16_t), comparator_func);

  // check that the array is in increasing order
  for (i = 1; i < value_count; ++i) {
    if (sorting_array[i] < sorting_array[i - 1]) {
      return false;
    }
  }
  // copy temp array into original
  memcpy(data_array, sorting_array, value_count * sizeof(uint16_t));
  free(sorting_array);
  return true;
}
