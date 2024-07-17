#include <stdio.h>  
  
/* Function to merge the subarrays of arr[] */  
void merge(int arr[], int s, int m, int e)    
{    
    int i, j, k;  
    int n1 = m - s + 1;    
    int n2 = e - m;    
      
    int lArr[n1], rArr[n2]; //temporary arrays  
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
    lArr[i] = arr[s + i];    
    for (int j = 0; j < n2; j++)    
    rArr[j] = arr[m + 1 + j];    
      
    i = 0; /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = s;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(lArr[i] <= rArr[j])    
        {    
            arr[k] = lArr[i];    
            i++;    
        }    
        else    
        {    
            arr[k] = rArr[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        arr[k] = lArr[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        arr[k] = rArr[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int arr[], int s, int e)  
{  
    if (s < e)   
    {  
        int m = (s + e) / 2;  
        mergeSort(arr, s, m);  
        mergeSort(arr, m + 1, e);  
        merge(arr, s, m, e);  
    }  
}  
  
/* Function to print the array */  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  
  
int main()  
{  
    int arr[] = { 12, 31, 25, 8, 32, 17, 40, 42 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    printf("Before sorting array elements are - \n");  
    printArray(arr, n);  
    mergeSort(arr, 0, n - 1);  
    printf("After sorting array elements are - \n");  
    printArray(arr, n);  
    return 0;  
} 