#include "monty.h"

/**
 * Function: f_add
 * ----------------------------
 * Adds the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function checks if the stack has at least two elements,
 * adds the values of the top two elements, updates the second
 * element with the sum, and removes the top element from the stack.
 * If the stack doesn't have enough elements, it prints an error
 * message and exits with failure.
 */

void f_add(stack_t **head, unsigned int counter)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        exit(EXIT_FAILURE);
    }

    (*head)->next->n += (*head)->n;
    f_pop(head, counter);
}
