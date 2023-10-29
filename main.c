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

void print_current_element(char* buffer, int num) {
   
    char* target = stringify(num);
    
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

    free(target);

    write(1, str, str_index);
    write(1, " ", 1); 
}

void print_num(int num) {                  //   7


    printf("\n%d --->  ", num);


    if(num == 0) {

        write(1, "zero", 4);
        return;

    }

    
    int exponent = calculate_exponent(num);

    num = reverse(num);
    int fd = open("numbers.dict", O_RDONLY);

    int buffer_size = 700;
    char* buffer = malloc(buffer_size);

    int sz = read(fd, buffer, 690);
    buffer[690] = '\0';

    while(num > 0) {

        int digit = (num % 10);
        int power_of_10 = my_pow(10, exponent--);
        
        int expression = digit * power_of_10;


        if(digit == 0) {
            
            num /= 10;
            continue;

        }

        if(expression < 20) {

            num /= 10;

            expression += num % 10;

            print_current_element(buffer, expression);

        }

        else if(expression < 100) {

            print_current_element(buffer, expression);


        }

        else if(expression < 10000) {

            print_current_element(buffer, digit);

            print_current_element(buffer, power_of_10);    
        }

        else if((expression >= 10000 && expression <= 100000)) {

            num /= 10;

            print_current_element(buffer, (expression / 1000));

            print_current_element(buffer, (num % 10));

            print_current_element(buffer, power_of_10 / 10);

            exponent--;
        }

        num /= 10;

    }


    write(1, "\n", 1);
    
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