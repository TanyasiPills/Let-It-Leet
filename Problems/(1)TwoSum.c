#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    for (short i = 0; i < numsSize; i++)
    {
        for (short o = i+1; o < numsSize; o++)
        {
            if(nums[i] + nums[o] == target){
                    
                result[0] = i;
                result[1] = o;
                *returnSize = 2;
                return result;
            }
        }
        
    }
    *returnSize = 0;
    return NULL;
}