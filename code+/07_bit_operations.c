#include <stdio.h>

// 07.비트 연산 및 비트 필드.

/* 비트 연산자
연산자	    의미	            예시        기호이름
&	        AND (비트 단위 곱)	a & b        앰퍼샌드(&)
|	        OR (비트 단위 합)   a |	b        파이프(|)
^	        XOR (배타적 OR)	    a ^ b        캐럿(caret)
~	        NOT (비트 반전)	    ~a           틸드(tilde)
<<	        왼쪽 시프트	        a << 1
>>	        오른쪽 시프트	    a >> 2

-- VHDL에서는 연산자 기호 안씀. {and, or, xor, not} 등으로 쓰면 됨*/


int main(){
    // 1) 비트 연산자 종류
    unsigned char a = 0b1100; // 12
    unsigned char b = 0b1010; // 10

    printf("AND: %02X\n", a & b);  // 0x08
    printf("OR : %02X\n", a | b);  // 0x1E
    printf("XOR: %02X\n", a ^ b);  // 0x16
    printf("NOT: %02X\n", ~a);     // 0xF3 (2의 보수 기반), [cf] a: 1byte, ~a: 4byte (int형)

    // char : 1byte        : 0xFF 
    // int  : 4byte        : 0xFFFFFFFF
    // 32x = 32bit =4 byte : 0xFFFFFFFF
    // 64x = 64bit =8 byte : 0xFFFFFFFF FFFFFFFF

    // 타입	크기        (byte)  표현 범위
    // signed int       4	    약 -2,147,483,648 ~ 2,147,483,647
    // unsigned int	    4	    0 ~ 4,294,967,295
    // signed char	    1	    -128 ~ 127
    // unsigned char	1	    0 ~ 255



    // 2) 마스크 연산           특정 비트를 {1로, 0으로, 토글}
    unsigned char flags = 0b10101100; //0b1010_1100

    // 특정 비트가 1인지 확인 (4번째 비트)
    if (flags & (1 << 3)) {
        printf("비트 3은 1입니다.\n");
    }

    // 특정 비트를 1로 설정 (비트 2)
    flags |= (1 << 2);

    // 특정 비트를 0으로 클리어 (비트 7)
    flags &= ~(1 << 7);     // ~(1 << 7) : result = 11111111 01111111

    // 특정 비트 토글 (비트 1)    
    flags ^= (1 << 1);      //xor 은 하나의 입력을 하나의 입력을 1로 고정할 때, 1->0, 0->1 로 토글(toggle)
                            //                    하나의 입력을 0로 고정할 때, 1->1, 0->0 로 영향x

    

    // 3. 비트 필드 구조체 (Bit Field)  // **주의** 비트 필드들은 일반 변수처럼 주소를 직접 참조할 수 없음
    struct Status {                 // unsigned int는 4byte 이지만 구조체는 8bit 메모리만 할당.
        unsigned int power : 1;     // unsigned int 자료형을 기반으로 사용하지만, 1bit만 쓰겠다.
        unsigned int error : 1;
        unsigned int ready : 1;
        unsigned int reserved : 5;  //비트 필드 멤버, 주소 접근 불가능.
        unsigned int c;             //일반 멤버, 일반 구조체처럼 주소 접근 가능.
    };
    struct Status s = {1, 0, 1, 0}; // power=1, error=0, ready=1
    printf("전체 상태값: 0x%X\n", *((unsigned char*)&s));




    
    return 0;
}