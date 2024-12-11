#include <stdio.h>

int timUCLN(int a, int b) {
    if(a == 0 || b == 0){
      return a + b;
    }
    int min = a < b ? a : b;
    for(int i = min; i >= 1; i--){
        if(a % i == 0 && b % i == 0){
        	return i;
      	}
   	}
   return 1;
}
int main() {
    int num1, num2;
    
    printf("Nhap so nguyen 1: ");
    scanf("%d", &num1);
    printf("Nhap so nguyen 2: ");
    scanf("%d", &num2);
    
    
    printf("UCLN cua %d va %d la: %d\n", num1, num2, timUCLN(num1, num2));
    
    return 0;
}
