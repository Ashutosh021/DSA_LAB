#include <stdio.h>
#define MAX 10
int top = -1;
int arr[MAX];

int isFull()
{
    if (top == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int n)
{
    if (isFull())
    {
        printf("\nCan't Push!! Stack Full");
    }
    else
    {
        top++;
        arr[top] = n;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("\nCan't Pop!! Stack Empty");
    }
    else
    {
        int data = arr[top];
        top--;
        return data;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nSatck is Empty..");
    }
    else
    {
        printf("\nPrinting Stack ..");
        for (int i = top; i >= 0; i--)
        {
            printf(" %d ", arr[i]);
        }
    }
}

int main()
{
    while (1)
    {
        int choice = 0;
        int data = 0;
        printf("\n\nEnter Your Choice :- ");
        printf("\n1. Push :- ");
        printf("\n2. Pop :- ");
        printf("\n3. Print Stack :- ");
        printf("\n4. IsEmpty :- ");
        printf("\n5. IsFull :- ");
        printf("\n6. Exit :- ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the you want to Push ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("\nPopped Element is :- %d", data);
            break;
        case 3:
                display();
            break;
        case 4:
            if (isFull())
            {
                printf("\nStack is Full");
            }
            else
            {
                printf("\nStack is Not Full");
            }
            break;
        case 5:
            if (isEmpty())
            {
                printf("\nStack is Empty");
            }
            else
            {
                printf("\nStack is Not Empty");
            }
            break;
        case 6:
            exit(1);
        default:
            printf("\nNot a Valid Case...");
            break;
        }
    }
}