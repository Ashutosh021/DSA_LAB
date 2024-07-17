// C program for insertion sort
#include <stdio.h>
// Driver code
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
    int i, temp, j;
	for (i = 1; i < n; i++) 
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
