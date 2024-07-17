// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[5] = {64, 25, 12, 22, 11};
//     int i, j,temp=0;

//     //selection sort
//     for (i = 0; i < 4; i++)
//     {
//         int min = i;
//         for (j = i+1; j < 5; j++)
//         {
//             if(arr[min]>arr[j])
//             {
//                 min=j;
//             }

//         }
//          if (i!=min)
//             {
//                 temp = arr[i];
//                 arr[i] = arr[min];
//                 arr[min] = temp;
//             }
//     }
//     for (i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

#include<stdio.h>
// #include<conio.h>
int main()
{
    int arr[5] = {4, 7, 2, 9, 5};
    int min, i, j;
    for (i = 0; i < 5; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }



        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}