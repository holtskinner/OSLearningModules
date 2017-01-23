#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) {
  if (!str || length <= 0) {
    return false;
  }
  size_t i = 0;
  for (i = 0; i < length; i++) {
    if (str[i] == '\0') {
      return true;
    }
  }
  return false;
}

char *string_duplicate(const char *str, const size_t length) {
  if (!str || length <= 0) {
    return NULL;
  }

  char *duplicate = calloc(length + 1, sizeof(char));

  size_t i = 0;
  for (i = 0; i < length; i++) {
    duplicate[i] = str[i];
  }
  duplicate[length] = '\0';
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
  return (!str || length <= 0) ? -1 : strlen(str);
}

int string_tokenize(const char *str, const char *delims,
                    const size_t str_length, char **tokens,
                    const size_t max_token_length,
                    const size_t requested_tokens) {
  if (!str || !delims || str_length <= 0 || !tokens || max_token_length <= 0 ||
      requested_tokens <= 0) {
    return 0;
  }

  int i = 0, j = 0, k = 0;
  for (i = 0; i < str_length; i++) {  // cycle through string

    if (k >= max_token_length) {
      return -1;
    }

    if (str[i] == delims[0]) {
      // tokens[j][k] = '\0';
      j++;
      k = 0;
    }

    if (j >= requested_tokens) {
      return -1;
    }

    // tokens[j][k] = str[i];
    k++;
  }
  return j;
}

bool string_to_int(const char *str, int *converted_value) {
  if (!str || !converted_value) {
    return false;
  }

  *converted_value = atoi(str);

  if (*converted_value == -1) {
    *converted_value = 0;
    return false;
  }

  return true;
}
