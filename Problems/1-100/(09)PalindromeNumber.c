#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {

    if(x < 0) return false;
    int result = 0, calc = x;
    while(calc > 0){
        if(result >= INT_MAX/10) return false;
        result *= 10;
        result += (calc % 10);
        calc /= 10;
    }
    return result == x;
}