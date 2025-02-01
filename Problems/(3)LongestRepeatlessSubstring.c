int lengthOfLongestSubstring(char* s) {
    int characterArray[128] = {0};
    int lastTime = 0, maxLenght = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char character = s[i];
        if(characterArray[character] > lastTime){
            lastTime = characterArray[character];
        }
        characterArray[character] = i+1;
        int lenght = i - lastTime + 1;

        if(lenght > maxLenght){
            maxLenght = lenght;
        }
    }

    return maxLenght;
}