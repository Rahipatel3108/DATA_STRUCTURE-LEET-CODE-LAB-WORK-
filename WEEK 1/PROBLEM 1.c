/* Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:*/

#include <stdio.h>
int main() {
    int numRows;
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    int triangle[30][30] = {0};
     for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }
   printf("[");
    for (int i = 0; i < numRows; i++) {
        printf("[");
        for (int j = 0; j <= i; j++) {
            printf("%d", triangle[i][j]);
            if (j != i) printf(",");
        }
        printf("]");
        if (i != numRows - 1) printf(",");
    }
    printf("]\n");
 return 0;}

