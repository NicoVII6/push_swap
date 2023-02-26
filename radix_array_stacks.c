#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100000 // size of each stack
#define BASE 10 // radix base

// get the digit in the specified place value
int get_digit(int num, int place) {
    return (num / place) % BASE;
}

void radix_sort(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // create two stacks
    int stack1[STACK_SIZE];
    int top1 = -1;
    int stack2[STACK_SIZE];
    int top2 = -1;

    // perform radix sort for each digit, starting with the least significant digit
    int place = 1;
    while (max / place > 0) {
        // push each element onto the stack for its current digit
        for (int i = 0; i < size; i++) {
            int digit = get_digit(arr[i], place);
            if (digit % 2 == 0) {
                top1++;
                stack1[top1] = arr[i];
            } else {
                top2++;
                stack2[top2] = arr[i];
            }
        }

        // move elements between the two stacks using swap, push, rotate, and reverse rotate operations
        while (top2 >= 0) {
            int current = stack2[top2];
            int next = get_digit(current, place) % 2 == 0 ? stack1[top1] : stack2[(top2 + 1) % STACK_SIZE];
            while (current != next) {
                if (next == stack1[top1]) {
                    // push current onto stack1
                    top1++;
                    stack1[top1] = current;
                } else if (next == stack2[(top2 + 1) % STACK_SIZE]) {
                    // swap current with the top element of stack2
                    int temp = current;
                    current = stack2[top2];
                    stack2[top2] = temp;
                    // rotate stack2
                    top2++;
                    int temp_top = top2 % STACK_SIZE;
                    for (int i = 0; i < STACK_SIZE - 1; i++) {
                        int temp_index = (temp_top + STACK_SIZE - 1 - i) % STACK_SIZE;
                        stack2[temp_index] = stack2[(temp_index - 1 + STACK_SIZE) % STACK_SIZE];
                    }
                    stack2[(temp_top + 1) % STACK_SIZE] = current;
                    // reverse rotate stack1
                    int temp_index = top1 % STACK_SIZE;
                    int temp_val = stack1[temp_index];
                    for (int i = 0; i < STACK_SIZE - 1; i++) {
                        int next_index = (temp_index + 1) % STACK_SIZE;
                        stack1[temp_index] = stack1[next_index];
                        temp_index = next_index;
                    }
                    stack1[temp_index] = temp_val;
                }
                next = get_digit(current, place) % 2 == 0 ? stack1[top1] : stack2[(top2 + 1) % STACK_SIZE];
            }
            // push the current element onto stack1 or stack2
            if (get_digit(current, place) % 2 == 0) {
                top1++;
                stack1[top1]
        } else {
            top2++;
            stack2[top2] = current;
        }
        // move to the next element in stack2
        top2--;
    }

    // pop elements from the stack and update the original array
    int i = 0;
    while (top1 >= 0) {
        arr[i] = stack1[top1];
        i++;
        top1--;
    }
    place *= BASE;
}

int main() 
{
	// example usage
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int size = sizeof(arr) / sizeof(arr[0]);
	radix_sort(arr, size);
	for (int i = 0; i < size; i++)
{
	printf("%d ", arr[i]);
}
printf("\n");
return 0;
}


/* Note that the implementation is similar to the counting sort version, but instead of counting 
the number of occurrences of each digit, we push each element onto the stack for its current digit, 
then move elements between two stacks using swap, push, rotate, and reverse rotate operations based 
on the digit being even or odd. After each digit has been processed, we pop elements from the stack 
and update the original array. */
