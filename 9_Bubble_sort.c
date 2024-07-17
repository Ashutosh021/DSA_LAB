// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[5] = {64, 25, 12, 22, 11};
//     int i, j,temp=0,n=5;

//     // Bubble sort
//     for (i = 0; i < (n-1); i++)
//     {
//        int  swap=0;
//         for (j = 0; j <(n-1-i) ; j++)
//         {
//             if(arr[j]>arr[j+1])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//                 swap++;
//             }
//         }
//         if(swap==0)
//         {
//             break;
//         }
//     }
//     for (i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

#include <stdio.h>

int main()
{
    int arr[5] = {4, 7, 2, 9, 5};
    int i, j;
    for (j = 0; j < 5; j++)
    {
        int sortHai = 0;
        for (i = 0; i < 5; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sortHai++;
            }
        }
        if (sortHai == 0)
        {
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}
