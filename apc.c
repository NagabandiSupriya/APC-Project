#include "apc.h"                      // Includes required definitions and structures
// Adds a new value at the start of the list
int insert_first(node **head, node **tail, int data)
{
    node *new_node = malloc(sizeof(node));   // Create memory for a new list item
    if (new_node == NULL)                    // Check if memory was not created
    {
        printf("Memory allocation failed\n"); 
        return FAILURE;                      // Stop function if memory fails
    }

    new_node->data = data;                   // Store the given value in the node
    new_node->prev = NULL;                   // No node exists before this one
    new_node->next = NULL;                   // No node exists after this one yet

    if (*head == NULL)                       // If the list is empty
    {
        *head = new_node;                    // New node becomes the first node
        *tail = new_node;                    // New node also becomes the last node
    }
    else
    {
        new_node->next = *head;              // Connect new node to old first node
        (*head)->prev = new_node;            // Connect old first node back to new node
        *head = new_node;                    // Make new node the first node
    }

    return SUCCESS;                        
}

// Adds a new value at the end of the list
int insert_last(node **head, node **tail, int data)
{
    node *new_node = malloc(sizeof(node));   // Create memory for a new list item
    if (new_node == NULL)                    // Check if memory was not created
    {
        printf("Memory allocation failed\n"); 
        return FAILURE;                      // Stop function if memory fails
    }

    new_node->data = data;                   // Store the given value
    new_node->prev = NULL;                   // Previous connection not set yet
    new_node->next = NULL;                   // No node after this one

    if (*head == NULL)                       // If the list has no items
    {
        *head = new_node;                    // New node becomes first
        *tail = new_node;                    // New node becomes last
    }
    else
    {
        new_node->prev = *tail;              // Connect new node to current last node
        (*tail)->next = new_node;            // Connect last node to new node
        *tail = new_node;                    // Update last node to new node
    }

    return SUCCESS;                          // Operation completed successfully
}

// Displays all values stored in the list
void print_list(node *head)
{
    if (head == NULL)                        // If list is empty
    {
        printf("INFO: List is empty\n");   
        return;                              // Exit function
    }

    while (head)                             // Go through each item in the list
    {
        printf("%d", head->data);            // Print the value stored
        head = head->next;                   // Move to the next item
    }
    printf("\n");                            
}

// Converts a number string into a list of digits
void create_list(char *opr, node **head, node **tail)
{
    int i = 0;                               // Start from the first character
    if(opr[i]=='+'||opr[i]=='-')             // Ignore plus or minus sign
    {
        i++;                                 // Move to first digit
    }
    while (opr[i])                           // Read each digit one by one
    { 
        int digit = opr[i] - '0';            // Change character to number
        insert_last(head, tail, digit);      // Store digit at end of list
        i++;                                 // Move to next character
    }
}

// Checks whether command line inputs are valid numbers
int cla_validation(int argc, char *argv[])
{
    if (argc != 4)                           // Ensure correct number of inputs
        return FAILURE;

    int i = 0;                               // Start checking from first character

    if (argv[1][i] == '+' || argv[1][i] == '-') // Allow sign for first number
        i++;

    if (argv[1][i] == '\0')                  // Reject input if only sign is given
        return FAILURE;

    while (argv[1][i])                       // Check every character
    {
        if (argv[1][i] >= '0' && argv[1][i] <= '9') // Allow only digits
            i++;
        else
            return FAILURE;                  // Reject if not a digit
    }

    i = 0;                                   // Reset index for second number
    if (argv[3][i] == '+' || argv[3][i] == '-') // Allow sign for second number
        i++;

    if (argv[3][i] == '\0')                  // Reject input if only sign is given
        return FAILURE;

    while (argv[3][i])                       // Check every character
    {
        if (argv[3][i] >= '0' && argv[3][i] <= '9') // Allow only digits
            i++;
        else
            return FAILURE;                  // Reject if not a digit
    }

    return SUCCESS;                          
}

int list_len(node *head)
{
    int count = 0;                           // Start counting from zero
    while(head)                              // Go through the list
    {
        count++;                             // Increase count for each node
        head = head->next;                  // Move to next node
    }
    return count;                            // Return total count
}

// Compares two lists to see which represents a larger number
int compare_list(node *head1, node *head2)
{
    node *temp1 = head1;                    // Pointer for first list
    node *temp2 = head2;                    // Pointer for second list

    int len1 = list_len(head1);             // Count digits in first list
    int len2 = list_len(head2);             // Count digits in second list

    if (len1 > len2)                        // Longer number is larger
        return OPERAND1;
    else if (len1 < len2)
        return OPERAND2;

    while (temp1 != NULL && temp2 != NULL)  // Compare digits one by one
    {
        if (temp1->data > temp2->data)      // Check which digit is bigger
            return OPERAND1;
        else if (temp1->data < temp2->data)
            return OPERAND2;

        temp1 = temp1->next;                // Move to next digit
        temp2 = temp2->next;
    }

    return SAME;                            // Both numbers are equal
}

// Removes extra zeros from the beginning of the list
void remove_pre_zeros(node **head)
{
    if((*head)==NULL)                       // If list is empty, do nothing
        return;

    while ((*head)->data == 0 && (*head)->next != NULL) // Remove starting zeros
    {
        node *temp = *head;                 // Store current first node
        *head = (*head)->next;              // Move head forward
        (*head)->prev = NULL;               // Disconnect previous node
        free(temp);                         // Delete old zero node
    }
}

// Deletes all nodes and clears the list
int delete_list(node **head, node **tail)
{
    if (*head == NULL)                      // If list is already empty
        return FAILURE;

    node *temp = *head;                     // Start from first node

    while (temp)                            // Remove each node one by one
    {
        node *next = temp->next;            // Save next node
        free(temp);                         // Free current node
        temp = next;                        // Move to next node
    }

    *head = NULL;                           // Set head to empty
    *tail = NULL;                           // Set tail to empty

    return SUCCESS;  
}                       
