#include "monty.h"

/**
 * Function: f_pchar
 * ----------------------------
 * Prints the character at the top of the stack, followed by a newline.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function first checks if the stack is empty. If the stack is empty,
 * it prints an error message to stderr and exits with failure status.
 * Then, it checks if the value at the top of the stack is within the printable
 * ASCII range (0 to 127). If the value is outside this range, it prints an error
 * message to stderr and exits with failure status.
 * If both conditions are met, it prints the character corresponding to the value
 * at the top of the stack, followed by a newline character.
 */

void f_pchar(stack_t **head, unsigned int counter)
{
    /* Check if stack is empty */
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        exit(EXIT_FAILURE);
    }

    /* Check if value is within printable ASCII range */
    if ((*head)->n < 0 || (*head)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        exit(EXIT_FAILURE);
    }

    /* Print character at the top of the stack */
    printf("%c\n", (*head)->n);
}
