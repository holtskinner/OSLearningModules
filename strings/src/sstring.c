#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) {
  if (!str || length <= 0 || str[length - 1] != '\0') {
    return false;
  }

  return true;
}

char *string_duplicate(const char *str, const size_t length) {
  if (!str || length <= 0) {
    return NULL;
  }

  char *duplicate = calloc(length, sizeof(char));

  if (!strncpy(duplicate, str, length)) {
    return NULL;
  }

  return duplicate;
}

bool string_equal(const char *str_a, const char *str_b, const size_t length) {
  if (!str_a || !str_b || length <= 0) {
    return false;
  }

  if (strncmp(str_a, str_b, length) == 0) {
    return true;
  }
  return false;
}

int string_length(const char *str, const size_t length) {
  if (!str || length <= 0) {
    return -1;
  }

  return strlen(str);
}

int string_tokenize(const char *str, const char *delims,
                    const size_t str_length, char **tokens,
                    const size_t max_token_length,
                    const size_t requested_tokens) {
  if (!str || !delims || str_length <= 0 || !tokens || max_token_length <= 0 ||
      requested_tokens <= 0) {
    return 0;
  }

  return -1;
}

bool string_to_int(const char *str, int *converted_value) { return true; }
