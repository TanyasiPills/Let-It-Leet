int strStr(char* haystack, char* needle) {
    int index = -1;
    int charCount = 0;

    for (int i = 0; haystack[i] != '\0'; i++)
    {
        if(haystack[i] == needle[charCount])
        {
            index = i;
            for (int g = 0; needle[g] != '\0'; g++)
            {
                if(haystack[i+g] != needle[g])
                    break;
                if(needle[g+1] == '\0') 
                    return index;
            }
        }
    }
    return -1;
}