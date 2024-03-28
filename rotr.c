#include "monty.h"

/**
 * Function: f_rotr
 * ----------------------------
 * Rotates the stack to the bottom.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed (unused).
 *
 * This function rotates the stack by moving the last node to the front, effectively
 * shifting all elements down by one position. If the stack is empty or has only one element,
 * it does nothing. It ensures that the connections between nodes are updated correctly to
 * maintain the doubly linked list structure.
 */

void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
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

    // Rotate the stack by moving the last node to the front
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *head;
    (*head)->prev = last;
    *head = last;
}
