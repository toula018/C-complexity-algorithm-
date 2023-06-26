#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float random_float( float min,  float max)
{
   return (max - min) * ((float)rand() / RAND_MAX) + min;
}

void printArray(float arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("t[%d] = %.8f \n", i,arr[i]);
    printf("\n");
}

 
int linearSearch(float arr[], int n, float x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(){
int i,n=50;
float t[n],x;
    for (i = 0; i < n; ++i) {
        t[i]=random_float(-10,10);
    }
    printArray(t,n);
    printf("Enter the number you want search :");
    scanf(" %f", &x);
    clock_t Time;
    Time= clock();
    int result = linearSearch(t, Time, x);
    Time = clock()-Time;
    double time_taken = ((double)Time)/CLOCKS_PER_SEC; 

    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    printf("\nThe function took %f seconds to execute \n", time_taken);
    

}