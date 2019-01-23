/*
===============================================================
Name        : main.c
Author      : Michael Kandziora
Version     : v1.0
Description : Merge-sort C-program
===============================================================
*/

/****************************************************/
/*					    LIBRARIES   				*/
/****************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/****************************************************/
/*				     MERGE FUNCTIONS    			*/
/****************************************************/
//----------------------------------------------------
/**                   merge                        **/
/*
    DESCRIPTION:    | Merges two subarrays of arr[]
                      First subarray is arr[l..m]
                      Second subarray is arr[m+1..r]

    PARAMETER:      | the main Array ,
                      the actual left corner,
                      the middle,
                      the actual right cornor

    RETURN:         | void

    BUGS:           | unknown
*/

void merge(long long arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    long long *L = malloc(sizeof(double)*n1);
    long long *R = malloc(sizeof(double)*n2);

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(R);
    free(L);
}

//----------------------------------------------------
/**                   mergeSort                    **/
/*
    DESCRIPTION:    |

    PARAMETER:      | the main Array ,
                      the actual left index,
                      the actual right index

    RETURN:         | void

    BUGS:           | unknown
*/

void mergeSort(long long arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2;

        // Sort first and second halves 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/****************************************************/
/*				     UTILITY FUNCTIONS    			*/
/****************************************************/
//----------------------------------------------------
/**                   printArray                   **/
/*            Function to print an array            */
void printArray(long long A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%lld ", A[i]);
    printf("\n");
}
//----------------------------------------------------
/**                   rand Array                   **/
/*   Function to fill an array with random values   */
void randArray(long long A[], int size, int max){
    int i;
    long long x;
    for(i = 0; i < size; i++){
        x = rand()%max;
        A[i] = x << rand()%max;
    }
}

/****************************************************/
/*				     MAIN FUNCTION      			*/
/****************************************************/
int main()
{
    clock_t start_t, end_t;
    double cpu_time_used;


    // MAX SIZE BEFORE BUG CRASH: 1048365
    int arr_size = 1000000000;
    long long* arr = malloc(sizeof(long long)*arr_size);

    if(arr ==  0){return 0;}

    randArray(arr, arr_size, RAND_MAX);

    //printf("Given array is \n");
    //printArray(arr, arr_size);

    start_t = clock();
    printf("Starting: mergeSort(), start_t = %ld\n", start_t);
    mergeSort(arr, 0, arr_size - 1);
    end_t = clock();
    printf("End: mergeSort(), end_t = %ld\n", end_t);

    cpu_time_used = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Total time taken by CPU: %f sec\n", cpu_time_used  );

    //printf("\nSorted array is \n");
    //printArray(arr, arr_size);

    free(arr);
    return 0;
} 
