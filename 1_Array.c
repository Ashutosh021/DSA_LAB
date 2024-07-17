#include <stdio.h>
#include <stdlib.h>
#define mx 10

void inpMat(int arr[][mx], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printSum(int arr1[][mx], int arr2[][mx], int r, int c)
{ 
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }
}

void printMul(int arr1[][mx], int arr2[][mx], int r, int c)
{
    int res[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < r; k++)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
void transposeMat(int arr1[][mx], int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = i + 1; j < c; ++j)
        {
            int temp = arr1[i][j];
            arr1[i][j] = arr1[j][i];
            arr1[j][i] = temp;
        }
    }
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
}

int main()
{
        /* code */
    
    int choice;
    int r1, r2, c1, c2;
    int mat1[mx][mx], mat2[mx][mx];
    while (1)
    {
    printf("\nEnter Your Choice :- \n");
    printf("\n1. Add Matrix ");
    printf("\n2. Multiply Matrix ");
    printf("\n3. Transpose Matrix ");
    printf("\n0. Exit \n");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2)
    {
        printf("\nEnter Matrix 1 row size :- ");
        scanf("%d", &r1);
        printf("\nEnter Matrix 1 column size :- ");
        scanf("%d", &c1);
        printf("\nEnter Matrix 2 row size :- ");
        scanf("%d", &r2);
        printf("\nEnter Matrix 2 column size :- ");
        scanf("%d", &c2);
    }

    switch (choice)
    {
    case 1:
        if (r1 == r2 && c1 == c2)
        {
            printf("\n Enter matrix 1 :- ");
            inpMat(mat1, r1, c1);
            printf("\n Enter matrix 2 :- ");
            inpMat(mat2, r2, c2);
            printf("\nmatrix 1 + matrix 2 is:- \n");
            printSum(mat1, mat2, r1, c2);
        }
        else
        {
            printf("\nMatrix Addition not possible...\n");
        }
        break;

    case 2:
        if (c1 == r1)
        {

            printf("\n Enter matrix 1 :- ");
            inpMat(mat1, r1, c1);
            printf("\n Enter matrix 2 :- ");
            inpMat(mat2, r2, c2);
            printf("\n matrix 1 * matrix 2 is:- \n");
            printMul(mat1, mat2, r1, c2);
        }
        else
        {
            printf("\nMatrix Multiplication Not Possible....\n");
        }
        break;

    case 3:
        printf("\nEnter Matrix row size :- ");
        scanf("%d", &r1);
        printf("\nEnter Matrix column size :- ");
        scanf("%d", &c1);
        printf("\nEnter Matrix  :- ");
        inpMat(mat1, r1, c1);
        printf("\nMatrix Transpose  :- ");
        transposeMat(mat1, r1, c1);
        break;
    
    case 0:
        printf("Exit Successfully...");
        exit(1);

    default:
        printf("Not a Valid Choice");
    }
    }

    return 0;
}