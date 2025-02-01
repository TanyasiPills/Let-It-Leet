int lengthOfLongestSubstring(char* s) {
    int size = sizeof(s);
    char lastChar = '\0';
    int count = 0;
    int top = 0;
    for (int i = 0; i < size; i++)
    {
        count++;
        if(lastChar == s[i]){
            if(count > top) top = count;
            count = 0;
        }
        lastChar = s[i];
    }
    return top;
}