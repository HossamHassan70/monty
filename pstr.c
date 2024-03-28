#include "monty.h"

/**
 * Function: f_pstr
 * ----------------------------
 * Prints the string starting at the top of the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed (unused).
 *
 * This function traverses the stack starting from the top and prints characters
 * until a non-printable ASCII character (greater than 127) or the end of the stack is encountered.
 * It prints each character sequentially without any delimiter.
 * If the stack is empty or does not contain printable ASCII characters, it prints only a newline character.
 */

void f_pstr(stack_t **head, unsigned int counter)
{
stack_t *current = *head;
    /* Prevent unused variable warning */
    (void)counter;

    /* Traverse the stack and print characters until a non-printable ASCII character or end of stack is encountered */
    for (; current != NULL && current->n > 0 && current->n <= 127; current = current->next)
    {
        printf("%c", current->n);
    }

    /* Print newline character after printing the string */
    printf("\n");
}
