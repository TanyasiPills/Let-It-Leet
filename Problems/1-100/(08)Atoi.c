#include <limits.h>

int myAtoi(char* s) {

    long long result = 0;
    char number = 0;
    char negative = 0;

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(result >= LLONG_MAX/10 && negative) return INT_MIN;
        if(result >= LLONG_MAX/10) return INT_MAX;
        if(s[i] == ' ' && !number) continue;
        if(s[i] == ' ' && number) break;
        if(s[i] == '-' && number) break;

        if(s[i] == '-' && !number) {
            number = 1;
            negative = 1;
            continue;
        }

        if(s[i] == '+' && !number){
            number = 1;
            continue;
        }

        if(s[i] < '0' || s[i] > '9') break; 

        if(!number) number = 1;

        result *= 10;
        result += s[i] - '0';
    }

    if(negative) result *= -1;

    if(result < INT_MIN) return INT_MIN;
    if(result > INT_MAX) return INT_MAX;
    
    return result;
}