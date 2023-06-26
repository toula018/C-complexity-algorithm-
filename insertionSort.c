#include <stdio.h>
#include <time.h>

void insertionSort(int T[], int n){
	int i, k;
	int x;
	for(i = 1 ; i < n ; i++){
	  k = i - 1;
		x = T[i];
		while(k >= 0 && T[k] > x){
			T[k+1] = T[k];
			k = k - 1;
		}
		T[k+1] = x;
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
    insertionSort(arr, n);
	Time = clock()-Time;
    double time_taken = ((double)Time)/CLOCKS_PER_SEC; 

	printf("the sorted array using insertion one : ");
    printArray(arr,n);
	printf("\nThe function took %f seconds to execute \n", time_taken);

}