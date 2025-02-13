#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool isValid(char* s) {
    int length = strlen(s);
    char *stack = malloc(length + 1);
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        switch(s[i]){
            case '(':
            case '[':
            case '{':
                stack[++top] = s[i];
                break;
            case ')':
                if (top == -1 || stack[top] != '(') return false;
                top--;
                break;
            case ']':
                if (top == -1 || stack[top] != '[') return false;
                top--;
                break;
            case '}':
                if (top == -1 || stack[top] != '{') return false;
                top--;
                break;
        }
    }

    return top == -1;
}