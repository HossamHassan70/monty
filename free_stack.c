#include "monty.h"

/**
 * Function: free_stack
 * ----------------------------
 * Frees a doubly linked list starting from the specified head node.
 *
 * head: Pointer to the head of the doubly linked list.
 *
 * This function traverses the doubly linked list starting from the specified head node,
 * freeing each node iteratively. It keeps track of the next node before freeing the current
 * node to prevent losing reference. After freeing all nodes, the function ensures that the
 * head pointer is set to NULL to indicate an empty list.
 */

void free_stack(stack_t *head)
{
    /* Traverse the list and free each node */
    while (head != NULL)
    {
        /* Keep track of the next node to prevent losing reference */
        stack_t *next_node = head->next;

        /* Free the current node */
        free(head);

        /* Move to the next node */
        head = next_node;
    }
}
