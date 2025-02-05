double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int finalLength = nums1Size + nums2Size;
    int* finalList = (int*)malloc(finalLength * sizeof(int));
    int index1 = 0, index2 = 0;
    for (int i = 0; i < finalLength; i++)
    {
        if(index1 < nums1Size && index2 < nums2Size){
            if(nums1[index1] <= nums2[index2]){
                finalList[i] = nums1[index1];
                index1++;
            }
            else{
                finalList[i] = nums2[index2];
                index2++;
            }
        }
        else{
            if(index1 < nums1Size) {
                finalList[i] = nums1[index1];
                index1++;
            }
            else{
                finalList[i] = nums2[index2];
                index2++;
            }
        }

    }
    double median = 0.0;
    if(finalLength %2 == 1){
        median = (double)finalList[finalLength/2];
    } else {
        median = ((double)finalList[finalLength/2] + (double)finalList[finalLength/2-1]) / 2;
    }
    free(finalList);
    return median;
}