#include <stdio.h>

int main() {
    int num = 10;
    int *p = &num;

    printf("value of num: %d\n", num);
    printf("value of pointer p: %d\n", *p);
    

    return 0;
}