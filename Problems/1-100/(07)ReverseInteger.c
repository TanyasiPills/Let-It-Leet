#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int reverse(int x){
    bool negative = x < 0;
    long long result = 0;
    while( x > 0 || x < 0){
        result *= 10;
        result += x % 10;
        x /= 10;
    }
    if(negative && result > 0) result *= -1;
    if(result > INT_MAX || result < INT_MIN) return 0;
    return result;
}