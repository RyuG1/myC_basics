/* 01_struct_advanced 커리큘럼

1. 중첩 구조체 (Nested Structures)
2. 구조체 배열 (Structure Arrays)
3. 구조체 포인터 (Structure Pointers)
4. 구조체와 함수 (Structures and Functions)
5. 구조체와 typedef (Structures and Typedef)
*/

#include <stdio.h>
#include <string.h>

// 1. 중첩 구조체 (Nested Structures)
typedef struct {    // typedef : Date라는 새로운 구조체 타입을 정의.
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[50];
    int age;
    Date birth; // 중첩 구조체
} Person;

void printPerson(Person p);     // 함수 선언, Person 타입의 매개변수를 받는 함수
void modifyPerson(Person *p);    // 함수 선언, 구조체 포인터를 매개변수로 받는 함수 선언


// 2. 구조체 배열 (Structure Arrays)
int main(){
    Person people[3];                           // 만약 구조체 정의할때 typedef 를 사용 안했다면, struct Person people[3];로 선언해야함.
    strcpy(people[0].name, "Alice");            // strcpy()             vs      = 연산자
    strcpy(people[1].name, "Bob");              // 문자열 내용 복사              포인터 주소 복사
                                                // 각 문자를 하나씩 복사         포인터 변수에 다른 문자열 주소를 복사
                                                // 대상 버퍼 공간이 필요         문자열 상수 주소만 가리킴
                                                // =연산자를 사용하면, 같은 주소를 가리킴 -> 수정 시 에러 발생 가능. 완전히 같은게 아니라면 strcpy() 사용.
    people[0].age = 30;
    people[0].birth.year = 2000;
    people[0].birth.month = 4;
    people[1].age = 25;
    people[1].birth.day = 18;
    
    
    people[1].birth = (Date){1995, 12, 25};                 // 복합 리터럴
    people[2]       = (Person){"Curry", 20, {2023, 10, 1}}; // 이미 (Person) 타입이 정의되어 있으므로, (Date) 복합 리터널은 생략 가능.



// 3. 구조체 포인터 (Structure Pointers)
    Person p = {"Doraemon", 10, {2023, 10, 1}};
    Person *ptr = &p; // 구조체 포인터, 'p'oin't'e'r'

    printf("Name: %s\n", ptr->name); // 구조체를 포인터로 접근할 때는 "->" 연산자를 사용.
                                                // .    구조체 멤버 접근 연산자                 (구조체 변수)
                                                // ->   포인터가 가리키는 구조체 멤버 접근       (구조체 포인터)  
                                                //
                                                // p.name = "Delta"
                                                // ptr->name = "Ellice"
                                                // (*ptr).name = "Fiona"
    printPerson(people[0]);
    printPerson(people[1]);
    printPerson(people[2]);
    printf("Next year............\n");
    modifyPerson(people);
    modifyPerson(people+1);
    modifyPerson(people+2);
    printPerson(people[0]);
    printPerson(people[1]);
    printPerson(people[2]);

    return 0;

}

// 4. 구조체와 함수 (Structures and Functions)
void printPerson(Person p){     // **주의** 함수 내부에서 정의된 p, 외부의 Person p와는 다른, 지역 변수 
        printf("name: %s, age: %d\n", p.name, p.age);
};

void modifyPerson(Person *p){   // **중요** 포인터 변수를 입력받기 때문에 외부 변수에 영향을 줄 수 있음. 
    p -> age += 1;
}
    

// 5. 구조체와 typedef (Structures and Typedef)
typedef struct{
    int x,y;
} Point;

Point p1 = {3, 4};
