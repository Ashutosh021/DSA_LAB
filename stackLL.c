#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
} node;

void displayList(node *head)
{
    while (head != (node *)NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void insertElementAtBeggining(node **head)
{
    int item;
    printf("Enter the number : ");
    scanf("%d", &item);
    node *p = (node *)malloc(sizeof(node));
    p->data = item;
    if ((*head) == NULL)
    {
        p->next = NULL;
        *head = p;
    }
    else
    {
        p->next = *head;
        *head = p;
    }
    return;
}

int deleteFirstElement(node **head)
{
    if ((*head) == NULL)
    {
        printf("Your Linked LIst is already empty");
        return -1;
    }
    node *p = *head;
    *head = (*head)->next;
    int data = p->data;
    free(p);
    return data;
}

int main()
{
    int choice, item;
    node *head = NULL;
    do
    {
        printf("Enter your choice\n1 for insertion\n2 for deletion\n3 for displaying and other for exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertElementAtBeggining(&head);
            break;
        case 2:
            item = deleteFirstElement(&head);
            if (item != -1)
            {
                printf("Element deleted is : %d.\n", item);
            }
            break;
        case 3:
            displayList(head);
            break;
        }
    } while (choice < 4 && choice > 0);
    return 0;
}