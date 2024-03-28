#include "monty.h"

/**
 * Function: f_mul
 * ----------------------------
 * Multiplies the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function checks if the stack has at least two elements to perform multiplication.
 * If the stack is too short, it prints an error message to stderr and exits with failure status.
 * If the stack has at least two elements, it multiplies the top two elements and updates the
 * second top element with the result. It then removes the top element from the stack.
 */

void f_mul(stack_t **head, unsigned int counter)
{
    // Check if stack has at least two elements
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        exit(EXIT_FAILURE);
    }

    // Multiply the top two elements
    (*head)->next->n *= (*head)->n;

    // Remove top element
    f_pop(head, counter);
}
