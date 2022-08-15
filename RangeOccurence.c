#include <stdio.h>
#include <stdlib.h>
#include "SortSamples.h"
#include "RangeOccurence.h"

tdd_st rangeValues_st[20];
int rangeNumIndex = 0;

int checkRangeOccurence(int index, int currentSamples[], int *rangeLowIndex, int *rangeHighIndex, int *rangeCount){
	int matchStatus = 0;
	if((currentSamples[index] + 1 == currentSamples[index+1]) || (currentSamples[index] == currentSamples[index+1])){
			*rangeHighIndex = currentSamples[index+1];
			*rangeCount = *rangeCount+1;
			matchStatus = 1;
	}
	return matchStatus;
}

void skipSingleOccurence(int index, int currentSamples[], int *matchstatus, int *rangeLowIndex, int *rangeCount){
	if(*rangeCount == 1){
		*matchstatus = 1;
		*rangeLowIndex = currentSamples[index+1];
	}
}

void displayRangeOccurence(int index, int matchStatus, int currentSamples[], int array_size, int *rangeLowIndex, int *rangeHighIndex, int *rangeCount){
	skipSingleOccurence(index, currentSamples, &matchStatus, rangeLowIndex, rangeCount);
	if((matchStatus != 1) || (index + 1 == array_size-1)){
		rangeValues_st[rangeNumIndex].rangeLowIndex = *rangeLowIndex;
		rangeValues_st[rangeNumIndex].rangeHighIndex = *rangeHighIndex;
		rangeValues_st[rangeNumIndex].rangeCount = *rangeCount;
		printf("\nRange %d - %d , %d", rangeValues_st[rangeNumIndex].rangeLowIndex,
				rangeValues_st[rangeNumIndex].rangeHighIndex, rangeValues_st[rangeNumIndex].rangeCount);
		*rangeLowIndex = currentSamples[index+1];
		*rangeHighIndex = currentSamples[index+1];
		*rangeCount = 1;
		rangeNumIndex++;
	}
}

void checkConsecutiveNumbers(int currentSamples[], int array_size){
	int index = 0, rangeCount = 1, matchStatus = 0;
	int rangeLowIndex = currentSamples[0];
	int rangeHighIndex = currentSamples[0];
	rangeNumIndex = 0;

	while(index < array_size - 1){
		matchStatus = checkRangeOccurence(index, currentSamples, &rangeLowIndex, &rangeHighIndex, &rangeCount);
		displayRangeOccurence(index, matchStatus, currentSamples, array_size, &rangeLowIndex, &rangeHighIndex, &rangeCount);
		index++;
	}
}

void DisplayConsecutiveNumRange(int currentSamples[], int array_size){
	sortCurrentSamples(currentSamples, array_size);
	checkConsecutiveNumbers(currentSamples, array_size);
}
