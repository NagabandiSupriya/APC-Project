#include "apc.h"                         

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int num1, num2, sum, carry = 0;      // Variables to store digits, sum, and carry
    node *temp1 = tail1;                 // Pointer to last node of first number
    node *temp2 = tail2;                 // Pointer to last node of second number

    while (temp1 || temp2 != NULL)       // Continue until both numbers are fully processed
    {
        if (temp1 != NULL)               // If first number still has digits
        {
            num1 = temp1->data;          // Get current digit from first number
            temp1 = temp1->prev;         // Move to previous digit
        }
        else
            num1 = 0;                    // Use 0 if no digits left

        if (temp2 != NULL)               // If second number still has digits
        {
            num2 = temp2->data;          // Get current digit from second number
            temp2 = temp2->prev;         // Move to previous digit
        }
        else
            num2 = 0;                    // Use 0 if no digits left

        sum = num1 + num2 + carry;       // Add both digits and previous carry
        carry = sum / 10;                // Calculate carry for next step
        sum = sum % 10;                  // Get single digit result

        insert_first(headR, tailR, sum); // Insert result digit at the beginning
    }

    if (carry)                           // If carry remains after addition
    {
        insert_first(headR, tailR, carry); // Insert remaining carry at the beginning
    }
}
