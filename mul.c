#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR1, node **tailR1)
{
    int count = 0, carry = 0, num1, num2, mul, data; // Variables for multiplication logic
    node *temp1 = tail1, *temp2 = tail2;             // Pointers to traverse both numbers
    node *headR2 = NULL, *tailR2 = NULL;             // Temporary list for partial result
    node *headAR = NULL, *tailAR = NULL;             // List to store addition result

    while (temp2)                                    // Loop through each digit of second number
    {
        /* Insert zeros based on position
           Example:
             2 3
           x 3 4
           -----
             9 2
           6 9 0   <- one zero added for next digit
        */
        for (int i = 0; i < count; i++)              // Add required number of zeros
        {
            insert_first(&headR2, &tailR2, 0);       // Insert zero at beginning
        }

        temp1 = tail1;                               // Start from last digit of first number
        carry = 0;                                   // Reset carry for each new digit

        while (temp1)                                // Multiply with each digit of first number
        {
            num1 = temp1->data;                      // Get digit from first number
            num2 = temp2->data;                      // Get digit from second number

            mul = num1 * num2 + carry;               // Multiply digits and add carry
            data = mul % 10;                         // Get last digit of result
            carry = mul / 10;                        // Calculate carry

            if (count == 0)                          // For first partial result
                insert_first(headR1, tailR1, data);  // Store directly in final result
            else
                insert_first(&headR2, &tailR2, data);// Store in temporary list

            temp1 = temp1->prev;                     // Move to next digit of first number
        }

        temp2 = temp2->prev;                         // Move to next digit of second number

        if (carry)                                   // If carry remains after multiplication
        {
            if (count == 0)
                insert_first(headR1, tailR1, carry); // Add carry to final result
            else
                insert_first(&headR2, &tailR2, carry);// Add carry to temporary result
        }

        if (count)                                   // If this is not the first partial result
        {
            headAR = tailAR = NULL;                  // Reset addition result list

            addition(*tailR1, tailR2, &headAR, &tailAR); // Add partial result to final result
            delete_list(headR1, tailR1);             // Delete old final result
            delete_list(&headR2, &tailR2);            // Delete temporary result

            *headR1 = headAR;                        // Update final result head
            *tailR1 = tailAR;                        // Update final result tail
        }

        count++;                                     // Increase zero count for next round
    }
}
