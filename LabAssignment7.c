#include <stdio.h>
#include <stdlib.h>
typedef struct element{
    int data;
    int numswaps;
} element;

element* numSwapsBubbleSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element)*size);
    for(int i = 0; i < size; i++){
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    bubbleSort(swaps, size);

    for(int i = 0; i < size; i++)
        {
            printf("%d: ", swaps[i].data);
            printf("%d\n", swaps[i].numswaps);
        }
}

element* numSwapsSelectionSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element)*size);
    for(int i = 0; i < size; i++){
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }


    selectionSort(swaps, size);

    for(int i = 0; i < size; i++)
        {
            printf("%d: ", swaps[i].data);
            printf("%d\n", swaps[i].numswaps);
        }
}


int main()
{
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arr3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;

    printf("Array1 Bubble Sort:\n");
    numSwapsBubbleSort(arr,n);
    printf("\n");

    printf("Array2 Bubble Sort:\n");
    numSwapsBubbleSort(arr2, n);
    printf("\n");



    printf("Array1 Selection Sort:\n");
    numSwapsSelectionSort(arr3, n);

    printf("\nArray2 Selection Sort:\n");
    numSwapsSelectionSort(arr4, n);
}

void bubbleSort(element arr[], int n)
{
   element temp;
   int i, j, totalswaps = 0;
   for (i = 0; i < n-1; i++)
   {
        for (j = 0; j < n-i-1; j++)
        {

           if (arr[j].data > arr[j+1].data)
           {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
             arr[j].numswaps++;
             arr[j+1].numswaps++;
             totalswaps++;
           }

        }
    }
    printf("Total Swaps: %d\n", totalswaps);
}

void selectionSort(element arr[], int n)
{
	int i, j, min_idx, totalswaps = 0;
    element temp;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j].data < arr[min_idx].data)
			min_idx = j;

        if(min_idx != i)
        {
            totalswaps++;
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            arr[i].numswaps++;
            arr[min_idx].numswaps++;
        }
	}
    printf("Total Swaps: %d\n", totalswaps);
}
