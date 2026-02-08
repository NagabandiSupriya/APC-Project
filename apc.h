#ifndef APC_H                         // Check if header file is already included
#define APC_H                         // Define header guard name

#include <stdio.h>                    // Needed for printf and input/output
#include <string.h>                   // Needed for string handling
#include <stdlib.h>                   // Needed for malloc and free

#define SUCCESS     1                 // Value used when function is successful
#define FAILURE     0                 // Value used when function fails

#define SAME        0                 // MACRO Used when both numbers are equal
#define OPERAND1    1                 // MACRO Used when first number is bigger
#define OPERAND2    2                 // MACRO Used when second number is bigger

typedef struct node                   // Define structure for a list node
{
    struct node *prev;                // Pointer to previous node
    int data;                         // Stores a single digit
    struct node *next;                // Pointer to next node
} node;                               // Name of the structure type

void addition(node *tail1, node *tail2, node **headR, node **tailR);     // Adds two numbers
void subtraction(node *tail1, node *tail2, node **headR, node **tailR);  // Subtracts two numbers
void multiplication(node *tail1, node *tail2, node **headR, node **tailR); // Multiplies two numbers
void division(node *head_L1, node *head_OPR2, node *tail_OPR2, node **headR, node **tailR); // Divides numbers

int cla_validation(int argc, char *argv[]); // Checks command line arguments
void create_list(char *opr, node **head, node **tail); // Converts number string to list

int insert_first(node **head, node **tail, int data);  // Insert node at beginning
int insert_last(node **head, node **tail, int data);   // Insert node at end
int delete_list(node **head, node **tail);              // Delete entire list
void print_list(node *head);                            // Print list as number

int compare_list(node *head1, node *head2); // Compare two numbers stored in lists
int list_len(node *head);                   // Count number of digits in list
void remove_pre_zeros(node **head);         // Remove leading zeros from number

#endif                                      // End of header file
