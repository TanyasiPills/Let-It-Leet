#include <stdlib.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    int closestDiff = INT_MAX;
    int closest;

    for (int i = 0; i < numsSize-2; i++)
    {
        for (int x = i+1; x < numsSize-1; x++)
        {
            for (int y = x+1; y < numsSize; y++)
            {
                int sum = nums[i]+nums[x]+nums[y];
                int diff = abs(target-sum);
                if(diff < closestDiff){
                    closest = sum;
                    closestDiff = diff;
                }
            }
        }
    }

    return closest;
}