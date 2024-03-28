#include "monty.h"

/**
 * Function: f_swap
 * ----------------------------
 * Swaps the top two elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function checks if the stack has at least two elements. If not, it prints an error message
 * to stderr and exits with failure status. If the stack has at least two elements, it swaps the values
 * of the top two elements. It ensures that memory is deallocated properly to avoid memory leaks.
 */

void f_swap(stack_t **head, unsigned int counter)
{
    // Check if stack has at least two elements
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    // Swap the values of the top two elements
    int temp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = temp;
}
