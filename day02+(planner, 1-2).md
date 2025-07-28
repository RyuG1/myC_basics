# C 언어 심화 커리큘럼

## ✅1. Struct 심화
- 중첩 구조체
- 구조체 배열
- 구조체 포인터
- 구조체를 함수 인자로 넘기기
- typedef로 구조체 정의하기

## ✅2. 포인터 심화
- 포인터 배열 vs 배열 포인터
- 함수 포인터
- 다중 포인터
- void 포인터
- const와 포인터의 조합

## ✅3. 메모리 관리
- malloc, calloc, realloc, free
- 메모리 누수, dangling pointer
- padding 및 정렬
- 구조체 정렬 제어

## ✅4. 함수 심화
- 재귀 함수 최적화
- 콜백 함수
- inline 함수 vs 매크로

## ✅5. 파일 입출력 (I/O)
- 텍스트/바이너리 파일
- 파일 포인터와 fseek
- 버퍼링 이해




## 6. 전처리기 및 매크로
- 함수형 매크로
- 조건부 컴파일
- include guard / pragma once
- 컴파일러 내장 매크로

## ✅7. 비트 연산 및 비트 필드
- 비트 연산자 기초
- 마스킹 기법
- 비트 필드 구조체

## 8. 저수준 시스템 접근
- 유니언을 통한 형 변환
- 엔디안 이해
- 메모리 맵 IO 시뮬레이션





## 9. 라이브러리 함수 분석
- printf, scanf 분석
- 문자열 함수 구현
- stdlib 함수 재현

## 10. 링크/빌드 시스템 이해
- 컴파일 vs 링크
- extern, static 키워드
- 다중 파일 구조 실습

## 11. C로 객체지향 흉내내기
- struct + function pointer
- virtual table 구현
- 캡슐화 구조 설계



## 📌 추가로 꼭 다루면 좋은 심화 주제

4. 🤣파일 입출력 심화🤣
- 이진 파일 (fread, fwrite)
- fseek, ftell, rewind 같은 위치 조작 함수
- 구조체를 파일로 저장하고 다시 불러오기

5. 😄C언어와 C++ 간 차이 이해😄
- struct vs class 차이점
- new/delete vs malloc/free
- 접근 지정자 (public, private, protected)
- 생성자/소멸자 기본 구조


01_struct_advanced.c              // 구조체 심화
02_pointer_advanced.c            // 포인터 심화
03_memory_management.c           // 동적 메모리 관리
04_function_advanced.c           // 함수 심화
05_file_io.c                     // 파일 입출력
06_preprocessor_macros.c         // 전처리기와 매크로
07_bit_operations.c              // 비트 연산과 비트 필드
08_low_level_access.c            // 저수준 시스템 접근
09_libfunc_analysis.c            // 표준 함수 분석/구현
10_linking_and_build.c           // 링크와 빌드 구조
11_object_like_struct.c          // 객체지향 흉내내기