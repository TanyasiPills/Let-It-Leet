#include <stdlib.h>

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int),compare);
    short columnsize = 0;
    int** returnArray = (int**)malloc(sizeof(int*));
    *returnColumnSizes = (int*)malloc(sizeof(int));
    for (short i = 0; i < numsSize; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for (short j = i+1; j < numsSize; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue;

            short start = j+1;
            short end = numsSize-1;

            while(start < end){
                long long sum = (long long)nums[i] + nums[j] + nums[start] + nums[end];

                if(sum == target){
                    returnArray = (int**)realloc(returnArray, (columnsize+1) * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, (columnsize+1) * sizeof(int*));
                    returnArray[columnsize] = (int*)malloc(4 * sizeof(int));
                    returnArray[columnsize][0] = nums[i];
                    returnArray[columnsize][1] = nums[j];
                    returnArray[columnsize][2] = nums[start];
                    returnArray[columnsize][3] = nums[end];

                     (*returnColumnSizes)[columnsize] = 4;

                    columnsize++;

                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;
                }
                if(sum > target) end--;
                else start++;
            }
        }
        
    }
    *returnSize = columnsize;
    return returnArray;
}