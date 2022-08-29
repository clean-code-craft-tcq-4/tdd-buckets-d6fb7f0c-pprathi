#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SortSamples.h"
#include "RangeOccurence.h"
#include "CurrentSensing.h"

extern tdd_st rangeValues_st[20];

void testSorting(void){
	int testSamples[] = {7,8,4,5};
	int array_size = sizeof(testSamples)/sizeof(testSamples[0]);

	CheckSortingAndSwap(&testSamples[0], &testSamples[1]);
	assert(testSamples[0]== 7);
	assert(testSamples[1]== 8);

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
	int testSamples[] = {2, 3, 8, 9, 10, 10};
	int array_size = sizeof(testSamples)/sizeof(testSamples[0]);
	int num = 8;
	int index = 3;
	checkConsecutiveNum(testSamples, &num, &index, 3); //8+1 == 9
	assert(rangeValues_st[3].rangeHighIndex == 9);
	assert(rangeValues_st[3].rangeCount == 1);

	num = 10;
	index = 4;
	checkConsecutiveNum(testSamples, &num, &index, 5); //10 == 10
	assert(rangeValues_st[4].rangeHighIndex == 10);
	assert(rangeValues_st[4].rangeCount == 1);

	num = 3;
	index = 2;
	checkConsecutiveNum(testSamples, &num, &index, 2); //3 != 8
	assert(rangeValues_st[2].rangeHighIndex == 0);
	assert(rangeValues_st[2].rangeCount == 0);

	checkNextConsecutiveNum(testSamples, &num, &index, 2); //3+1<8
	assert(rangeValues_st[3].rangeLowIndex == 8);
	assert(rangeValues_st[3].rangeHighIndex == 8);
	assert(rangeValues_st[3].rangeCount == 1);

	num = 10;
	index = 5;
	checkNextConsecutiveNum(testSamples, &num, &index, 5); //10+1 > 10
	assert(rangeValues_st[5].rangeLowIndex == 0);
	assert(rangeValues_st[5].rangeHighIndex == 0);
	assert(rangeValues_st[5].rangeCount == 0);

	checkRangeOccurence(testSamples, array_size);
	assert(rangeValues_st[0].rangeLowIndex == 2);
	assert(rangeValues_st[0].rangeHighIndex == 3);
	assert(rangeValues_st[0].rangeCount == 2);
	assert(rangeValues_st[1].rangeLowIndex == 8);
	assert(rangeValues_st[1].rangeHighIndex == 10);
	assert(rangeValues_st[1].rangeCount == 4);
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

void testCurrentRange(void){
	//test for positive range
	float adcValues[] = {1146, 4094};
	int numOfInputs = sizeof(adcValues)/sizeof(adcValues[0]);
	int currentSamples[numOfInputs];

	checkMinRange(0, adcValues, 0, 10, currentSamples, 4095);
	assert(currentSamples[0] == 3);

	ConversionForCurrent(1, adcValues, 0, 20, currentSamples, 4095);
	assert(currentSamples[1] == 20);

	getCurrentSamples(adcValues, numOfInputs, 12, 0, 10, currentSamples);
	assert(currentSamples[0] == 3);
	assert(currentSamples[1] == 10);

	//test for negative range
	float adc2Values[] = {1022, 511, 0};
	numOfInputs = sizeof(adc2Values)/sizeof(adc2Values[0]);

	checkMinRange(2, adc2Values, -10, 10, currentSamples, 1023);
	assert(currentSamples[2] == -10);

	getCurrentSamples(adc2Values, numOfInputs, 10, -15, 15, currentSamples);
	assert(currentSamples[0] == 15);
	assert(currentSamples[1] == 0);
	assert(currentSamples[2] == -15);
}

void testfunctions(void){
	testSorting();
	testRangeOccurence();
	testConsecutiveNumRange();
	testCurrentRange();
}


int main(void) {
	float adcValues[] = {1146, 1150, 2045, 1700};
	int numOfInputs = sizeof(adcValues)/sizeof(adcValues[0]);
	int currentSamples[numOfInputs];
	getCurrentSamples(adcValues, numOfInputs, 12, 0, 10, currentSamples);

	int array_size = sizeof(currentSamples)/sizeof(currentSamples[0]);
	DisplayConsecutiveNumRange(currentSamples, array_size);
	testfunctions();
}
