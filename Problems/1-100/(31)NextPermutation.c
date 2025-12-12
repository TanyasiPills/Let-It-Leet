void nextPermutation(int* nums, int numsSize) {
    int x, y;
    for (x = numsSize-2; x >= 0; x--) if(nums[x] < nums[x+1]) break;

    if(x == -1) {
        for (int i = 0; i < numsSize/2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[numsSize-1-i];
            nums[numsSize-1-i] = temp;
        }
    } else{
        for (y = numsSize-1; y > x; y--) if(nums[x] < nums[y]) break;

        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;

        x++;

        int dist = (numsSize-x)/2;

        for (int i = x; i < x+dist; i++)
        {
            int temp = nums[i];
            nums[i] = nums[numsSize-1-(i-x)];
            nums[numsSize-1-(i-x)] = temp;
        }
    }
}