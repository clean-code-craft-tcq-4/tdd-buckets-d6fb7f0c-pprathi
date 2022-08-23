#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SortSamples.h"
#include "RangeOccurence.h"

extern tdd_st rangeValues_st[20];

void testSorting(void){
	int testSamples[] = {7,8,4,5};
	int array_size = sizeof(testSamples)/sizeof(testSamples[0]);

	CheckSortingAndSwap(&testSamples[1], &testSamples[2]);
	assert(testSamples[1]== 4);
	assert(testSamples[2]== 8);

	sortCurrentSamples(testSamples, array_size);
	assert(testSamples[0]== 4);
	assert(testSamples[1]== 5);
	assert(testSamples[2]== 7);
	assert(testSamples[3]== 8);
}

void testRangeOccurence(void){
	int testSamples[] = {2, 3, 8, 9, 10};
	int array_size = sizeof(testSamples)/sizeof(testSamples[0]);
	int num = 8;
	int index = 3;
	checkConsecutiveNum(testSamples, &num, &index, 3);
	assert(rangeValues_st[3].rangeHighIndex == 9);
	assert(rangeValues_st[3].rangeCount == 1);

	num = 3;
	index = 2;
	checkConsecutiveNum(testSamples, &num, &index, 2);
	assert(rangeValues_st[2].rangeHighIndex == 0);
	assert(rangeValues_st[2].rangeCount == 0);

	checkNextConsecutiveNum(testSamples, &num, &index, 2);
	assert(rangeValues_st[3].rangeLowIndex == 8);
	assert(rangeValues_st[3].rangeHighIndex == 8);
	assert(rangeValues_st[3].rangeCount == 1);

	checkRangeOccurence(testSamples, array_size);
	assert(rangeValues_st[0].rangeLowIndex == 2);
	assert(rangeValues_st[0].rangeHighIndex == 3);
	assert(rangeValues_st[0].rangeCount == 2);
	assert(rangeValues_st[1].rangeLowIndex == 8);
	assert(rangeValues_st[1].rangeHighIndex == 10);
	assert(rangeValues_st[1].rangeCount == 3);
}

void testConsecutiveNumRange(void){
	int testSamples[] = {3, 3, 5, 4, 10, 11, 12};
	int array_size = sizeof(testSamples)/sizeof(testSamples[0]);
	DisplayConsecutiveNumRange(testSamples, array_size);
	assert(rangeValues_st[0].rangeLowIndex == 3);
	assert(rangeValues_st[0].rangeHighIndex == 5);
	assert(rangeValues_st[0].rangeCount == 4);
	assert(rangeValues_st[1].rangeLowIndex == 10);
	assert(rangeValues_st[1].rangeHighIndex == 12);
	assert(rangeValues_st[1].rangeCount == 3);
}

void testfunctions(void){
	testSorting();
	testRangeOccurence();
	testConsecutiveNumRange();
}

int main(void) {
	int currentSamples[] = {3, 3, 5, 4, 10, 11, 12};
	int array_size = sizeof(currentSamples)/sizeof(currentSamples[0]);

	DisplayConsecutiveNumRange(currentSamples, array_size);
	testfunctions();
}
