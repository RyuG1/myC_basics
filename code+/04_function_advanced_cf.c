// 4.3 함수 포인터 활용 예제 2가지.


// (1) 콜백 함수 예제
#include <stdio.h>

// 콜백 함수 타입: int(int, int)
typedef int (*Operation)(int, int);

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// 콜백 함수를 매개변수로 받는 함수
int compute(int x, int y, Operation op) {
    return op(x, y);  // 넘겨받은 함수 호출
}

int main() {
    int res1 = compute(3, 4, add);       // 7
    int res2 = compute(3, 4, multiply);  // 12

    printf("Add: %d\n", res1);
    printf("Multiply: %d\n", res2);

    return 0;
}


// (2) 함수 포인터 배열 예제
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int main() {
    // 함수 포인터 배열 선언 및 초기화
    int (*func_arr[])(int, int) = {add, sub, mul};

    int x = 10, y = 5;

    for (int i = 0; i < 3; i++) {
        printf("Result %d: %d\n", i, func_arr[i](x, y));
    }

    return 0;
}
