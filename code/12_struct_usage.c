#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person p1 = {"Alice", 25};
    printf("name: %s, age: %d\n", p1.name, p1.age);

    
    return 0;
}


// struct 는 세미콜론 ; 붙여야함.
