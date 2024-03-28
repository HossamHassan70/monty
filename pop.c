#include "monty.h"

/**
 * Function: f_pop
 * ----------------------------
 * Removes the top element of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function first checks if the stack is empty. If the stack is empty,
 * it prints an error message to stderr and exits with failure status.
 * If the stack is not empty, it removes the top element by updating the head
 * pointer to point to the next element in the stack, and then frees the memory
 * allocated for the removed element.
 */

void f_pop(stack_t **head, unsigned int counter)
{
    // Check if stack is empty
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        exit(EXIT_FAILURE);
    }

    // Remove the top element
    stack_t *temp = *head;
    *head = temp->next;
    free(temp);
}
