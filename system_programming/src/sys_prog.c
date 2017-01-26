#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/sys_prog.h"

// LOOK INTO OPEN, READ, WRITE, CLOSE, FSTAT/STAT, LSEEK
// GOOGLE FOR ENDIANESS HELP
// NOTE THE FILE I/O MUST USE OPEN, READ, WRITE, CLOSE, SEEK, STAT with file
// descriptors (NO FILE*)
// Make sure to uint8_t or uint32_t, you are dealing with system dependent sizes

bool bulk_read(const char *input_filename, void *dst, const size_t offset,
               const size_t dst_size) {
  if (!input_filename || !dst || offset < 0 || dst_size <= 0) {
    return false;
  }

  int file = open(input_filename, O_RDONLY);

  if (file < 0 || lseek(file, offset, SEEK_SET) < 0 ||
      read(file, dst, dst_size) < 0) {
    close(file);
    return false;
  }

  close(file);
  return true;
}

bool bulk_write(const void *src, const char *output_filename,
                const size_t offset, const size_t src_size) {
  if (!src || !output_filename || offset < 0 || src_size <= 0) {
    return false;
  }

  int file = open(output_filename, O_WRONLY);

  if (file < 0 || lseek(file, offset, SEEK_SET) < 0 ||
      write(file, src, src_size) < 0) {
    close(file);
    return false;
  }

  close(file);
  return true;
}

bool file_stat(const char *query_filename, struct stat *metadata) {
  if (stat(query_filename, metadata) < 0) {
    return false;
  }
  return true;
}

bool endianess_converter(uint32_t *src_data, uint32_t *dst_data,
                         const size_t src_count) {
  if (!src_data || !dst_data || src_count <= 0) {
    return false;
  }

  int i = 0;
  for (i = 0; i < src_count; i++) {
    dst_data[i] = htonl(src_data[i]);
  }

  return true;
}
