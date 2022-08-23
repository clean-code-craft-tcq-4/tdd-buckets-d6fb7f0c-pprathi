#include <stdio.h>
#include <stdlib.h>
#include "SortSamples.h"
#include "RangeOccurence.h"

tdd_st rangeValues_st[20];

void checkNextConsecutiveNum(int currentSamples[], int *ptr_num, int *ptr_index, int position){
	if((*ptr_num + 1 < currentSamples[position])){
		printf("\n Range %d - %d , %d", rangeValues_st[*ptr_index].rangeLowIndex, rangeValues_st[*ptr_index].rangeHighIndex, rangeValues_st[*ptr_index].rangeCount);
		*ptr_index = *ptr_index +1;
		rangeValues_st[*ptr_index].rangeLowIndex = currentSamples[position];
		rangeValues_st[*ptr_index].rangeHighIndex = currentSamples[position];
		rangeValues_st[*ptr_index].rangeCount = 1;
		*ptr_num = currentSamples[position];
	}
}

void checkConsecutiveNum(int currentSamples[], int *ptr_num, int *ptr_index, int position){
	if((*ptr_num == currentSamples[position]) || (*ptr_num + 1 == currentSamples[position])){
		rangeValues_st[*ptr_index].rangeCount++;
		*ptr_num = currentSamples[position];
		rangeValues_st[*ptr_index].rangeHighIndex = currentSamples[position];
	}
}

void checkRangeOccurence(int currentSamples[], int array_size){
	int index = 0;
	int num = rangeValues_st[index].rangeLowIndex = currentSamples[0];
	rangeValues_st[index].rangeHighIndex = currentSamples[0];
	rangeValues_st[index].rangeCount = 1;

	for(int position=1; position<array_size; position++){
		checkConsecutiveNum(currentSamples, &num, &index, position);
		checkNextConsecutiveNum(currentSamples, &num, &index, position);
	}
	printf("\n Range %d - %d , %d", rangeValues_st[index].rangeLowIndex, rangeValues_st[index].rangeHighIndex, rangeValues_st[index].rangeCount);
}

void DisplayConsecutiveNumRange(int currentSamples[], int array_size){
	sortCurrentSamples(currentSamples, array_size);
	checkRangeOccurence(currentSamples, array_size);
}
