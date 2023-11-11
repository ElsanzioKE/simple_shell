#include "main.h"

/**
 * get_input - gets input from the command line
 * @void: no parameters
 * 
 * Return: A string containing the user input
 */
char *get_input(void)
{
    char *buffer = NULL;
    size_t n = 0;
    ssize_t input;

    if (isatty(STDIN_FILENO))
    {
        input = getline(&buffer, &n, stdin);

        if (input > 0 && buffer[input - 1] == '\n')
            buffer[input - 1] = '\0';
    }
    else
    {
        size_t max_buffer_size = MAX_BUFFER_SIZE;
        size_t total_size = 0;

        while (1)
        {
            if (total_size >= max_buffer_size - 1)
            {
                max_buffer_size *= 2;
                buffer = realloc(buffer, max_buffer_size);
                if (buffer == NULL)
                {
                    perror("get_input");
                    exit(EXIT_FAILURE);
                }
            }

            input = read(STDIN_FILENO, buffer + total_size, 1);

            if (input == -1)
            {
                perror("get_input");
                exit(EXIT_FAILURE);
            }

            if (input == 0 || buffer[total_size] == '\n')
            {
                buffer[total_size] = '\0';
                break;
            }

            total_size++;
        }
    }

    if (input == -1 && errno == EOF)
    {
        free(buffer);
        return NULL;
    }

    return buffer;
}

