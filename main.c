#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>



// write malloc free open close read


int my_pow(int num, int exponent) {

    int res = 1;

    while(exponent > 0) {

        res = num * res,  exponent--;
    }

    return res;
}



void print_num(unsigned int num) {

    unsigned int t_num = num;

    int count = 0;

    while(t_num > 0) {

        t_num /= 10, count++;

    }

    char* str = (char*) malloc(count + 1); // + '\0'

    str[count] = '\0';

    int index = count;

    while(index > 0) {

        str[index - 1] = (num % 10) + '0';

        index--, num /= 10;
    }

    char* print = (char*) calloc(500, sizeof(char));

    int fd = open("numbers.dict", O_RDONLY);

    // int sz = read(fd, print, 200);

    // printf("%s\n", print);

    int bit = 1, exp = 1, i = 1;


    while(exp < count) {

        if(print[bit] >= '0' && print[bit] <= '9') {
            printf("%c\n", print[bit]);  
            exp++;
        }

        int sz = read(fd, print, 10);

        bit++;

    }

    printf("%d\n", exp);    

    int cl = close(fd);

    free(str);
    free(print);

}



int main() {

    print_num(1488);

    return 0;
}

