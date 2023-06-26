
#include <time.h>
#include<stdio.h>



char versionChek(int a[],int b[],int n)	{
	int i;
	for(i=0;i<n;i++){
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}

int sortingCheck(int arr[], int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            return 0;
    return 1;
}
 



void sortingAndVersionChek(int a[],int b[], int n){
    int i=0;
	if(sortingCheck(a,n)==1){
     if(i<n && versionChek(a, b, n) == 1){
          printf("The 1st array is version of 2nd one !");
     }else{
		 printf("The 1st array is not version of 2nd one !");
	  }
	}else{
		 printf("The 1st array is not sorted !");
	}

	
}

int main(){
	int a[] = {1, 3,4,5,6,8,10,50,400};
    int  n= sizeof(a)/sizeof(a[0]);
	int b[] = {1, 3,4,5,6,8,10,50,400};
	clock_t Time;
    Time= clock();
    sortingAndVersionChek(a,b,n);
	Time = clock()-Time;
    double time_taken = ((double)Time)/CLOCKS_PER_SEC; 
    printf("\nThe function took %f seconds to execute \n", time_taken);

}