#include "apc.h"                         // Header file containing all function declarations

#define RESET  "\033[0m"                // Reset terminal color to default
#define RED    "\033[31m"               // Red color for error messages
#define GREEN  "\033[32m"               // Green color for successful result
#define YELLOW "\033[33m"               // Yellow color for information
#define BLUE   "\033[34m"               // Blue color for headings

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL;   // Linked list for operand 1
    node *head2 = NULL, *tail2 = NULL;   // Linked list for operand 2
    node *headR = NULL, *tailR = NULL;   // Linked list for result

    int p_flag1 = 0, p_flag2 = 0;        // Flags to indicate positive numbers
    int n_flag1 = 0, n_flag2 = 0;        // Flags to indicate negative numbers

    if (!cla_validation(argc, argv))     // Validate command line arguments
    {
        printf(RED "ERROR : Invalid command line arguments\n" RESET); // Print error
        return FAILURE;                  // Exit program on failure
    }

    create_list(argv[1], &head1, &tail1); // Convert operand 1 into linked list
    create_list(argv[3], &head2, &tail2); // Convert operand 2 into linked list

    remove_pre_zeros(&head1);            // Remove leading zeros from operand 1
    remove_pre_zeros(&head2);            // Remove leading zeros from operand 2

    printf(YELLOW "Operand 1 : " RESET); // Display operand 1 heading
    print_list(head1);                   // Print operand 1 list

    printf(YELLOW "Operand 2 : " RESET); // Display operand 2 heading
    print_list(head2);                   // Print operand 2 list

    if (argv[1][0] == '-')               // Check if operand 1 is negative
        n_flag1 = 1;
    else
        p_flag1 = 1;

    if (argv[3][0] == '-')               // Check if operand 2 is negative
        n_flag2 = 1;
    else
        p_flag2 = 1;

    char oper = argv[2][0];              // Store operator symbol

    switch (oper)
    {
    case '+':                            // Addition operation
        printf(BLUE "Addition Result : " RESET);

        if (n_flag1 == n_flag2)          // Same sign add directly
        {
            addition(tail1, tail2, &headR, &tailR); // Call addition function
            remove_pre_zeros(&headR);    // Remove leading zeros from result

            if (n_flag1)                 // Print minus if result is negative
                printf("-");
        }
        else                             // Different sign subtraction
        {
            int ret = compare_list(head1, head2); // Compare both operands

            if (ret == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR); // Operand1 - Operand2
                remove_pre_zeros(&headR);
                if (n_flag1)
                    printf("-");
            }
            else if (ret == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR); // Operand2 - Operand1
                remove_pre_zeros(&headR);
                if (n_flag2)
                    printf("-");
            }
            else
                insert_first(&headR, &tailR, 0); // Result is zero
        }

        printf(GREEN);
        print_list(headR);               // Print final result
        printf(RESET);
        break;

    case '-':                            // Subtraction operation
        printf(BLUE "Subtraction Result : " RESET);

        n_flag2 = !n_flag2;              // Convert subtraction to addition logic

        if (n_flag1 == n_flag2)
        {
            addition(tail1, tail2, &headR, &tailR); // Perform addition
            remove_pre_zeros(&headR);
            if (n_flag1)
                printf("-");
        }
        else
        {
            int ret = compare_list(head1, head2);

            if (ret == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR);
                remove_pre_zeros(&headR);
                if (n_flag1)
                    printf("-");
            }
            else if (ret == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR);
                remove_pre_zeros(&headR);
                if (!n_flag1)
                    printf("-");
            }
            else
                insert_first(&headR, &tailR, 0);
        }

        printf(GREEN);
        print_list(headR);               // Print result
        printf(RESET);
        break;

    case 'x':
    case 'X':                            // Multiplication operation
        printf(BLUE "Multiplication Result : " RESET);

        multiplication(tail1, tail2, &headR, &tailR); // Call multiplication
        remove_pre_zeros(&headR);

        if (n_flag1 ^ n_flag2)           // XOR result sign check
            printf("-");

        printf(GREEN);
        print_list(headR);
        printf(RESET);
        break;

    case '/':                            // Division operation
        printf(BLUE "Division Result : " RESET);

        division(head1, head2, tail2, &headR, &tailR); // Call division
        remove_pre_zeros(&headR);

        if (n_flag1 ^ n_flag2)
            printf("-");

        printf(GREEN);
        print_list(headR);
        printf(RESET);
        break;

    default:                             
        printf(RED "ERROR : Invalid operator\n" RESET);
        return FAILURE;
    }

    return SUCCESS;                      // Program executed successfully
}
