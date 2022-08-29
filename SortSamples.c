#include <stdio.h>
#include <stdlib.h>
#include "SortSamples.h"

void CheckSortingAndSwap(int *ptr_num1, int *ptr_num2){
	int temp = 0;
	if (*ptr_num1 > *ptr_num2){
		temp = *ptr_num1;
		*ptr_num1 = *ptr_num2;
		*ptr_num2 = temp;
	}
}

void iterateCurrentSamples(int i, int currentSamples[], int array_size){
	int j=0;
	for (j = i+1; j < array_size; j++)
	{
		CheckSortingAndSwap(&currentSamples[i], &currentSamples[j]);
	}
}

void sortCurrentSamples(int currentSamples[], int array_size){
	int i = 0;

	for (i = 0; i < array_size - 1; i++)
	{
		iterateCurrentSamples(i, currentSamples, array_size);
	}
}
