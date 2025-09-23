#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <string.h>

char* map[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void Propegate(char* text, char* digits, char** result, int index, int* returnSize){
    if(index == strlen(digits)){
        result[*returnSize] = strdup(text);
        (*returnSize)++;
        return;
    }

    int num = digits[index]-'0';
    for (int x = 0; x < strlen(map[num]); x++)
    {
        text[index] = map[num][x];
        Propegate(text, digits, result, index+1, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int inputSize = strlen(digits);

    if(!digits || inputSize == 0) return NULL;

    int size = 0;
    char** result = malloc(sizeof(char*) * pow(4, inputSize));
    char* current = malloc(sizeof(char)*(inputSize+1));
    current[inputSize] = '\0';

    Propegate(current, digits, result, 0, returnSize);

    free(current);
    
    return result;
}