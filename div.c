#include "apc.h"  

void division(node *head_L1, node *head_OPR2, node *tail_OPR2, node **headR, node **tailR)
{
    int sub_count = 0;                         // Stores how many times subtraction happens
    node *head_SR = NULL, *tail_SR = NULL;    // Temporary list to store subtraction result
    node *head_OPR1 = NULL, *tail_OPR1 = NULL;// Temporary list for partial dividend

    node *L1_temp = head_L1;                  // Pointer to traverse first number
    insert_last(&head_OPR1, &tail_OPR1, L1_temp->data); // Copy first digit to partial dividend

    while (compare_list(head_OPR1, head_OPR2) == OPERAND2) // While divisor is bigger
    {  
        L1_temp = L1_temp->next;              // Move to next digit of dividend
        if (L1_temp == NULL)                  // If no more digits are left
        {
            insert_last(headR, tailR, 0);     // Quotient is zero
            return;                           // Exit function
        }
        insert_last(&head_OPR1, &tail_OPR1, L1_temp->data); // Add next digit to partial dividend
    }

    while (L1_temp != NULL)                   // Continue till all digits are processed
    {
        remove_pre_zeros(&head_OPR1);         // Remove unnecessary zeros at front
        sub_count = 0;                        // Reset subtraction counter

        while (compare_list(head_OPR1, head_OPR2) == OPERAND1 ||
               compare_list(head_OPR1, head_OPR2) == SAME) // While dividend ≥ divisor
        {
            subtraction(tail_OPR1, tail_OPR2, &head_SR, &tail_SR); // Subtract divisor
            delete_list(&head_OPR1, &tail_OPR1); // Delete old partial dividend

            head_OPR1 = head_SR;              // Store subtraction result as new dividend
            tail_OPR1 = tail_SR;

            head_SR = tail_SR = NULL;         // Reset subtraction result list
            remove_pre_zeros(&head_OPR1);     // Remove leading zeros
            sub_count++;                      // Count how many times subtraction happened
        }

        insert_last(headR, tailR, sub_count); // Store quotient digit
        L1_temp = L1_temp->next;              // Move to next digit of original dividend

        if (L1_temp != NULL)                  // If more digits are available
        {
            insert_last(&head_OPR1, &tail_OPR1, L1_temp->data); // Bring next digit down
        }
        else
        {
            break;                            // Stop when no digits are left
        }
    }
}
