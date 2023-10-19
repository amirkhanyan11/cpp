#include <stdio.h>


char* strcpy(const char* src, char* dest) {
    
    char* t_dest = dest;

    while(*src != '\0') {
        *(t_dest++) = *(src++);
    }
    
    *t_dest = '\0';

    return dest;
}


void print_str(const char* str) {

    while(*str) {
        printf("%c", *(str++));
    }

    printf("\n");
    return;
}

int main() {

    char first[] = "hello";
    char second[] = "aaaaaaaaaaaaaaa";

    print_str(second);

    print_str(strcpy(first, second));

    return 0;

}