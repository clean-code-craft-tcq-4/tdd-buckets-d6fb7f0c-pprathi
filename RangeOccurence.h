typedef struct{
int rangeLowIndex;
int rangeHighIndex;
int rangeCount;
}tdd_st;

void checkNextConsecutiveNum(int currentSamples[], int *ptr_num, int *ptr_index, int position);
void checkConsecutiveNum(int currentSamples[], int *ptr_num, int *ptr_index, int position);
void checkRangeOccurence(int currentSamples[], int array_size);
void DisplayConsecutiveNumRange(int currentSamples[], int array_size);
