#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/error_handling.h"

int create_blank_records(Record_t **records, const size_t num_records) {
  if (!records || *records || num_records <= 0) {
    return -1;
  }

  *records = (Record_t *)malloc(sizeof(Record_t) * num_records);

  if (!(*records)) {
    return -2;
  }

  memset(*records, 0, sizeof(Record_t) * num_records);

  return 0;
}

int read_records(const char *input_filename, Record_t *records,
                 const size_t num_records) {
  if (!input_filename || !records || num_records <= 0) {
    return -1;
  }

  if (num_records >= 200) {
    return -3;
  }

  int fd = open(input_filename, O_RDONLY);

  if (fd == -1) {
    close(fd);
    return -2;
  }

  ssize_t data_read = 0;
  for (size_t i = 0; i < num_records; i++) {
    data_read = read(fd, &records[i], sizeof(Record_t));
    if (data_read < 0) {
      close(fd);
      return -3;
    }
  }

  close(fd);
  return 0;
}

int create_record(Record_t **new_record, const char *name, int age) {
  if (!new_record || !name || age <= 0 || age > 200 || name[0] == '\n' ||
      strlen(name) > MAX_NAME_LEN - 1) {
    return -1;
  }

  *new_record = (Record_t *)calloc(1, sizeof(Record_t));

  if (!(*new_record)) {
    return -2;
  }

  if (!memcpy((*new_record)->name, name, sizeof(char) * strlen(name))) {
    return -2;
  }

  (*new_record)->name[MAX_NAME_LEN - 1] = '\0';
  (*new_record)->age = age;
  return 0;
}
