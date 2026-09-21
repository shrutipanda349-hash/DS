//Delete any element chosen by the user from a matrix
#include <stdio.h>

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int r, c;

    
    printf("Enter row (0-2) and column (0-2): ");
    scanf("%d %d", &r, &c);

    
    matrix[r][c] = 0;

    
    printf("\nUpdated Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
