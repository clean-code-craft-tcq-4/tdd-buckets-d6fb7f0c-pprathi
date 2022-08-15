typedef struct{
int rangeLowIndex;
int rangeHighIndex;
int rangeCount;
}tdd_st;

int checkRangeOccurence(int index, int currentSamples[], int *rangeLowIndex, int *rangeHighIndex, int *rangeCount);
void skipSingleOccurence(int index, int currentSamples[], int *matchstatus, int *rangeLowIndex, int *rangeCount);
void displayRangeOccurence(int index, int matchStatus, int currentSamples[], int array_size, int *rangeLowIndex, int *rangeHighIndex, int *rangeCount);
void checkConsecutiveNumbers(int currentSamples[], int array_size);
void DisplayConsecutiveNumRange(int currentSamples[], int array_size);
