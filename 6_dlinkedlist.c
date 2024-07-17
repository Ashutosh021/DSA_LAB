#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

void displayList(struct node *start)
{
    if (start == NULL)
    {
        printf("\n **** List is Empty ****");
    }
    else
    {
        struct node *p;
        p = start;
        printf("\n ----  Linked List is :- ");
        while (p != NULL)
        {
            printf(" %d ", p->info);
            p = p->next;
        }
    }
}

void searchItem(struct node *start, int item)
{
    struct node *p;
    p = start;
    int pos = 1;
    while (p != NULL)
    {
        if (p->info == item)
        {
            printf("\n Item Found at :- %d", pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("\n Item Not Found ");
}

void createList(struct node **start, int item)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    tmp->next = NULL;
    tmp->prev = NULL;
    *start = tmp;
}

void addatBeg(struct node **start, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = *start;
    tmp->prev = NULL;
    if (*start != NULL)
        (*start)->prev = tmp;
    *start = tmp;
}

void addatEnd(struct node **start, int data)
{
    struct node *p = *start;
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = NULL;

    if (*start == NULL)
    {
        tmp->prev = NULL;
        *start = tmp;
        return;
    }

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
    tmp->prev = p;
}

int main()
{

    struct node *start = NULL;
    // createList(&start, 20);
    // addatBeg(&start, 30);
    // addatBeg(&start, 50);
    // addatEnd(&start, 90);
    // addatEnd(&start, 100);
    // displayList(start);


    int choice;
    int data = 0;
    while (1)
    {
        /* code */
        printf("\n\n ***** ---------  ***** :- ");
        printf("\nChoose Operation  ");
        printf("\n1. Create Node ");
        printf("\n2. Display ");
        printf("\n3. Add at Beginnning ");
        printf("\n4. Add at End ");
        printf("\n5. Search \n\n ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter the data :- ");
            scanf("%d", &data);
            createList(&start, data);
            break;

        case 2:
            displayList(start);
            break;

        case 3:
            printf("\n Enter the data to add at start:- ");
            scanf("%d", &data);
            addatBeg(&start, data);
            break;

        case 4:
            printf("\n Enter the data to add at end :- ");
            scanf("%d", &data);
            addatEnd(&start, data);
            break;
        
        case 5:
            printf("\n Enter the data to be Searched :- ");
            scanf("%d", &data);
            searchItem(start, data);
            break;

        default:
            exit(1);
        }
    }

    return 0;
}
