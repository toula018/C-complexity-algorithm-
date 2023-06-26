#include <stdio.h>
#include <time.h>




long long int  iterativeDichotomie(int T[], double x, long long int length){
	long long int left = 0;
	long long int right = length - 1;
	long long int mid;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if(x == T[mid])
			return mid;
		else{
			if(x < T[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return -1;
}


long long int recursiveDichotomie(int T[], double x, long long int left, long long int right){

	if(left > right){
		
		
		return -1;
	}
	
	long long int mid = left + (right - left) / 2;
	if(x == T[mid]){
		
		return mid;
	}
	else 
		if(x < T[mid]) 
			return recursiveDichotomie(T, x, left, mid - 1);
		else 
			return recursiveDichotomie(T, x, mid + 1, right);
}


int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num = 22;
    int right=n-1;
    int left=0;

    clock_t Time;
    Time= clock();

    int iterativeResult = iterativeDichotomie(arr, num, n);

	Time = clock()-Time;
    double time_taken = ((double)Time)/CLOCKS_PER_SEC; 

    printf("using the iterative one : ");
    (iterativeResult == -1)? printf("\nElement is not present in array")
    : printf("\nElement is present at index %d", iterativeResult);
   
    printf("\nThe iterative one took %f seconds to execute \n", time_taken);

    Time= clock();

    int recursiveResult = recursiveDichotomie(arr, num, left ,right);

    Time = clock()-Time;
    time_taken = ((double)Time)/CLOCKS_PER_SEC; 
   
    printf("\nusing the recursive one : ");
    (recursiveResult== -1)? printf("\nElement is not present in array")
    : printf("\nElement is present at index %d", recursiveResult);
    printf("\nThe recursive one took %f seconds to execute \n", time_taken);

}