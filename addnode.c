#include "monty.h"

/**
 * Function: addnode
 * ----------------------------
 * Adds a new node to the head of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @n: Value to be stored in the new node.
 *
 * This function allocates memory for a new node, initializes it with
 * the provided value, and inserts it at the beginning of the stack.
 * If memory allocation fails, it prints an error message to stderr
 * and exits with failure status. It also updates the previous pointer
 * of the existing head node if it exists. The head pointer is updated
 * to point to the newly added node.
 */

void addnode(stack_t **head, int n)
{
    /* Create a new node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = n;
    new_node->prev = NULL;

    /* Update pointers */
    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    new_node->next = *head;

    /* Update head pointer */
    *head = new_node;
}
