
#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void nhapMang(int arr[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void inMang(int arr[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inGoc(int arr[100][100], int m, int n) {
    printf("arr[0][0] = %d\n", arr[0][0]);
    printf("arr[0][%d] = %d\n", n - 1, arr[0][n - 1]);
    printf("arr[%d][0] = %d\n", m - 1, arr[m - 1][0]);
    printf("arr[%d][%d] = %d\n", m - 1, n - 1, arr[m - 1][n - 1]);
}

void inBien(int arr[100][100], int m, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[0][i]);
    }
    for (int i = 1; i < m - 1; i++) {
        printf("%d ", arr[i][n - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[m - 1][i]);
    }
    for (int i = m - 2; i > 0; i--) {
        printf("%d ", arr[i][0]);
    }
    printf("\n");
}

void inDuongCheo(int arr[100][100], int m, int n) {
    for (int i = 0; i < m && i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    for (int i = 0; i < m && i < n; i++) {
        printf("%d ", arr[i][n - i - 1]);
    }
    printf("\n");
}

void inSNT(int arr[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int arr[100][100], m, n;
    int choice;

    printf("Nhập số hàng của ma trận: ");
    scanf("%d", &m);
    printf("Nhập số cột của ma trận: ");
    scanf("%d", &n);

    do {
        printf("\nMENU\n");
        printf("1. Nhập giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In ra các phần tử ở góc theo ma trận\n");
        printf("4. In ra các phần tử nằm trên đường biên theo ma trận\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
        printf("6. In ra các phần tử là số nguyên tố theo ma trận\n");
        printf("7. Thoát\n");
        printf("Chọn một tùy chọn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, m, n);
                break;
            case 2:
                inMang(arr, m, n);
                break;
            case 3:
                inGoc(arr, m, n);
                break;
            case 4:
                inBien(arr, m, n);
                break;
            case 5:
                inDuongCheo(arr, m, n);
                break;
            case 6:
                inSNT(arr, m, n);
                break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 7);

    return 0;
}
