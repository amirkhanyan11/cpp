#include <stdio.h>

void swap(int* a, int* b) {
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int a = 21;
    int b = 3;

    printf("Before: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("After: a = %d, b = %d\n", a, b);
}