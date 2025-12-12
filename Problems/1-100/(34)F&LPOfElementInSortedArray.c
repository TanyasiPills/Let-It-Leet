#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* returner = malloc(sizeof(int)*2);
    returner[0] = -1;
    returner[1] = -1;
    *returnSize = 2;

    if(numsSize == 0) return returner;

    int upper = numsSize;
    int lower = 0;
    int tmp;
    
    //will close in on the lower bound of the targer
    while(lower<upper){
        int middle = (lower+upper) / 2;
        if(nums[middle] < target) lower = middle + 1;
        else upper = middle;
    }
    tmp = lower;

    upper = numsSize;
    lower = 0;

    //will close onto the correct place +1 bc it can equal the num so it will climb up until it does not
    while(lower<upper){
        int middle = (lower+upper) / 2;
        if(nums[middle] <= target) lower = middle + 1;
        else upper = middle;
    }

    if(tmp < numsSize && nums[tmp] == target){
        returner[0] = tmp;
        returner[1] = lower-1;
    }

    return returner;
}