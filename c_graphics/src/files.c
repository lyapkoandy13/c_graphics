#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2) {
  char *result =
      malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator

  if (result == NULL) {
    perror("Could not malloc");
    return result;
  }

  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

char *readFile(const char *path) {
  FILE *file = NULL;
  file = fopen(path, "r");

  if (file == NULL) {
    char *errMsg = concat("Could not open a file ", path);
    if (errMsg != NULL) {
      perror(errMsg);
      free(errMsg);
    }
    perror("Could not open a file");
    exit(1);
  }

  size_t resultLen = 0, resultSize = 0;
  char *result = NULL, *tmp = NULL;

  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    size_t lineLen = strlen(line);

    // allocate memory if new line doesnt fit
    // -1 because we remove 1 of the \0
    if ((lineLen + resultLen - 1) > resultSize) {
      resultSize += sizeof(line);
      tmp = realloc(result, resultSize);

      if (tmp == NULL) {
        perror("Failed to realloc for final string while reading a file");
        break;
      }

      result = tmp;
    }

    strcat(result, line);
  }

  fclose(file);

  return result;
}
