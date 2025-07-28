/*🧪 실습 과제: 포인터 심화 실습
🎯 실습 목표
함수 포인터와 다중 포인터를 직접 사용

포인터 배열과 배열 포인터 차이 실습

void 포인터 형변환

📌 실습 문제
정수형 배열 int arr[3] = {10, 20, 30} 를 만들고:

배열 포인터로 arr의 모든 요소를 출력하라

포인터 배열을 만들어 각각 arr 요소를 가리키게 하라

int add(int a, int b) 함수와 함수 포인터를 이용해 두 수를 더하라

int x = 7; 일 때, int **pp 형태의 다중 포인터로 x를 출력하라

void 포인터를 이용해 float f = 3.14 값을 출력하라

const 포인터 3종류 각각 선언해보고, 어느 부분이 수정 가능한지 확인해라*/

#include <stdio.h>

void printALL(int **pp, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", **(pp+i));
    }
}

int add(int a, int b){
    return a+b;
}

int main(){
    int arr[3] = {10, 20, 30};          // 배열         {int, int, int}
    int *p[3] = {arr, arr+1, arr+2};    // 포인트 배열  {int *, int *, int *} vs 포인트 int *
    printf("포인트 배열 출력: \n");
    printALL(p, 3);                     // **주의** 배열의 크기를 모른다면, 포인터로 넘긴다. 함수도 포인터로 받는다.
                                        //          포인터 배열을 넘긴다면 함수에서는 이중포인터로 받는다.

    int (*addPtr)(int, int) = add;
    printf("두 수 더하기: %d \n", addPtr(3, 4));
    
    int x = 10;
    int *q = &x;
    int **qq =&q;
    printf("이중포인터 지시값 출력: %d\n", **qq);
    
    void *vp;   // void 타입은 cast(형변환) 해야함.
    float f = 3.14;
    vp = &f;
    printf("void 포인터 이용: %.2f\n", *(float *)vp);

    const int *a;
    int *const b;
    const int *const c;
    
    const int d;
    int const e;
    
    return 0;
}









// int a[3]  => {int, int, int}             배열
// int *a[3] => {int *, int *, int *}       포인트 배열