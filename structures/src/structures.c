#include "../include/structures.h"
#include <stdio.h>

int compare_structs(sample_t* a, sample_t* b) {
  if (!a || !b) {
    return 0;
  }

  // check all fields for matches
  // these are all primitives, so == works
  if (a->a == b->a && a->b == b->b && a->c == b->c) {
    return 1;
  }
  return 0;
}

void print_alignments() {
  printf("Alignment of int is %zu bytes\n", __alignof__(int));
  printf("Alignment of double is %zu bytes\n", __alignof__(double));
  printf("Alignment of float is %zu bytes\n", __alignof__(float));
  printf("Alignment of char is %zu bytes\n", __alignof__(char));
  printf("Alignment of long long is %zu bytes\n", __alignof__(long long));
  printf("Alignment of short is %zu bytes\n", __alignof__(short));
  printf("Alignment of structs are %zu bytes\n", __alignof__(fruit_t));
}

int sort_fruit(const fruit_t* a, int* apples, int* oranges, const size_t size) {
  if (!a || !apples || !oranges || size <= 0) {
    return -1;
  }

  for (size_t i = 0; i < size; i++) {
    if (IS_APPLE(a + i)) {
      (*apples)++;
    } else if (IS_ORANGE(a + i)) {
      (*oranges)++;
    } else {
      // don't know how this would happen, but...
      return -1;
    }
  }
  return size;
}

int initialize_array(fruit_t* a, int apples, int oranges) {
  if (!a || apples < 0 || oranges < 0) {
    return -1;
  }

  int j = 0;  // super pointer to index in array a

  for (int i = 0; i < apples; i++) {
    if (initialize_apple((apple_t*)(a + j)) != 0) {
      return -1;
    }
    j++;
  }

  for (int i = 0; i < oranges; i++) {
    if (initialize_orange((orange_t*)(a + j)) != 0) {
      return -1;
    }
    j++;
  }

  return 0;
}

int initialize_orange(orange_t* a) {
  if (!a) {
    return -1;
  }

  a->type = ORANGE;
  a->weight = 0;
  a->peeled = 0;

  return 0;
}

int initialize_apple(apple_t* a) {
  if (!a) {
    return -1;
  }

  a->type = APPLE;
  a->weight = 0;
  a->worms = 0;

  return 0;
}
