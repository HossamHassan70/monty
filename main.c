#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * Function: main
 * ----------------------------
 * Entry point of the Monty bytecode interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Returns: 0 on successful execution.
 */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    unsigned int line_number = 0;
    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;

        // Remove trailing newline if present
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        if (execute(line, &stack, line_number, file) == EXIT_FAILURE)
        {
            // Handle execution failure
            fclose(file);
            free(line);
            free_stack(stack);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    free(line);
    free_stack(stack);
    return EXIT_SUCCESS;
}
