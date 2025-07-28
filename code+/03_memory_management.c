/*
## 3. 메모리 관리
- malloc, calloc, realloc, free
- 메모리 누수, dangling pointer
- padding 및 정렬
- 구조체 정렬 제어

malloc  : Memory Allocation     / 메모리 할당
calloc  : Contiguous Allocation / 연속 할당   
realloc : Real location         / 실제 위치 
free
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p = (int *)malloc(sizeof(int)*3);
//  1. malloc -> 성공 시 주소 반환(void*), 실패 시 NULL 반환
//               원하는 크기만큼 메모리를 heap 영역에 할당
//               명시 안하면 자동으로 int*로 캐스팅됨. 그러나 가독성 때문에 적어주는 습관 들이기 추천.
    
    int *p = (int *)calloc(3, sizeof(int));
//  2. calloc -> malloc과 같지만 0으로 초기화됨
//               (malloc은 초기화x)

    p = (int *)realloc(p, sizeof(int)*5);
//  3. realloc -> 기존 메모리 크기를 변경 (확장 또는 축소)
//                주소가 바뀔 수 있음, 항상 다시 저장해야 안전
//                주소 "재할당"할 수 있기 때문에 p= {...} 이렇게 재귀.

    free(p);
    p = NULL;
//  4. free ->  malloc, calloc, realloc로 할당한 메모리를 해제
//              반드시 해줘야 메모리 누수 방지
//              메모리를 반납해도, p는 주소를 기억하고 있음.
//              메모리 접근 권한x = Dangling Pointer (p를 초기화 해야 이상한 동작 방지)


//  5. 메모리 누수 (Memory Leak)
    int *p = malloc(10 * sizeof(int));
    p = malloc(20 * sizeof(int));
    //  주소를 재할당하기 때문에 먼저 만든 10개짜리는 잃어버림 (사라짐x)

//  6. 죽은 포인터 (Dangling Pointer)
    int *p = malloc(10);
    free(p);
    *p = 10; 
    // free에 의해 반납된 메모리를 의미. 접근 권한 x

// 7. 구조체 패딩 & 정렬 (Padding & Alignment)
    struct A {
        char a; // 1 byte
        int b;  // 4 byte
    };
    // (구조체의 사이즈) a + b = 5  ???  ->  Noop, a + b = 8.
    // 구조체는 멤버의 타입에 맞춰 정렬(alignment)을 해줘야함. (이유: 메모리 접근 속도 향상)
    // int 는 4 바이트 "정렬"이 필요함.
    // char 뒤에 3 바이트 "패딩"이 삽입됨.



// 8. 구조체 정렬 제어 방법 (GCC 기준)
    #pragma pack(1) // 구조체 정렬(allocation)을 1 바이트로 강제.
    struct A {
        char a;
        int b;
    };
    #pragma pack()  // 다시 기본 정렬로 복원
    // 정렬을 1 byte로 하기 때문에 패딩이 사라짐
    // 그래서 5 바이트 구조체를 만들 수 있음
    // 단, 성능은 떨어지고 CPU마다 위험할 수 있음

    return 0;
}