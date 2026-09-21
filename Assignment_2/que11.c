#include <stdio.h>

int main() {
    int matrix[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int target, found = 0;

    // Get the element to search for
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Search the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == target) {
                printf("Element found at position: Row %d, Column %d\n", i, j);
                found = 1; 
            }
        }
    }

    if (!found) {
        printf("Element not found in the matrix.\n");
    }

    return 0;
}
