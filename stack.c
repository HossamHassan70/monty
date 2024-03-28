#include "monty.h"

/**
 * Function: f_stack
 * ----------------------------
 * Sets the stack mode to LIFO (stack).
 *
 * @head: Pointer to the head of the stack (unused).
 * @counter: Line number where the operation is performed (unused).
 *
 * This function sets the stack mode to LIFO (stack) by updating the global variable `bus.lifi` to 0.
 * It does not perform any operations on the stack itself.
 */

void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 0;
}