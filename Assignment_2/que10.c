//Insert an element in a matrix at a given index.//
 #include <stdio.h>

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int r, c, newValue;

    
    printf("Enter row (0-2), column (0-2), and new value: ");
    scanf("%d %d %d", &r, &c, &newValue);

    matrix[r][c] = newValue;

    printf("\nUpdated Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
