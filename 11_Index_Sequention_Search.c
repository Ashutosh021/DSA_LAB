#include<stdio.h>
#define mx 100


int search(int arr[],int size,int target){
    int indexElem[mx];
    int index[mx];
    int idx=0;
    int len=0;
    for(int i=0;i<size;i+=3){
        indexElem[idx]=arr[i];
        index[idx]=i;
        idx++;
        len++;
    }

    printf("\n Index :- \n");
    for(int i=0;i<len;i++){
        printf("%d",index[i]);
    }
    printf("\n Index Elem :- \n");
    for(int i=0;i<len;i++){
        printf("%d",indexElem[i]);
    }
}
 
int main()
{
    int arr[mx],size,target;
    printf("\nEnter array size :- ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter target elem :- ");
    scanf("%d",&target);

    search(arr,size,target);
    return 0;
}