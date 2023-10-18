#include <stdio.h>
#include <unistd.h>

void ft_div_mod(int a, int b, int* div, int* mod) {
    
    *div = a / b;
    *mod = a % b;
}

void ft_ultimate_div_mod(int* a, int* b) {
    
    int temp = *a;
    *a = (*a / *b);
    *b = (temp % *b);
}

void ft_putstr(char* str) {

    while(*str != '\0') {
        write(1, str++, 1);
    }

}

int ft_strlen(char* str) {

    int count = 0;

    while(*str != '\0') {
        str++;
        count++;
    }


    return count;
}

int main() {

    char str[] = "hello";

   printf("%d\n", ft_strlen(str));

   return 0;
}



