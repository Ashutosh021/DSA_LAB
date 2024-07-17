#include <stdio.h>

void inpMat(int arr[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

int main()
{
    int choice;
    int r1, r2, c1, c2;
    printf("Enter Your Choice :- \n");
    printf("\n1. Add Matrix ");
    scanf("%d", &choice);

    printf("\nEnter Matrix 1 row size :- ");
    scanf("%d", &r1);
    printf("\nEnter Matrix 1 column size :- ");
    scanf("%d", &c1);
    printf("\nEnter Matrix 2 row size :- ");
    scanf("%d", &r2);
    printf("\nEnter Matrix 2 column size :- ");
    scanf("%d", &c2);

    int mat1[r1][c1];             //  2 4 35 4
    int mat2[r2][c2];

    // int mat1[10][10];
    // int mat2[10][10];   // 2 4 6  8

    switch (choice)
    {
    case 1:
        if (r1 == r2 && c1 == c2)
        {
            printf("\n Enter matrix 1 :- ");
            inpMat(mat1, r1, c1);
            printf("\n Enter matrix 2 :- ");
            inpMat(mat2, r2, c2);
            printf("\n Printing matrix 1 :- ");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    // printf("\n > %d ", mat1[i][j] + mat2[i][j]);
                    printf("\n > %d r2=%d  c2=%d", mat2[i][j],i,j);
                }
            }
        }
        else
        {
            printf("\nMatrix Addition not possible");
        }
        break;
    }
    return 0;
}