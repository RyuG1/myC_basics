/*🔍 2. 포인터 심화 — 개념 정리 & 실습 문제
✅ 학습 목표
포인터의 다양한 형태와 차이 이해

함수 포인터, 다중 포인터, 배열과 포인터 차이

const와 void 포인터의 활용*/

// 포인터 형변환 cast :  (int *)ptr 
// 포인터                int *ptr
// 배열 포인터           int (*ptr)[3]
// 포인터 배열           int *ptr[3]
// 함수                  int        add(int a, int b)  - 매개변수의 이름 필요
// 함수 포인터           int (*funcPtr)(int, int)       - 매개변수의 타입만 알면 됨.
//                      함수의 주소를 함수 포인터로 선언. 새로운 함수를 정의하는 것이 아닌,
//                      이미 정의된 함수의 주소를 저장하고, 그 함수를 간접적으로 호출하기 위한 도구
//                      함수의 이름표 혹은 리모컨 역할. 함수 이름 재정의, 별명.
//  활용1: 함수에서 다른 함수를 변수로 입력할때 유용. void operate(int x, int y, int (*func)(int, int)) { };
//  활용2: 전역으로 함수 포인터 선언. int (*global_fp)(int, int);
//  활용3: 배열에 함수 포인터 넣기 - 간단한 메뉴 시스템 같은 데 쓰임. int (*ops[2])(int, int) = {add, sub};

// 메모리에는 "주소 -> 값" 형태로 저장됨.
// 포인터도 구조 동일. 단지, 값에 "주소"가 저장되어 있음.


#include <stdio.h>

int add(int a, int b){
    return a + b;
};

int main() {
    // 1️⃣ 배열 vs 포인터
    int arr[3] = {1, 2, 3};
    int *p = arr;

    // arr[1] == *(arr + 1) == p[1] == *(p + 1);


    // 2️⃣ 포인터 배열 vs 배열 포인터
    // 포인터 배열: 각 요소가 int형 포인터를 가리키는 배열.    {포인터, 포인터, 포인터}
    int *ptrArr[3]; 

    // 배열 포인터 : 배열 전체를 가리키는 포인터.               포인터
    int (*pArr)[3] = &arr;  // &arr  vs  arr(=&arr[0])
                            // &arr: 배열 전체를 가리키는 포인터 
                            // arr : 배열의 첫번째 요소를 가리키는 포인터 

    
    // 3️⃣ 함수 포인터
    int (*funcPtr)(int, int) = add; // 함수 포인터 선언 및 초기화
    //or
    int (*funcPtr)(int, int);   // 함수 포인터 선언
    funcPtr = add;              // 함수 포인터 초기화

    int result = funcPtr(3, 4);
    printf("result: &d\n", result);


    // 4️⃣ 다중 포인터 (포인터의 포인터)
    //  address   address   value
    //             &x        x(=10)
    //    &p        p        *p
    //    pp       *pp       **pp
    
    int x = 10;         
    int *p = &x;
    int **pp = &p; // 이걸 활용하면 포인터 p에 간섭할 수 있음. 잘은 모르겠다.



    // 5️⃣ void 포인터 (형변환(cast) 해서 써야 함)
    void *vp;
    int n = 5;
    vp = &n; // void 포인터에 int형 변수 주소 저장
    printf("Value: %d\n", *(int *)vp); // void 포인터를 int 포인터로 형변환 후 사용


    // 6️⃣ const 포인터 = 읽기전용. 위치: const 타입 const 변수이름
    //                   경우에 따라 초기값이 필요함. const int x = 5;, int * const p2 = &x;
    //                   const int x = 5; == int const x = 5; 동일한 결과.
    
    const int *p1; // ✅ 포인터 p1은 다른 주소를 가리킬 수 있다. p1  = &... 가능
                   // ❌ 단, *p1 = 값; 은 금지 (읽기 전용 값)   *p1 = ...  불가능 (int값 못바꾼다)
    int *const p2;  // ✅ p2는 주소 고정, *p2 값은 변경 가능    p2 = &... 불가능 (포인트 못바꾼다)
                    //                                         *p2 = ...  가능
    const int *const p3; // 둘 다 변경 불가능, const를 어디에 적어야하는지 위치 주의. 









    return 0;
}



