#include <stdlib.h>

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int),compare);
    short columnsize = 0;
    int size = 20000;
    int** returnArray = (int**)malloc(size * sizeof(int*));
    *returnColumnSizes = (int*)malloc(size * sizeof(int));
    for (short i = 0; i < numsSize; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        short start = i+1;
        short end = numsSize-1;   

        while(start < end){
            long long sum = (long long)nums[i] + nums[start] + nums[end];
            if(sum == 0){
                    returnArray[columnsize] = (int*)malloc(3 * sizeof(int));
                    returnArray[columnsize][0] = nums[i];
                    returnArray[columnsize][1] = nums[start];
                    returnArray[columnsize][2] = nums[end];

                     (*returnColumnSizes)[columnsize] = 3;

                    columnsize++;

                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;
            }
            if(sum > 0) end--;
            else start++;
        }     
    }
    returnArray = (int**)realloc(returnArray, columnsize * sizeof(int*));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, columnsize * sizeof(int));
    *returnSize = columnsize;
    return returnArray;
}
