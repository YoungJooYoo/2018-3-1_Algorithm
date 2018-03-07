/*
 +학번 및 이름 : 2016101453 컴퓨터학부 유영주
 * 목적 및 개요:  3-1학기 알리즘 과제 <피보나치 수열>
 * 과제수행날짜: 2018.03.07(수)
 * 프로그램 특징: 재귀호출법과 반복정 방법으로 구현한 피보나치 수열 구현 및 실행시간 측정
 *             재귀함수를 함수화 시키고, 반복문을 이용한 계산을 함수화 시켜서 구현.
 * 사용언어: C언어
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.3
 *   IDE: Xcode 9.2
 *   Compiler gcc 4.2.1
 */


//이슈 클럭함수를 어디다 선언할까 메인문에?

#include <stdio.h>
#include <time.h>

int Fibonacci_Recursive(int num);
int Fibonacci_Loop(int num);


int main(int argc, const char * argv[]) {
   
    int select_num;  // 어떤 계산방법을 선택할지 정하는 변수
    int caculation_num; // 피보나치수열의 몇번째 항까지 계산할지 입력받는 정수
    clock_t function_start_time, function_finish_time; //시간 측정을 위한 변수 2개 시작점과 끝점
    double duration ; // 끝시간-시작시간 = 연산시간이므로 이 변수를 선언한다.
    
    // 재귀함수를 무슨 방법으로 구할지 선택한다.
    printf("피보나치 수열의 계산프로그램입니다.\n");
    printf("1번 방법은 재귀함수, 2번은 방법은 반복문을 사용합니다. 원하시는 번호를 입력해주세요.\n");
    scanf("%d",&select_num);
    
    
    
    // 선택에 따라 각 방법으러 구현한 피보나치 수열 계산 함수를 호출한다.
    // 1이면 재귀순환, 2선택시 반복문이다. 다만, 다른 숫자는 잘못된 선택으로 간주한다.
    if(select_num==1){
        printf("재귀순환을 선택하셨습니다.\n");
        printf("계산하고 싶은 항의 숫자를 입력하세요\n");
        scanf("%d", &caculation_num);
        function_start_time = clock(); // 시작시간 계산
        printf("재귀순환으로 구한 피보나치수열의 합은 = %d\n",Fibonacci_Recursive(caculation_num));
        function_finish_time = clock(); // 종료시간계산
        duration = (double)(function_finish_time-function_start_time); // 단위는 per sec으로 시간을구한다
        printf("재귀순환으로 소요된 시간은= %f초입니다.\n",duration);
    }
    
    else if(select_num==2){
        printf("반복문을 선택하셨습니다.\n");
        printf("계산하고 싶은 항의 숫자를 입력하세요\n");
        scanf("%d", &caculation_num);
        function_start_time = clock(); // 시작시간 계산
        printf("반복문으로 구한 피보나치수열의 합은 = %d\n",Fibonacci_Loop(caculation_num));
        function_finish_time = clock(); // 종료시간계산
        duration = (double)(function_finish_time-function_start_time); // 단위는 per sec으로 시간을구한다
        printf("문복문으로 소요된 시간은= %f초입니다.\n",duration);
    }
    else return printf("잘못선택하셨습니다/n");
    
    return 0;
}




// 피보나치 재귀함수를 이용한 방법을 함수로 구현
int Fibonacci_Recursive(int caculation_num){
    //피보나치 수열의 정의에 따라 첫번째 항과 2번째항은 예외로 이렇게 두고 3번쨰 항부터 본격적인 계산이 시작된다.
    if(caculation_num == 0) return 0;
    else if(caculation_num == 1) return 1;
    else return Fibonacci_Recursive(caculation_num-1)+Fibonacci_Recursive(caculation_num-2);
}

// 피보나치 반복문을 이용한 방법을 함수로 구현
int Fibonacci_Loop(int caculation_num){
    int Fibo_mid = 1;
    int Fibo_head = 0;
    int Fibo_rear = 0;
    
    for(int i=0; i<caculation_num; i++){
        Fibo_rear = Fibo_mid+Fibo_head;
        Fibo_head = Fibo_mid;
        Fibo_mid = Fibo_rear;
    }
    return Fibo_rear;
}
