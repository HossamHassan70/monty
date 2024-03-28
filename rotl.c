#include "monty.h"

/**
 * Function: f_rotl
 * ----------------------------
 * Rotates the stack to the top.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed (unused).
 *
 * This function rotates the stack by moving the head node to the end of the stack.
 * If the stack is empty or has only one element, it does nothing.
 * It ensures that the connections between nodes are updated correctly to maintain
 * the doubly linked list structure.
 */

void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    // Check if stack is empty or has only one element
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    // Traverse to the last node of the stack
    stack_t *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Rotate the stack by moving the head node to the end
    last->next = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    last->next->next = NULL;
    last->next->prev = last;
}
