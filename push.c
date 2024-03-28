#include "monty.h"

/**
 * Function: is_valid_integer
 * ----------------------------
 * Checks if a string represents a valid integer.
 *
 * @str: String to check.
 *
 * This function iterates through the characters of the string to determine if it represents
 * a valid integer. It first checks if the string starts with an optional minus sign and skips it.
 * Then, it checks each character in the string to ensure that it contains digits only.
 * If the string contains any non-digit characters, the function returns 0, indicating that
 * the string does not represent a valid integer. Otherwise, if the string consists of digits
 * only, the function returns 1, indicating that the string represents a valid integer.
 */

int is_valid_integer(const char *str)
{
    /* Skip optional minus sign */
    if (*str == '-')
        str++;

    /* Check if string contains digits only */
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

/*
 * Function: f_push
 * ----------------------------
 * Adds a new node to the stack.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number where the operation is performed.
 *
 * This function first checks if an argument is provided. If not, it prints an error message
 * to stderr and exits with failure status. Then, it converts the argument to an integer
 * using the atoi function. If the argument is not a valid integer, it prints another error
 * message and exits with failure status.
 * If the argument is a valid integer, it adds a new node to the stack using the addnode
 * function if the 'lifo' mode is active, or using the addqueue function if the 'fifo' mode
 * is active.
 */

void f_push(stack_t **head, unsigned int counter)
{
    int n;

    /* Check if argument exists */
    if (!bus.arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        exit(EXIT_FAILURE);
    }

    /* Convert argument to integer */
    n = atoi(bus.arg);

    /* Check if argument is a valid integer */
    if (!is_valid_integer(bus.arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        exit(EXIT_FAILURE);
    }

    /* Add node to the stack */
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

