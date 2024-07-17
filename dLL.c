#include <stdio.h>
#include <stdlib.h>
typedef struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *next;
    struct doublyLinkedList *prev;
} node;

void insertAtBeggining(node **head, int item)
{
    if ((*head) == NULL)
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr->data = item;
        ptr->next = NULL;
        ptr->prev = NULL;
        (*head) = ptr;
    }
    else
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr->data = item;
        node *p = *head;
        p->prev = ptr;
        ptr->prev = NULL;
        ptr->next = *head;
        *head = ptr;
    }
}

void insertAtLast(node **head, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    ptr->next = NULL;
    node *p = *head;
    while (p->next != NULL)
        p = p->next;
    ptr->prev = p;
    p->next = ptr;
}

void display(node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
        {
            printf(" -> ");
        }
        head = head->next;
    }
}

void insertAtPosition(node **head, int pos, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    if (pos == 1)
        insertAtBeggining(head, item);
    else
    {
        node *p = *head;
        node *q = p->next;
        while (pos > 2)
        {
            p = p->next;
            q = q->next;
            pos--;
        }
        ptr->prev = p;
        ptr->next = q;
        p->next = ptr;
        q->prev = ptr;
    }
}

void insertAfterKey(node **head, int key, int item)
{
    node *p = *head;
    while (p->data != key && p->next != NULL)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        printf("Element not found");
        return;
    }
    node *q = p->next;
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    ptr->next = q;
    ptr->prev = p;
    p->next = ptr;
    q->prev = ptr;
}

void deleteFirst(node **head)
{
    node *p = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(p);
}

void deleteEnd(node **head)
{
    node *p = *head;
    node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

void deleteAtPosition(node **head, int pos)
{
    if (pos == 1)
    {
        deleteFirst(head);
    }
    else
    {
        node *p = *head;
        node *q = p->next;
        node *r = q->next;
        while (pos > 2)
        {
            p = p->next;
            q = q->next;
            r = r->next;
            pos--;
        }
        p->next = r;
        r->prev = p;
        free(q);
    }
}

void deleteKey(node **head, int key)
{
    node *p = *head;
    int i=1;
    while (p->data != key && p->next != NULL)
    {
        i++;
        p = p->next;
    }
    if (p->next == NULL)
    {
        printf("Element not found");
        return;
    }
    deleteAtPosition(head,i);
    node *a = p->next;
    node *b= p->prev;
    if(a==NULL&&b==NULL)
    *head=NULL;
    else if(a==NULL)
    deleteFirst(head);
    else if(b==NULL)
    deleteEnd(head);
    free(p);
}

int main()
{
    node *head = NULL;
    insertAtBeggining(&head, 10);
    insertAtBeggining(&head, 7);
    insertAtBeggining(&head, 5);
    insertAtBeggining(&head, 3);
    insertAtBeggining(&head, 1);
    insertAtLast(&head, 23);
    insertAtLast(&head, 25);
    insertAtLast(&head, 27);
    insertAtLast(&head, 30);
    insertAtPosition(&head, 6, 18);
    insertAtPosition(&head, 6, 16);
    insertAtPosition(&head, 6, 14);
    insertAtPosition(&head, 6, 12);

    display(head);
    insertAfterKey(&head, 18, 19);
    printf("\n");
    display(head);
    deleteFirst(&head);
    printf("\n");
    display(head);
    deleteEnd(&head);
    printf("\n");
    display(head);
    deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 2);
    printf("\n");
    display(head);
    deleteKey(&head,18);
    printf("\n");
    display(head);
}
