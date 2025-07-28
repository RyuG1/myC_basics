/*
4-1. 함수 기본 복습 & 함수 선언 vs 정의 vs 호출
    - 함수 프로토타입 이해
    - 함수 원형 선언과 정의 분리
    - 매개변수 전달 방식 (값 전달 vs 주소 전달)

4-2. 재귀 함수 (Recursive Function)
    - 재귀 호출의 원리
    - 종료 조건과 스택 메모리 이해
    - 간단한 팩토리얼, 피보나치 구현

4-3. 함수 포인터 (Function Pointer)
    - 함수 포인터 선언 및 사용법
    - 콜백 함수 이해
    - 배열과 함수 포인터 활용

4-4. 가변 인자 함수 (Variadic Function)
    - stdarg.h 활용법
    - printf, scanf의 내부 원리

4-5. 인라인 함수와 매크로 함수 비교
    - 성능 차이 이해
    - 매크로 함수 위험성 및 사용법
*/

#include <stdio.h>
#include <stdarg.h> // 가변 인자

//  1. 선언 / 정의 / 호출
int add(int a, int b);  // 함수 선언, 세미콜론(;) 필요

int add(int a, int b){  // 함수 정의, 세미콜론(;) 생략
    return a + b;
}


//  2. 재귀 함수 (Recursive Function)
int factorial (int n){
    if(n <=1 ){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
    // 함수가 자기 자신을 호출하는 함수
    // 꼭 종료 조건(base case)을 가져야 무한 루프 방지 가능
}


//  3. 함수 포인터 (Function Pointer)
int (*func_ptr)(int, int);  // 기존의 함수를 사용. 그래서 Type만 정의하면 됨.


//  4. 가변 인자 함수 (Variadic Function) - ex: printf(), scanf() 
/*      <stdarg.h>
        va_list	                        가변 인자 리스트 타입 선언
        va_start(va, last_fixed_arg)	가변 인자 리스트 초기화
        va_arg(va, type)	            다음 인자(argument)를 타입에 맞게 꺼냄
        va_end(va)	                    가변 인자 리스트 종료
*/
void pritn_numbers(int count, ...) {
    va_list args;                       // list: 가변인자 리스트의 현재 위치(포인터) 
    va_start(args, count);              // start: 시작 위치 지정

    for (int i = 0; i < count; i++){
        int num = va_arg(args, int);    // arg: 호출마다 다음 인자 위치로 이동
        printf("%d ", num);
    }

    va_end(args);
    printf("\n");
}



//  5. 매크로 함수와 인라인 함수 비교
//  #define                 VS    inline 함수
//  전처리기 단계(문자치환)         컴파일러 단계(함수처럼 처리)
#define SQUARE (x) ((X) * (X))  // '#': 전처리기 단계에서 수행, "문자열 치환"을 수행
                                // C 컴파일러가 본격적인 컴파일에 들어가기 전에 먼저 소스를 한 번 가공.

inline int square(int x) {      // inline %function% : 컴파일러가 함수 호출 없이 "코드 자체를 삽입"함.
    return x*x;                 
}
//      함수 호출 vs inline
//          함수 호출: 실행 코드 정지 -> 스택에 복귀 주소, 인자 값, 레지스터 등 저장 -> 함수로 점프 -> 복귀 및 실행
//                      단순히 return만 해도 복잡한 과정을 거치게 됨(병목 유발 가능)
//          inline  : 함수 코드를 호출 위치에 그대로 복사. "치환"이라 생각하면 될 듯. 
//                      단순 로직에 유용. 복잡하면 프로그램 전체 크기가 커질 수 있음.
//                      재귀 함수, 가변 인자 함수에는 사용 금지.
//                      결국 컴파일러가 최종적으로 "inline할지 말지 판단"힘.
//
//gpt   즉, 지금은 거의 대부분 inline 함수가 #define 매크로 함수를 대체하고 있어.
//gpt   단순 상수 정의는 #define, 함수처럼 쓰려면 inline 쓰는 게 훨씬 안전하고 명확해!


int main(){
    int result = add(3, 4); // 함수 호출
//      1) 값 전달 (pass by value) : 값 복사, 원본 변경x
//      2) 주소 전달 (pass by reference via pointer) : 주소 전달, 원본 변경


    func_ptr = add; // 함수 포인터
    int res = func_ptr(3, 4); 
    

    print_numbers(3, 10, 20, 30);      // 출력: 10 20 30
    print_numbers(5, 1, 2, 3, 4, 5);   // 출력: 1 2 3 4 5

    return 0;

}
