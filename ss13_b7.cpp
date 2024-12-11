#include <stdio.h>

void createArr(int rows, int cols, int arr[100][100]) {  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}


void printArr(int rows, int cols, int arr[100][100]) {
    printf("\nin ra mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    
    printf("nhap so hag: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    
    int arr[100][100];
    
    createArr(rows, cols, arr);
    
    printArr(rows, cols, arr);
    
    return 0;
}
