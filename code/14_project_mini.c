#include <stdio.h>

// 성적 계산기
int main() {
    int score;
    printf("wirte your score: ");
    scanf("%d", &score);

    if(score >= 90){
        printf("score is A\n");
    } else if(score >=80){
        printf("score is B\n");
    } else if(score >=70){
        printf("score is C\n");
    } else if(score >=60){
        printf("score is D\n");
    } else {
        printf("score is F\n");
    }    
    return 0;
}