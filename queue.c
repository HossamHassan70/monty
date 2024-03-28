#include "monty.h"

/**
 * Function: f_queue
 * ----------------------------
 * Sets the stack mode to FIFO (queue).
 *
 * @head: Pointer to the head of the stack (unused).
 * @counter: Line number where the operation is performed (unused).
 *
 * This function sets the stack mode to FIFO (queue) by updating the global variable `bus.lifi` to 1.
 * It does not perform any operations on the stack itself.
 */
void f_queue(stack_t **head, unsigned int counter)
{
    /* Prevent unused variable warnings */
    (void)head;
    (void)counter;

    /* Set stack mode to FIFO (queue) */
    bus.lifi = 1;
}

/**
 * Function: addqueue
 * ----------------------------
 * Adds a new node to the tail of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @n: Value to be added.
 *
 * This function allocates memory for a new node and initializes it with the given value.
 * If the stack is empty, the new node becomes the head of the stack.
 * If the stack is not empty, the new node is appended to the tail of the stack.
 * It ensures that the connections between nodes are updated correctly.
 */
void addqueue(stack_t **head, int n)
{
    stack_t *tail = *head;    /* Allocate memory for new node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        return;
    }

    /* Initialize new node */
    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    /* If stack is empty, set new node as head */
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    /* Traverse the stack to find the tail */
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    /* Append new node to the tail */
    tail->next = new_node;
    new_node->prev = tail;
}
