Aim: To search for a given element in an array using Binary Search (Recursion) and measure the execution time.

Algorithm: BINARY_SEARCH(arr, low, high, key)

Start
If low > high then
  Print "Element not found" and return

mid ← (low + high) / 2

If arr[mid] == key then
  Print "Element found at position mid+1" and return

Else if key < arr[mid] then
  Call BINARY_SEARCH(arr, low, mid-1, key)

Else
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
    int a[10000], n = 10000, key, i;
    clock_t start, end;

    // Generate sorted elements (important for Binary Search)
    for (i = 0; i < n; i++)
        a[i] = i;  

    key = rand() % 10000;

    printf("Searching for element: %d\n", key);

    start = clock();

    bs(a, 0, n - 1, key);

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total time taken: %lf seconds\n", time_taken);

    return 0;
}

Sample Output:

Searching for element: 457
Element found at position 458
Total time taken: 0.000001 seconds

Result: Thus, the element is searched successfully using Binary Search (Recursion), and execution time is calculated.
