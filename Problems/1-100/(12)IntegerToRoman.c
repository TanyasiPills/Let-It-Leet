char* intToRoman(int num) {
    char* value = (char*)malloc(20);
    int index = 0;

    int values[] =    {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcpy(value + index, symbols[i]);
            index += strlen(symbols[i]);
            num -= values[i];
        }
    }

    value[index] = '\0';

    return value;
}