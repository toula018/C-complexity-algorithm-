#include <stdio.h>
#include <time.h>

  
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y= temp;
}
  
void selectionSort(int arr[], int n)
{
    int i, j, maxId;
  
    
    for (i = 0; i < n-1; i++)
    {
       
        maxId= i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[maxId])
            maxId = j;
  
       
           if(maxId != i)
            swap(&arr[maxId], &arr[i]);
    }
}
  

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  

int main()
{
    int arr[] = {1, 15, 4, 20, 4, 0, 7, 84, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t Time;
    Time= clock();
    selectionSort(arr, n);
    Time = clock()-Time;
    double time_taken = ((double)Time)/CLOCKS_PER_SEC; 
	printf("the sorted array using selection one : ");
    printArray(arr,n);
    printf("\nThe function took %f seconds to execute \n", time_taken);

}