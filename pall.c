#include "monty.h"

/**
 * Function: f_pall
 * ----------------------------
 * Prints all elements of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed (unused).
 *
 * This function traverses the stack starting from the head node and prints the value of each element.
 * It uses a loop to iterate over the stack and print each element sequentially.
 * If the stack is empty, the function returns without performing any action.
 * The counter parameter is unused and included for compatibility with the opcode function pointer signature.
 */

void f_pall(stack_t **head, unsigned int counter)
{
    // Prevent unused variable warning
    (void)counter;

    // Traverse the stack and print each element
    for (stack_t *current = *head; current != NULL; current = current->next)
    {
        printf("%d\n", current->n);
    }
}
