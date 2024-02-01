#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *readFile(const char *path)
{
    FILE *file = NULL;
    file = fopen(path, "r");

    if (file == NULL)
    {
        perror("Could not open a file");
    }

    size_t resultLen = 0, resultSize = 0;
    char *result = NULL, *tmp = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file))
    {
        size_t lineLen = strlen(line);

        // allocate memory if new line doesnt fit
        // -1 because we remove 1 of the \0
        if ((lineLen + resultLen - 1) > resultSize)
        {
            resultSize += sizeof(line);
            tmp = realloc(result, resultSize);

            if (tmp == NULL)
            {
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
