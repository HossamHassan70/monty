#include "monty.h"

/**
 * Function: f_sub
 * ----------------------------
 * Subtracts the top element of the stack from the second top element.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function checks if the stack has at least two elements. If not, it prints an error message
 * to stderr and exits with failure status. If the stack has at least two elements, it calculates
 * the result of subtracting the top element from the second top element. It then removes the top
 * element from the stack and updates the value of the new top element with the subtraction result.
 * It ensures that memory is deallocated properly to avoid memory leaks.
 */

void f_sub(stack_t **head, unsigned int counter)
{
    // Check if stack has at least two elements
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    // Calculate the subtraction result
    int result = (*head)->next->n - (*head)->n;

    // Remove the top element and update the stack
    stack_t *temp = *head;
    *head = (*head)->next;
    free(temp);

    // Update the value of the new top element
    (*head)->n = result;
}
