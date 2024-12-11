#include <stdio.h>

void addItem(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) { 
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void printItem(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {  
        printf("Phan tu arr[%d] co gia tri %d\n", i, arr[i]);
    }
}

void insertItem(int arr[], int *size, int pos, int value) {
    int i;
    if (pos < 0 || pos > *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (i = *size; i > pos; i--) {  
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
    printf("Them phan tu thanh cong!\n");
}

void updateItem(int arr[], int size, int pos, int value) {
    if (pos < 0 || pos >= size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    arr[pos] = value;
    printf("Sua phan tu thanh cong!\n");
}

void deleteItem(int arr[], int *size, int pos) {
    int i;
    if (pos < 0 || pos >= *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (i = pos; i < *size - 1; i++) {  
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Xoa phan tu thanh cong!\n");
}

void sortItems(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {  
        for (j = i + 1; j < size; j++) {  
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void searchItem(int arr[], int size, int value) {
    int i, found = 0;
    for (i = 0; i < size; i++) {  
        if (arr[i] == value) {
            printf("Phan tu %d duoc tim thay o vi tri %d\n", value, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang!\n", value);
    }
}

int main() {
    int arr[100];
    int size = 0; 
    int choose;   

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong phan tu va gia tri\n");
        printf("2. In ra cac phan tu trong mang dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o mot vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Moi ban nhap lua chon: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap so luong phan tu: ");
                scanf("%d", &size);
                if (size > 0 && size <= 100) {
                    addItem(arr, size);
                } else {
                    printf("So luong phan tu khong hop le!\n");
                }
                break;
            case 2:
                printItem(arr, size);
                break;
            case 3: {
                int pos, value;
                printf("Nhap vi tri can them (0-%d): ", size);
                scanf("%d", &pos);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertItem(arr, &size, pos, value);
                break;
            }
            case 4: {
                int pos, value;
                printf("Nhap vi tri can sua (0-%d): ", size - 1);
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                updateItem(arr, size, pos, value);
                break;
            }
            case 5: {
                int pos;
                printf("Nhap vi tri can xoa (0-%d): ", size - 1);
                scanf("%d", &pos);
                deleteItem(arr, &size, pos);
                break;
            }
            case 6:
                sortItems(arr, size);
                break;
            case 7: {
                int value;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                searchItem(arr, size, value);
                break;
            }
            case 8:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
                break;
        }
    } while (choose != 8);

    return 0;
}

