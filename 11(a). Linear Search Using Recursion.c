Aim: To search for a given element in an array using Linear Search (Recursion) and measure the execution time.

Algorithm: LINEAR_SEARCH(arr, begin, stop, key)

Start

Step 1: If begin = stop
  Print "Element not found" and return.

Step 2: If arr[begin] = key
  Print "Element found at position begin+1" and return.

Step 3: Else
  Call LINEAR_SEARCH(arr, begin+1, stop, key)

Stop

Program:

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ls(int a[], int begin, int stop, int search)
{
    if (begin == stop)
        printf("Element not found\n");
    else if (a[begin] == search)
        printf("Element found at position %d\n", begin + 1);
    else
        ls(a, begin + 1, stop, search);
}

int main()
{
    int a[100], n, key, i;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(i=0; i<n; i++)
    {
        printf("Element[%d]: ", i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d",&key);

    start = clock();

    ls(a,0,n,key);

    end = clock();

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Total time taken: %lf seconds\n",time_taken);

    return 0;
}
