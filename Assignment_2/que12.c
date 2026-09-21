//Sort a given matrix in ascending order. //
#include <stdio.h>

int main() {
    int matrix[3][3] = {{90, 20, 70}, {40, 50, 60}, {30, 80, 10}};
    int temp[9];
    int k = 0;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[k++] = matrix[i][j];
        }
    }

        for (int i = 0; i < 9 - 1; i++) {
        for (int j = 0; j < 9 - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = temp[k++];
        }
    }

printf("Sorted Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
