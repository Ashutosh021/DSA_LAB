#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
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
            p = p->link;
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
        p = p->link;
        pos++;
    }
    printf("\n Item Not Found ");
}

void createList(struct node **start, int item)
{
    struct node *p = *start;
    if (p == NULL)
    {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = item;
        tmp->link = NULL;
        *start = tmp;
    }
}

void addatBeg(struct node **start, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = *start;
    *start = tmp;
}

void addatEnd(struct node *start, int data)
{
    struct node *p = start;
    while (p->link != NULL)
    {
        p = p->link;
    }

    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    p->link = tmp;
    tmp->link = NULL;
}

void deleteAtBeg(struct node **start)
{
    if (*start == NULL)
    {
        printf("\n **** List is Empty ****");
        return;
    }
    struct node *tmp = *start;
    *start = (*start)->link;
    free(tmp);
}

void deleteAtEnd(struct node *start)
{
    if (start == NULL)
    {
        printf("\n **** List is Empty ****");
        return;
    }
    struct node *p = start;
    struct node *prev = NULL;
    while (p->link != NULL)
    {
        prev = p;
        p = p->link;
    }
    if (prev != NULL)
        prev->link = NULL;
    free(p);
}

void deleteAtPosition(struct node **start, int pos)
{
    if (*start == NULL)
    {
        printf("\n **** List is Empty ****");
        return;
    }
    if (pos == 1)
    {
        deleteAtBeg(start);
        return;
    }
    struct node *p = *start;
    struct node *prev = NULL;
    int count = 1;
    while (p != NULL && count < pos)
    {
        prev = p;
        p = p->link;
        count++;
    }
    if (p == NULL)
    {
        printf("\nInvalid Position");
        return;
    }
    prev->link = p->link;
    free(p);
}

void reverseList(struct node **start)
{
    struct node *prev = NULL;
    struct node *current = *start;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    displayList(prev);
    *start = prev;
}

int main()
{

    struct node *start = NULL;
    int choice;
    int data = 0;
    while (1)
    {
        printf("\n\n ***** ---------  ***** :- ");
        printf("\nChoose Operation  ");
        printf("\n1. Create Node ");
        printf("\n2. Display ");
        printf("\n3. Add at Beginning ");
        printf("\n4. Add at End ");
        printf("\n5. Search ");
        printf("\n6. Delete at Beginning ");
        printf("\n7. Delete at End ");
        printf("\n8. Delete at Position ");
        printf("\n9. Reverse List ");
        printf("\n10. Exit\n\n ");
        printf("\nChoose Operation :  ");
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
            addatEnd(start, data);
            break;

        case 5:
            printf("\n Enter the data to be Searched :- ");
            scanf("%d", &data);
            searchItem(start, data);
            break;

        case 6:
            deleteAtBeg(&start);
            break;

        case 7:
            deleteAtEnd(start);
            break;

        case 8:
            printf("\n Enter the position to delete :- ");
            scanf("%d", &data);
            deleteAtPosition(&start, data);
            break;

        case 9:
            reverseList(&start);
            break;

        case 10:
            exit(0);

        default:
            printf("\nInvalid Choice ");
        }
    }

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int info;
//     struct node *link;
//     struct node *prev;
// };

// void displayList(struct node *start)
// {
//     if (start == NULL)
//     {
//         printf("\n **** List is Empty ****");
//     }
//     else
//     {
//         struct node *p;
//         p = start;
//         printf("\n ----  Linked List is :- ");
//         while (p != NULL)
//         {
//             printf(" %d ", p->info);
//             p = p->link;
//         }
//     }
// }

// void searchItem(struct node *start, int item)
// {
//     struct node *p;
//     p = start;
//     int pos = 1;
//     while (p != NULL)
//     {
//         if (p->info == item)
//         {
//             printf("\n Item Found at :- %d", pos);
//             return;
//         }
//         p = p->link;
//         pos++;
//     }
//     printf("\n Item Not Found ");
// }

// void createList(struct node **start, int item)
// {
//     struct node *p = *start;
//     if (p == NULL)
//     {
//         struct node *tmp = (struct node *)malloc(sizeof(struct node));
//         tmp->info = item;
//         tmp->link = NULL;
//         *start = tmp;
//     }
// }

// void addatBeg(struct node **start, int data)
// {
//     struct node *p = *start;
//     struct node *tmp = (struct node *)malloc(sizeof(struct node));
//     tmp->info = data;
//     tmp->link = *start;
//     *start = tmp;
// }

// void addatEnd(struct node *start, int data)
// {
//     struct node *p = start;
//     while (p->link != NULL)
//     {
//         p = p->link;
//     }

//     struct node *tmp = (struct node *)malloc(sizeof(struct node));
//     tmp->info = data;
//     p->link = tmp;
//     tmp->link = NULL;
// }

// int main()
// {

//     struct node *start = NULL;
//     // createList(&start, 20);
//     // addatBeg(&start, 30);
//     // addatBeg(&start, 50);
//     // addatEnd(start, 90);
//     // addatEnd(start, 100);
//     // displayList(start);
//     int choice;
//     int data = 0;
//     while (1)
//     {
//         /* code */
//         printf("\n\n ***** ---------  ***** :- ");
//         printf("\nChoose Operation  ");
//         printf("\n1. Create Node ");
//         printf("\n2. Display ");
//         printf("\n3. Add at Beginnning ");
//         printf("\n4. Add at End ");
//         printf("\n5. Search \n\n ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("\n Enter the data :- ");
//             scanf("%d", &data);
//             createList(&start, data);
//             break;

//         case 2:
//             displayList(start);
//             break;

//         case 3:
//             printf("\n Enter the data to add at start:- ");
//             scanf("%d", &data);
//             addatBeg(&start, data);
//             break;

//         case 4:
//             printf("\n Enter the data to add at end :- ");
//             scanf("%d", &data);
//             addatEnd(start, data);
//             break;
        
//         case 5:
//             printf("\n Enter the data to be Searched :- ");
//             scanf("%d", &data);
//             searchItem(start, data);
//             break;

//         default:
//             exit(1);
//         }
//     }

//     return 0;
// }
