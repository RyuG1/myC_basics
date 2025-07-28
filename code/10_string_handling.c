#include <stdio.h>

int main() {
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    
    for (int i = 0; i < 10; i++) {
        if(name[i] == '\0') {
            printf("end of string reached at index %d\n", i);
            break;
        }else {
            printf("look, name[%d] = %c!\n", i, name[i]);
        }
    }
    
    return 0;
}

// string 쓰는 이유 까먹음
// 문자를 배열처럼 다룰수 있음.
// 즉, "R", "y", "u", "\0" 이렇게 저장됨.

// %s, name     값이 아닌 배열
//    vs
// %c, name[i]



// 터미널로 바로 가는 단축키
// ctrl + ` 터미널로 이동
// ctrl + J 패널 열기/닫기
