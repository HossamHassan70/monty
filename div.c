#include "monty.h"

/**
 * Function: f_div
 * ----------------------------
 * Divides the second element from the top of the stack by the top element.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function checks if the stack has at least two elements. If not,
 * it prints an error message to stderr and exits with failure status.
 * It also checks if the top element of the stack is zero, in which case
 * it prints an error message and exits with failure status to avoid
 * division by zero. If both conditions are met, it divides the second
 * element from the top of the stack by the top element, updates the
 * result in the second element, and removes the top element from the stack.
 */

void f_div(stack_t **head, unsigned int counter)
{
    // Check if stack has at least two elements
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        exit(EXIT_FAILURE);
    }

    // Check for division by zero
    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        exit(EXIT_FAILURE);
    }

    // Perform division
    (*head)->next->n /= (*head)->n;

    // Remove top element
    f_pop(head, counter);
}
