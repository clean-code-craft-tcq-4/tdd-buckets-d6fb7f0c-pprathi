#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "CurrentSensing.h"

void ConversionForCurrent(int index, float adcValues[], float minRange, float maxRange, int currentSamples[], int maxDigitalValue){
	int adcRange = maxRange - minRange;

	if(adcValues[index] < maxDigitalValue){
		currentSamples[index] = round(adcRange * adcValues[index]/(maxDigitalValue-1));
	}
}

void checkMinRange(int index, float adcValues[], float minRange, float maxRange, int currentSamples[], int maxDigitalValue){
	ConversionForCurrent(index, adcValues, minRange, maxRange, currentSamples, maxDigitalValue);
	if(minRange < 0){
		currentSamples[index] = currentSamples[index] - maxRange;
	}
}

void getCurrentSamples(float adcValues[], int numOfInputs, int bitValue, float minRange, float maxRange, int currentSamples[]){
	int maxDigitalValue = 0;

	maxDigitalValue = pow(2,bitValue) - 1;
	for(int index = 0; index < numOfInputs; index++){
		checkMinRange(index, adcValues, minRange, maxRange, currentSamples, maxDigitalValue);
	}
}
