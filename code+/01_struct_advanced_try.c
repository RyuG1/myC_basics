/* 🧪 실습 과제: 구조체와 포인터 활용한 사람 목록 관리
🎯 목표
구조체 정의

구조체 배열

구조체 포인터

함수로 구조체 넘기기

📌 실습 문제
아래 요구사항에 맞춰 C 프로그램을 작성하시오.

📝 요구사항
Person 구조체를 정의하라.

이름 (char name[20])

나이 (int age)

키 (float height)

3명의 사람 정보를 구조체 배열에 저장하라.

모든 사람을 출력하는 함수 printAll(Person *list, int size)를 작성하라.

특정 사람의 나이를 증가시키는 함수 birthday(Person *p)를 작성하라.

main() 함수에서 위 함수들을 활용하라.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float height;
} Person;

void printAll(Person *list, int size){
    for(int i = 0; i < size; i++){
        printf("Name: %s, Age: %d, Height: %.2f\n", list[i].name, list[i].age, list[i].height);
    }                       //축약 표현: list[i].name   ,  실제: (list + i ) -> name
};

void birthday(Person *p){
    (p+0) -> age += 1;
    (p+1) -> age +=1;
    (p+2) -> age += 1;
};

int main(){
    Person people[3] = {
        {"Alice", 30, 165.5},
        {"Bob", 25, 175.0},
        {"Charlie", 20, 180.2}
    };

    printf("=== 사람 목록 ===\n");
    printAll(people, 3);

    birthday(people);

    printf("=== 업데이트 후 ===\n");
    printAll(people, 3);

    return 0;
}