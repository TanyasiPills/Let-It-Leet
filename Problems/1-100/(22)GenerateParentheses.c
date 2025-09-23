#include <stdlib.h>
#include <math.h>
#include <string.h>

double Factorial(int input){
    double result = 1;
    for (size_t i = input; i > 0; i--)
    {
        result *= i;
    }
    return result;
}

void Propegate(char** result, char* current, int op, int cl, int* resultSize, int index){
    if(op == 0 && cl == 0){
        result[*resultSize] = strdup(current);
        (*resultSize)++;
        return;
    }

    if(op > 0){
        current[index] = '(';
        Propegate(result, current, op-1, cl, resultSize, index+1);
    }
    if(cl > op){
        current[index] = ')';
        Propegate(result, current, op, cl-1, resultSize, index+1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    if(n < 1) return NULL;

    *returnSize = 0;
    int op = n, cl = n;

    char** result = malloc(sizeof(char*) * (Factorial(n)));
    char* current = malloc(sizeof(char)*(2*n+1));
    current[2*n] = '\0';

    Propegate(result, current, op, cl, returnSize, 0);

    free(current);

    return result;
}