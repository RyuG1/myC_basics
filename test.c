#include <stdio.h>

typedef struct {
    int age;
} Person;

int main() {
    Person people[2];
    people[0].age = 20;
    people[1].age = 23;
    people[2].age = 19;

    printf("people     : %p\n", (void*)people);         // 첫번째 요소의 주소   Person*
    printf("people[0] : %p\n", (void*)&people[0]);     // 첫번째 요소의 주소    Person*                                

    printf("&people    : %p\n", (void*)&people);    // 배열 전체의 주소,        Person (*)[5]
                                                    // *p 로 인수를 받으면 *(&people) -> people
                                                    //                    *(people)  -> people[0]

        /*
        people             (배열 이름)
        ↓
        &people            (배열 전체의 주소)         → 타입: Person (*)[3]
        ↓
        &people[0]         (첫 번째 구조체의 주소)     → 타입: Person*
        ↓
        people[0].age      (첫 번째 구조체의 값)       → 타입: int
        */

    int p = 30;
    int *ptr = &p;

    int num[3] = {10, 20, 30};
    //num 은 배열의 이름, 배열의 주소, num[0]의 주소와 같음.

    num
    &num[0] // 배열의 주소, num[0]의 주소와 같음.


    return 0;
}

