#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
char* addBinary(char* a, char* b) {
    int aLength = strlen(a);
    int bLength = strlen(b);
    int maxLength = fmax(aLength, bLength);
    char* result = malloc((maxLength+2) * sizeof(char));
    result[maxLength + 1] = '\0';
    int carry = 0;
    while(aLength > 0 || bLength > 0){
        int aValue = (aLength > 0 && a[aLength-1] == '1') ? 1 : 0;
        int bValue = (bLength > 0 && b[bLength-1] == '1') ? 1 : 0;
        int sum = (aValue + bValue + carry);
        result[maxLength] = (sum % 2) + '0';
        carry = sum / 2;
        if (aLength > 0) aLength--;
        if (bLength > 0) bLength--;
        maxLength--; 
    }
    if (carry > 0) {
        result[0] = '1';
        return result;
    } else {
        return result + 1;
    }
}