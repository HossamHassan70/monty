#include "monty.h"

/**
 * Function: f_mod
 * ----------------------------
 * Computes the rest of the division of the second top element of the stack by the top element of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function first checks if the stack has at least two elements to perform the modulo operation.
 * If the stack is too short, it prints an error message to stderr and exits with failure status.
 * Additionally, it checks if the top element of the stack is zero to avoid division by zero.
 * If the divisor is zero, it prints an error message and exits with failure status.
 * If both conditions are met, it computes the rest of the division and updates the second top element
 * with the result. It then removes the top element from the stack.
 */

void f_mod(stack_t **head, unsigned int counter)
{
    /* Check if stack has at least two elements */
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
        exit(EXIT_FAILURE);
    }

    /* Check for division by zero */
    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        exit(EXIT_FAILURE);
    }

    /* Compute the rest of division */
    (*head)->next->n %= (*head)->n;

    /* Remove top element */
    f_pop(head, counter);
}
