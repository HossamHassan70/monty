#include "monty.h"

/**
 * Function: execute
 * ----------------------------
 * Executes the opcode specified in the given content.
 *
 * @content: Line content containing the opcode and arguments.
 * @stack: Pointer to the head of the stack.
 * @counter: Line number being executed.
 * @file: Pointer to the Monty file being processed.
 *
 * This function tokenizes the content to extract the opcode and argument (if any).
 * It then searches for the opcode in the instruction table and executes the corresponding function.
 * If the opcode is not found, it prints an error message to stderr and exits with failure status.
 * Comments (lines starting with '#') are ignored. Memory cleanup is performed before exiting.
 *
 * Returns: 0 if successful, 1 if opcode is not found.
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    unsigned int i = 0;
    /* Array of instruction opcodes and their corresponding functions */
    instruction_t opst[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };

    /* Tokenize content to extract opcode */
    char *op = strtok(content, " \n\t");
    if (op && op[0] == '#')  // Ignore comments
        return 0;

    /* Extract argument if any */
    bus.arg = strtok(NULL, " \n\t");

    /* Search for the opcode in the instruction table */
    while (opst[i].opcode && op)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            /* Execute the corresponding function */
            opst[i].f(stack, counter);
            return 0;  /* Successful execution */
        }
        i++;
    }

    /* If opcode is not found, print error message and exit */
    if (op && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;  /* Opcode not found */
}
