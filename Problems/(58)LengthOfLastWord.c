int lengthOfLastWord(char* s) {
    int size = 0;
    for (int i = 0; s[i] != '\0'; i++)
    { 
        if(i == 0 || (s[i] != ' ' && s[i-1] == ' '))
            size = 0;
        if(s[i] != ' ') size++;
    }
    return size;
}