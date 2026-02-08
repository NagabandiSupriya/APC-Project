#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow = 0, sub = 0, num1, num2;     // Variables to store borrow, result, and digits
    node *temp1 = tail1;                    // Pointer to last digit of first number
    node *temp2 = tail2;                    // Pointer to last digit of second number

    while (temp1)                           // Continue until all digits of first number are processed
    {
        if (temp1)                          // If digit exists in first number
        {
            num1 = temp1->data;             // Get digit from first number
            temp1 = temp1->prev;            // Move to previous digit
        }

        if (temp2)                          // If digit exists in second number
        {
            num2 = temp2->data;             // Get digit from second number
            temp2 = temp2->prev;            // Move to previous digit
        }
        else
        {
            num2 = 0;                       // Use 0 if second number has no digit
        }

        if (borrow)                         // If borrow was taken from previous step
        {
            num1 = num1 - 1;                // Reduce current digit by 1
            borrow = 0;                     // Reset borrow
        }

        if (num1 < num2)                    // If top digit is smaller than bottom digit
        {
            num1 += 10;                     // Borrow 10 from next digit
            borrow = 1;                     // Mark borrow for next iteration
        }

        sub = num1 - num2;                  // Perform subtraction for current digit

        insert_first(headR, tailR, sub);    // Store result digit at the beginning
    }
}
