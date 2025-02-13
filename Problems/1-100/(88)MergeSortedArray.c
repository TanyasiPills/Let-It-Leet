void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int left = m-1, right = n-1;
    int i = nums1Size - 1;
    while(right >= 0){
        if(left >= 0 && nums1[left] > nums2[right]){
            nums1[i--] = nums1[left--];
        }
        else{
            nums1[i--] = nums2[right--];
        }
    }
}