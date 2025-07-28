// printf 터미널에 쓰기(출력)
// scantf 터미널 내용 읽기(입력)


/*
## 5. 파일 입출력 (I/O)
- 텍스트/바이너리 파일
- 파일 포인터와 fseek
- 버퍼링 이해


fopen()	    파일 열기
fclose()	파일 닫기

fscanf()	파일에서 입력 읽기
fprintf()	파일에   출력 쓰기

fgets()	    문자열 "한 줄" 읽기
fputs() 	문자열 "한 줄" 쓰기

fread()     바이너리 파일 읽기
fwrite()    바이너리 파일 쓰기
*/


#include <stdio.h>

int main(){
    // 1. 읽기 모드 "r", fscanf(...)
    FILE *fp = fopen("data.txt", "r"); 
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;   // 운영체제(OS)에게 "1번 오류가 발생했다"고 알림
    }
    char str[100];
    int num;

    fscanf(fp, "%s %d", str, &num);  // 입력 예시: hello 42
    fclose(fp);


    // 2. 쓰기 모드 "w", fprintf(...)
    FILE *fp = fopen("output.txt", "w");
    fprintf(fp, "Hello, world!\n");
    fclose(fp);

    FILE *fp = fopen("input.txt", "r");

    return 0;
}