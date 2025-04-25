int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1;
    int most = 0;

    while(i < j){
        int min = (height[i] < height[j]) ? height[i] : height[j];
        int dist = j - i;
        int tmp = dist * min;
        if(tmp > most) most = tmp;

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return most;   
}