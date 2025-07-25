#include <stdio.h>

int main() {
    // Writing to a file
    FILE *fp = fopen("output.txt", "w");

    if(fp != NULL){
        fprintf(fp, "파일에 쓰는 중입니다\n");
        fclose(fp);
    }else{
                 printf("파일 열기 실패\n");
    }

    // Reading from a file
    fp = fopen("output.txt", "r");
    if(fp != NULL){
        char line[100];
        fgets(line, sizeof(line), fp);

        printf("read from file: %s", line);
        fclose(fp);
    } else{
        printf("파일 열기 실패\n");
    }

    return 0;
}
// const char *format    ?????
// const : 변경 불가능
// const int a = 10;
// const char msg[] = "Hello, world!";
// 값 변경 불가능.

// const char         *str = "Hi";  
// 문자열 내용은 수정할 수 없음
// str[0] = 'h';  // ❌

//       char   *const ptr = buffer;
// 포인터 자체는 못 바꾸지만, 내용은 바꿀 수 있음

// const char   *const both = "Hi";
// 포인터도 못 바꾸고, 가리키는 내용도 못 바꿈




// FILE 은 struct 형태이다.
// FILE 은 주로 포인터 형태로만 사용한다.

// FILE *fp;
// FILE 구조체는 {파일의 상태, 위치, 버퍼} 등 다양한 정보를 저장

// fopen, fclose, fprintf, fgets, fscanf 등 파일 입출력 함수 사용   
// 1. 파일열기
// "r", "w", "a", "r+", "w+", "a+" 등 모드 설정

// 2. 파일 출력
// fprintf(FILE *fp, const char *format, ...);      쓰기 : 파일에 출력
// fput(const char *s, FILE *fp);                   쓰기 : 문자열을 파일에 출력
// fput(int c,         FILE *fp);                   쓰기 : 한 문자를 파일에 출력


// 3. 파일 입력
// fscanf(FILE *fp, const char *format, ...);       읽기 : 파일에서 읽기
// fgets(char *str, int n, FILE *fp);               읽기:  파일에서 한 줄씩 읽기, \n 포함, \0 까지 저장
// fgets(                  FILE *fp);               읽기:  파일에서 한 문자 읽기

// 4. 그 외
// fopen(const char *filename, const char *mode);   파일 열기
// fclose(FILE *fp);                                파일 닫기
// feof(FILE *fp);                                  파일 끝(end of file)인지 확인
// fflush(FILE *fp);                                파일 출력 버퍼 비우기 (강제로 쓰기 수행) ???? 이건 모르겠네