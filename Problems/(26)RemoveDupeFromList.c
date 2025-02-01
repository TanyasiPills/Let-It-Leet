int removeDuplicates(int* nums, int numsSize) {
    int index = 0;

    for (int i = 0; i < numsSize-1; i++)
    { 
        if(nums[index] != nums[i+1])
        {
            index++;
            nums[index] = nums[i+1];
        }
    }
    
    return index+1;
}