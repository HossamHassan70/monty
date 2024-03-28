#include "monty.h"

/**
 * Function: f_pint
 * ----------------------------
 * Prints the value at the top of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function checks if the stack is empty. If the stack is empty,
 * it prints an error message to stderr and exits with failure status.
 * If the stack is not empty, it prints the value at the top of the stack
 * followed by a newline character.
 */

void f_pint(stack_t **head, unsigned int counter)
{
    // Check if stack is empty
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        exit(EXIT_FAILURE);
    }

    // Print value at the top of the stack
    printf("%d\n", (*head)->n);
}
