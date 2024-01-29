#include "stdio.h"
#include <stdlib.h>

void shader()
{
    FILE *file;
    char *buffer = NULL;
    size_t buffer_size = 0;

    // Open the file in read mode
    file = fopen("src/shaders/phong.vert", "r");

    if (file == NULL)
    {
        perror("Error opening file");
    }

    // Read the file content
    while (getline(&buffer, &buffer_size, file) != -1)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    // Free the dynamically allocated memory
    free(buffer);
}