#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE
// Copy the contents from source array into destination array
// \param src the array the will be copied into the destination array
// \param dst the array that will be copied from the source array
// \param elem_size the number of bytes each array element uses
// \param elem_count the number of elements in the source array
// return true if operation was successful, else false
bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count) {
    if (!src || !dst || elem_size == 0 || elem_count == 0) {
        return false;
    }
    if (!memcpy(dst, src, (elem_size * elem_count))) {
        return false;
    }
    return true;
}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count) {
    if (!data_one || !data_two || elem_size == 0 || elem_count == 0) {
        return false;
    }

    int result = memcmp(data_one, data_two, (elem_size * elem_count));

    if (result == 0) {
        return true;
    }
    return false;
}

ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count) {

    return 0;
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count) {

    return false;
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count) {

    return false;
}
