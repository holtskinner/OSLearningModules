#include "../include/bitmap.h"
#include <math.h>
// data is an array of uint8_t and needs to be allocated in bitmap_create and
// used in the remaining bitmap functions. You will use data for any bit
// operations and bit logic
// bit_count the number of requested bits, set in bitmap_create from n_bits
// byte_count the total number of bytes the data contains, set in bitmap_create

bitmap_t *bitmap_create(size_t n_bits) {
  if (n_bits <= 0) {
    return NULL;
  }

  bitmap_t *bitmap = calloc(n_bits, sizeof(bitmap_t));

  if (!bitmap) {
    free(bitmap);
    bitmap = NULL;
    return NULL;
  }

  bitmap->data = calloc(n_bits, sizeof(uint8_t));
  bitmap->bit_count = n_bits;
  bitmap->byte_count = ceil(n_bits / 8.0);  // convert bits to bytes

  return bitmap;
}

bool bitmap_set(bitmap_t *const bitmap, const size_t bit) {
  if (!bitmap || bit < 0 || bit > bitmap->bit_count) {
    return false;
  }

  bitmap->data[bit / 8] |= 1 << (bit % 8);
  return true;
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit) {
  if (!bitmap || bit < 0 || bit > bitmap->bit_count) {
    return false;
  }

  bitmap->data[bit / 8] &= ~(1 << (bit % 8));
  return true;
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit) {
  if (!bitmap || bit < 0 || bit > bitmap->bit_count) {
    return false;
  }

  if (bitmap->data[bit / 8] & (1 << (bit % 8))) {
    return true;  // bit is 1
  } else {
    return false;  // bit is zero
  }
}

size_t bitmap_ffs(const bitmap_t *const bitmap) {
  if (!bitmap) {
    return SIZE_MAX;
  }

  size_t i = 0;
  for (i = 0; i < bitmap->bit_count; i++) {
    if (bitmap_test(bitmap, i)) {
      return i;
    }
  }

  return SIZE_MAX;
}

size_t bitmap_ffz(const bitmap_t *const bitmap) {
  if (!bitmap) {
    return SIZE_MAX;
  }

  size_t i = 0;
  for (i = 0; i < bitmap->bit_count; i++) {
    if (!bitmap_test(bitmap, i)) {
      return i;
    }
  }

  return SIZE_MAX;
}

bool bitmap_destroy(bitmap_t *bitmap) {
  if (!bitmap || !bitmap->data) {
    return false;
  }

  free(bitmap->data);
  bitmap->data = NULL;

  free(bitmap);
  bitmap = NULL;

  if (bitmap) {
    return false;
  }
  return true;
}
