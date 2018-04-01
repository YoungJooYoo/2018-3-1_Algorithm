/*
 * 작성자 정보 : 2016101453 컴퓨터학부 유영주
 * 목적 및 개요:  3-1학기  알고리즘 과제  <Binomial_Coeffcient>
 * 과제수행날짜: 2018.04.01(일)
 * 프로그램 특징: 분할정복과 동적계획으로 이항계수 구하기
 * 참고자료 : https://blog.naver.com/gywhd8928/220513756901
 * 사용언어: C
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.3
 *   IDE: Xcode 9.3
 *   Compiler gcc 4.2.1
 */


#include <stdio.h>
#include <time.h>

int recursiveBinomial(int n, int k){
    if(k == 0 || k == n){
        printf("k==0 k==n 인경우 k = %d  n = %d\n",n,k);
        return 1;
    }
    else{
        printf("계산중 n-1 = %d  k-1 = %d\n",n-1,k-1);
        return recursiveBinomial(n-1, k-1) + recursiveBinomial(n-1, k);
    }
    
}


int binomial(int **arr, int n, int k){
    int i, m;
    arr = (int **)malloc(sizeof(int *) * (n+1));
    for(i = 0; i < n+1; i++)
        arr[i] = (int *)malloc(sizeof(int *) * (k+1));
    
    for(i = 0; i < n+1; i++)
    {
        for(m = 0; m < i+1; m++)
        {
            if(i == m || m == 0){
                arr[i][m] = 1;
                printf("k==0 k==n 인경우 i = %d  m = %d \n",i,m);
            }
            else if(i > m && m > 0){
                arr[i][m] = arr[i-1][m-1] + arr[i-1][m];
                printf("계산중 i = %d  m= %d\n",i,m);
            }
        }
    }
    
    return arr[n][k];
}


int main(int argc, const char * argv[]) {
    
    int array[2];  // n과 k를 위한 인덱스
    clock_t function_start_time, function_finish_time; //시간 측정을 위한 변수 2개 시작점과 끝점
    double duration ; // 끝시간-시작시간 = 연산시간이므로 이 변수를 선언한다.
    
    
    printf("n값을 입력해주세요");
    scanf("%d",&array[0]);
    printf("k값을 입력해주세요");
    scanf("%d",&array[1]);
    
    // 재귀 방법으로 구하고 시간측정
    function_start_time = clock(); // 시작시간 계산
    printf("이항 계수의 합은 = %d\n", recursiveBinomial(array[0],array[1]) );
    function_finish_time = clock(); // 종료시간계산
    duration = (double)(function_finish_time-function_start_time); // 단위는 microsec으로 시간을구한다
    printf("재귀방법으로 소요된 시간은= %fmsec입니다.\n",duration);
    printf("\n\n");
    
    // 동적계획으로 구하고 시간측정
    function_start_time = clock(); // 시작시간 계산
    printf("이항 계수의 합은 = %d\n", recursiveBinomial(array[0],array[1]) );
    function_finish_time = clock(); // 종료시간계산
    duration = (double)(function_finish_time-function_start_time); // 단위는 microsec으로 시간을구한다
    printf("동적계획으로 소요된 시간은= %fmsec입니다.\n",duration);
    printf("\n\n");
    
    return 0;
}
