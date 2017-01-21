#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

bool array_copy(const void *src, void *dst, const size_t elem_size,
                const size_t elem_count) {
  // sanity check
  if (!src || !dst || elem_size == 0 || elem_count == 0) {
    return false;
  }
  // copy memory and check for NULL
  if (!memcpy(dst, src, (elem_size * elem_count))) {
    return false;
  }
  return true;
}

bool array_is_equal(const void *data_one, void *data_two,
                    const size_t elem_size, const size_t elem_count) {
  // sanity check
  if (!data_one || !data_two || elem_size == 0 || elem_count == 0) {
    return false;
  }

  // memcmp returns 0 if memory is equal
  if (memcmp(data_one, data_two, (elem_size * elem_count)) == 0) {
    return true;
  }

  return false;
}

bool array_serialize(const void *src_data, const char *dst_file,
                     const size_t elem_size, const size_t elem_count) {
  // sanity check
  if (!src_data || !dst_file || dst_file == "" || isspace(dst_file) ||
      elem_size == 0 || elem_count == 0) {
    return false;
  }

  // open file for writing in binary
  FILE *fp = fopen(dst_file, "wb");

  if (!fp) {
    fclose(fp);
    return false;
  }

  // fwrite returns the number of elements written (should be the same as
  // elem_count)
  if (elem_count != fwrite(src_data, elem_size, elem_count, fp)) {
    fclose(fp);
    return false;
  }

  fclose(fp);
  return true;
}

bool array_deserialize(const char *src_file, void *dst_data,
                       const size_t elem_size, const size_t elem_count) {
  return false;
}

ssize_t array_locate(const void *data, const void *target,
                     const size_t elem_size, const size_t elem_count) {
  return 0;
}
