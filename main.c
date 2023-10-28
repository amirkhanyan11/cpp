#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

// write malloc free open close read



int my_pow(int num, int exponent) {

    int res = 1;

    while(exponent > 0) {

        res = num * res,  exponent--;
    }

    return res;
}

int calculate_exponent(int num) {

    int t_num = num;

    int exponent = 0;

    while(t_num > 0) {

        exponent++, t_num /= 10;

    }

    return exponent - 1;
}

int reverse(int num) {

    int res = 0;


    while(num > 0) {

        res = (10 * res) + (num % 10);

        num /= 10;
    }

    return res;
}

char* stringify(int num) {

    char* str = malloc(25);      // 70

    int index = calculate_exponent(num);

    int last = index + 1;

    while(num > 0) {

        str[index--] = (num % 10) + '0';

        num /= 10;
    }
    
    str[last] = '\0';

    return str;

}

void print_current_digit(char* buffer, int target) {

    int index = 0;

    char str[70];

    int str_index = 0;

    while(buffer[index] - '0' != target) {
        index++;
    }

    while(buffer[index] != '\n') {

        if(buffer[index] >= 'A' && buffer[index] <= 'z') {

            str[str_index] = buffer[index];
            str_index++;
        }

        index++;
    
    }

    str[str_index] = '\0';

    printf("%s ", str);
}

void print_current_element(char* buffer, char* target) {
   
    int index = 0;

    char str[70];

    int str_index = 0;

    char* buffer_pointer = strstr(buffer, target);

    while(*buffer_pointer != '\n') {

        if(*buffer_pointer >= 'A' && *buffer_pointer <= 'z') {

            str[str_index] = *buffer_pointer;
            str_index++;
        }

       buffer_pointer++;
    
    }

    str[str_index] = '\0';

    printf("%s ", str); 
}

void print_num(int num) {                  //   7

    printf("\n%d --->  ", num);

    int exponent = calculate_exponent(num);

    num = reverse(num);
    int fd = open("numbers.dict", O_RDONLY);

    int buffer_size = 1000;
    char* buffer = malloc(buffer_size);

    int sz = read(fd, buffer, 690);
    buffer[690] = '\0';

    while(num > 0) {

        int digit = (num % 10);
        int rhs = my_pow(10, exponent--);
        
        int expression = digit * rhs;

        char* current = stringify(rhs);

        char* current_dig = stringify(expression);

        if(digit == 0) {
            
            num /= 10;
            continue;

        }


        if(expression < 10) {
            
            print_current_digit(buffer, digit);
        }


        if(reverse(num) > 10 && reverse(num) <= 20) {

            char* tmp = stringify(reverse(num));

            print_current_element(buffer, tmp);

            num /= 10;

            free(tmp);
        }


        else if(expression < 100) {

            print_current_element(buffer, current_dig);

        }

        else if((expression >= 100) && ((expression) % 10 == 0)) {

            print_current_digit(buffer, digit);

            print_current_element(buffer, current);
            
        }

        free(current);

        num /= 10;

    }

    printf("\n");
    
    free(buffer);

    int cl = close(fd);

}



int main() {

    int x = 0;

    while(1) {

        printf("\n Enter the number : ");
        scanf("%d", &x);

        print_num(x);
    }

    

    return 0;
}