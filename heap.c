#include <stdio.h>
#include <stdlib.h>

#define max50 50

void heapify(int a[], int n);
void heapSort(int a[], int n);
void reheapifyDownward(int heap[], int start, int finish);

void main()
{
    int i, n, a[max50];
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    if (n > max50)
    {
        printf("\n Input size of array greater than declared size\n");
        exit(1);
    }
    
    printf("\nEnter %d integer elements of array\n\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    heapSort(a, n);
    
    printf("\nSorted list of elements\n\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

void heapify(int a[], int n)
{
    int i, index;

    index = n / 2;

    for (i = index; i >= 0; i--)
        reheapifyDownward(a, i, n);
}

void heapSort(int a[], int n)
{
    int i, temp;
    heapify(a, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        reheapifyDownward(a, 0, i - 1);
    }
}

void reheapifyDownward(int heap[], int start, int finish)
{
    int index, lchild, rchild, maximum, temp;
    lchild = 2 * start + 1;
    rchild = lchild + 1;
    
    if (lchild <= finish)
    {
        maximum = heap[lchild];
        index = lchild;
        
        if (rchild <= finish && heap[rchild] > maximum)
        {
            maximum = heap[rchild];
            index = rchild;
        }
        
        if (heap[start] < heap[index])
        {
            temp = heap[start];
            heap[start] = heap[index];
            heap[index] = temp;
            reheapifyDownward(heap, index, finish);
        }
    }
}
