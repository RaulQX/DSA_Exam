#include <stdio.h>
#include <stdlib.h>

int choose() {
	printf("1 - Insertion\n");
	printf("2 - Bubble\n");
	printf("3 - Select\n");
	printf("4 - Shaker\n");

	int k;
	scanf("%d", &k);
	return k;
}

void printArr(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertionSort(int arr[], int n)  {  
    int i, key, j;  

    for (i = 1; i < n; i++) { 
    	printArr(arr, n); 
        key = arr[i];  
        j = i - 1;  
        // Move elements of arr[0..i-1], 
        // that are    greater than key, to  
        // one position ahead of their  
        // current position 
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  

        arr[j + 1] = key;  
        printArr(arr, n);
    }  
}  

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void SelectSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  		printArr(arr,n);	
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
        printArr(arr,n);	
    }  
}  

void BubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
	    // Last i elements are already in place  
	    for (j = 0; j < n-i-1; j++)  
	        if (arr[j] > arr[j+1]) {
	        	printArr(arr,n);
	        	swap(&arr[j], &arr[j+1]);  
	        	printArr(arr,n);
	        	printf("\n");
	        }
	            
}  

void ShakerSort(int a[], int n)
{
    int swapped = 1;
    int start = 0;
    int end = n - 1;
 
    while (swapped) 
    {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = 0;
 
        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i) 
        {
            if (a[i] > a[i + 1]) {
            	printArr(a, n);
                swap(&a[i], &a[i + 1]);
                swapped = 1;
                printArr(a, n);
            }
        }
 
        // if nothing moved, then array is sorted.
        if (!swapped)
            break;
 
        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = 0;
 
        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;
 
        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) 
        {
            if (a[i] > a[i + 1]) {
            	printArr(a, n);
                swap(&a[i], &a[i + 1]);
                swapped = 1;
                printArr(a, n);
            }
        }
 
        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}
int main ()
{
	int sortingArray[] = {9, 5, 12, 2, 1, 0, 1};
	int arraySize = sizeof(sortingArray)/sizeof(sortingArray[1]);

	switch(choose()) {

		case 1: insertionSort(sortingArray, arraySize);
				break;
		case 2: BubbleSort(sortingArray, arraySize);
				break;
		case 3: SelectSort(sortingArray, arraySize);
				break;
		case 4: ShakerSort(sortingArray, arraySize);
				break;

		default: printf("ayaye\n");
	}


	return 0;
}