#include <stdbool.h>

int searchInsert(int* nums, int numsSize, int target) {
    bool run = true;
    int stepSize = numsSize / 2;
    int index = stepSize;
    
    if(numsSize == 1){
        if(target > nums[0]) return 1;
        else return 0;
    }

    while(true){
        stepSize = stepSize / 2;
        if(stepSize <= 0) stepSize = 1;

        if((nums[index]> target && nums[index-1]< target) || nums[index] == target){
            return index;
        }
        
        if(nums[index] > target)
            index -= stepSize;
            if(index <= 0) return 0;
        else if(nums[index] < target)
            index += stepSize;
            if(index >= numsSize) return index;
    }
}