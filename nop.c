#include "monty.h"
/**
 * Function: f_nop
 * ----------------------------
 * Does nothing.
 *
 * @head: Pointer to the head of the stack (unused).
 * @counter: Line number where the operation is performed (unused).
 *
 * This function is a no-operation (NOP) that does not perform any actions.
 * It is used as a placeholder or for debugging purposes when an opcode
 * needs to be ignored without affecting the program flow.
 */

void f_nop(stack_t **head, unsigned int counter)
{
    (void)counter;
    (void)head;
}