#include <memory>

int expand(char* s, int left, int right){
    while(left >= 0 && s[right] != '\0' && s[left] == s[right]){
        left--;
        right++;
    }
    return right-left-1;
}

char* longestPalindrome(char* s) {
    int position = 0;
    int size = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int longMiddle = expand(s, i, i);
        int longOddMiddle = expand(s, i, i+1);

        int longest = (longMiddle >= longOddMiddle) ? longMiddle : longOddMiddle;

        if(longest > size){
            size = longest;
            position = i-(size-1)/2;
        }
    }
    char* longestPalindromic = malloc(size*sizeof(char)+1);
    strncpy(longestPalindromic, s+position, size);
    longestPalindromic[size] = '\0';
    return longestPalindromic;
}