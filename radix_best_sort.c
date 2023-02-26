#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
    int data;
    struct s_node *next;
}              t_node;

void push(t_node **stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = value;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(t_node **stack) {
    if (*stack == NULL) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    int value = (*stack)->data;
    t_node *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

void swap(t_node **stack) {
    if (*stack != NULL && (*stack)->next != NULL) {
        int temp = (*stack)->data;
        (*stack)->data = (*stack)->next->data;
        (*stack)->next->data = temp;
    }
}

void rotate(t_node **stack) {
    if (*stack != NULL && (*stack)->next != NULL) {
        t_node *last_node = *stack;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = *stack;
        *stack = (*stack)->next;
        last_node->next->next = NULL;
    }
}

void reverse_rotate(t_node **stack) {
    if (*stack != NULL && (*stack)->next != NULL) {
        t_node *last_node = *stack;
        while (last_node->next->next != NULL) {
            last_node = last_node->next;
        }
        t_node *temp = last_node->next;
        last_node->next = NULL;
        temp->next = *stack;
        *stack = temp;
    }
}

int get_max_digit(int *array, int size) {
    int max_digit = 0;
    for (int i = 0; i < size; i++) {
        int num = array[i];
        int num_digits = 0;
        while (num != 0) {
            num /= 10;
            num_digits++;
        }
        if (num_digits > max_digit) {
            max_digit = num_digits;
        }
    }
    return max_digit;
}

void radix_sort(t_node **stack_a, t_node **stack_b) {
    int array_size = 0;
    int *array = NULL;
    t_node *current_node = *stack_a;
    while (current_node != NULL) {
        array_size++;
        array = realloc(array, array_size * sizeof(int));
        array[array_size - 1] = current_node->data;
        current_node = current_node->next;
    }
    int max_digit = get_max_digit(array, array_size);
    for (int i = 0; i < max_digit; i++) {
        for (int j = 0; j < array_size; j++) {
            int num = array[j];
            int digit = 0;
            for (int k = 0; k <= i; k++) {
                digit = num % 10;
                num /= 10;
            }
            if (digit == 0) {
                push(stack_a, pop(stack_b));
            } else {
                while (digit > 0) {
                    rotate(stack_b);
                    digit--;
                }
                push(stack_b, pop(stack_a));
            }
        }
        while (*stack_b != NULL) {
            push(stack_a, pop(stack_b));


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list implementation
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure using linked list implementation
typedef struct Stack {
    Node* top;
} Stack;

// Push operation
void push(Stack* stack, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

// Pop operation
int pop(Stack* stack) {
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Peek operation
int peek(Stack* stack) {
    return stack->top->data;
}

// Check if stack is empty
bool is_empty(Stack* stack) {
    return (stack->top == NULL);
}

// Swap operation for stack a
void sa(Stack* a) {
    if (a->top != NULL && a->top->next != NULL) {
        int temp = a->top->data;
        a->top->data = a->top->next->data;
        a->top->next->data = temp;
    }
}

// Swap operation for stack b
void sb(Stack* b) {
    if (b->top != NULL && b->top->next != NULL) {
        int temp = b->top->data;
        b->top->data = b->top->next->data;
        b->top->next->data = temp;
    }
}

// Swap operation for both stacks
void ss(Stack* a, Stack* b) {
    sa(a);
    sb(b);
}

// Push operation from stack b to stack a
void pa(Stack* a, Stack* b) {
    if (b->top != NULL) {
        int data = pop(b);
        push(a, data);
    }
}

// Push operation from stack a to stack b
void pb(Stack* a, Stack* b) {
    if (a->top != NULL) {
        int data = pop(a);
        push(b, data);
    }
}

// Rotate operation for stack a
void ra(Stack* a) {
    if (a->top != NULL && a->top->next != NULL) {
        int temp = a->top->data;
        Node* current = a->top;
        while (current->next != NULL) {
            current->data = current->next->data;
            current = current->next;
        }
        current->data = temp;
    }
}

// Rotate operation for stack b
void rb(Stack* b) {
    if (b->top != NULL && b->top->next != NULL) {
        int temp = b->top->data;
        Node* current = b->top;
        while (current->next != NULL) {
            current->data = current->next->data;
            current = current->next;
        }
        current->data = temp;
    }
}

// Rotate operation for both stacks
void rr(Stack* a, Stack* b) {
    ra(a);
    rb(b);
}

// Reverse rotate operation for stack a
void rra(Stack* a) {
    if (a->top != NULL && a->top->next != NULL) {
        Node* prev = NULL;
        Node* current = a->top;
        Node* next = a->top->next;
        while (next != NULL) {
            current->next = prev;
           
#include <stdlib.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

void sa(t_node **stack)
{
    t_node *temp;

    if (*stack && (*stack)->next)
    {
        temp = (*stack)->next;
        (*stack)->next = temp->next;
        temp->next = *stack;
        *stack = temp;
    }
}

void sb(t_node **stack)
{
    sa(stack);
}

void ss(t_node **a, t_node **b)
{
    sa(a);
    sb(b);
}

void pa(t_node **a, t_node **b)
{
    t_node *temp;

    if (*b)
    {
        temp = *b;
        *b = (*b)->next;
        temp->next = *a;
        *a = temp;
    }
}

void pb(t_node **a, t_node **b)
{
    pa(b, a);
}

void ra(t_node **stack)
{
    t_node *temp;
    t_node *last;

    if (*stack && (*stack)->next)
    {
        temp = *stack;
        *stack = (*stack)->next;
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = temp;
        temp->next = NULL;
    }
}

void rb(t_node **stack)
{
    ra(stack);
}

void rr(t_node **a, t_node **b)
{
    ra(a);
    rb(b);
}

void rra(t_node **stack)
{
    t_node *last;
    t_node *second_last;

    if (*stack && (*stack)->next)
    {
        last = *stack;
        second_last = NULL;
        while (last->next)
        {
            second_last = last;
            last = last->next;
        }
        last->next = *stack;
        *stack = last;
        second_last->next = NULL;
    }
}

void rrb(t_node **stack)
{
    rra(stack);
}

void rrr(t_node **a, t_node **b)
{
    rra(a);
    rrb(b);
}

void radix_sort(t_node **a, t_node **b)
{
    int max_digit_count = 0;
    int divisor = 1;
    int digit, i;
    t_node *temp;

    while (1)
    {
        i = 0;
        while (i < max_digit_count || (*a)->value / divisor)
        {
            digit = ((*a)->value / divisor) % 10;
            if (digit >= 0 && digit <= 9)
            {
                while (i < digit)
                {
                    ra(a);
                    i++;
                }
                pb(b, a);
            }
            else
                rrb(a);
        }
        while (*b)
        {
            temp = *b;
            pb(a, b);
        }
        if (max_digit_count == 0 && !(*a)->next)
            break ;
        divisor *= 10;
        max_digit_count++;
    }
}

Note that this implementation of radix sort is not the most efficient, 
as it uses the stack commands to move numbers between the two stacks. 
A more efficient implementation would use arrays or linked lists and manipulate pointers directly.