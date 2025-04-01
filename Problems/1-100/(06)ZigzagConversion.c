#include <memory>
#include <string>

char* convert(char* s, int numRows) {
    if(numRows == 1) return strdup(s);
    int sizeOfArray = strlen(s), current = 0, row = 0, col = 0;
    char* output = malloc(sizeOfArray+ 1);

    char** matrix = malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = malloc(sizeOfArray);
        memset(matrix[i], 0, sizeOfArray);
    }

    char down = 1;

    while (s[current] != '\0')
    {
        matrix[row][col] = s[current++];

        if(down){
            row++;
            if(row == numRows){
                row = numRows-2;
                col++;
                down = 0;
            }
        } else {
            row--;
            col++;
            if(row < 0){
                row = 1;
                down = 1;
            }
        }
    }

    current = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int g = 0; g < sizeOfArray; g++)
        {
            if (matrix[i][g] != 0){
                output[current++] = matrix[i][g];
            }
        }
    }
    output[sizeOfArray] = '\0';
    return output;
}