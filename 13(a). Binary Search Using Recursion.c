Aim: To search for a given element in an array using Binary Search (Recursion) and measure the execution time.

Algorithm: BINARY_SEARCH(arr, low, high, key)

Start
Step 1: If low > high
  Print "Element not found" and return.

Step 2: Find middle position
  mid ← (low + high) / 2

Step 3: If arr[mid] = key
  Print "Element found at position mid+1" and return.

Step 4: If key < arr[mid]
  Call BINARY_SEARCH(arr, low, mid-1, key)

Step 5: Else
  Call BINARY_SEARCH(arr, mid+1, high, key)

Stop

Program:

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bs(int a[], int low, int high, int key)
{
    if (low > high)
        printf("Element not found\n");
    else
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            printf("Element found at position %d\n", mid + 1);

        else if (key < a[mid])
            bs(a, low, mid - 1, key);

        else
            bs(a, mid + 1, high, key);
    }
}

int main()
{
    int a[100], n, key, i;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (in sorted order for binary search):\n", n);

    for(i=0; i<n; i++)
    {
        printf("Element[%d]: ", i+1);
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d",&key);

    start = clock();

    bs(a,0,n-1,key);

    end = clock();

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Total time taken: %lf seconds\n",time_taken);

    return 0;
}
