/*
 * 학번 및 이름 : 2016101453 컴퓨터학부 유영주
 * 목적 및 개요:  3-1학기  알고리즘 과제 <Quick_Sort>
 * 과제수행날짜: 2018.03.21(수)
 * 프로그램 특징: 8개의 숫자를 "빠른정렬"하는 프로그램 작성
 * 사용언어: C언어
 * 참고자료: http://milvus.tistory.com/70
 *         기본 코드의 일부를 참조하였습니다.
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.3
 *   IDE: Xcode 9.2
 *   Compiler: gcc 4.2.1
 *   Text Encoding: UTF-8
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_fun();
void swap(int* a, int* b);
void quick_sort(int* array, int start, int end);

int array[8];

int main(int argc, const char * argv[]) {
    
    init_fun();  //초기화 함수 호출
    quick_sort(array, 0, 7);
    
    
    //정렬 후 숫자출출력
    printf("정렬완료 후 배열의 숫자 출력\n");
    for(int i=0; i<8; i=i+1){
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}



// 퀵정렬 프로그램의 입력 값을 받는 함수
void init_fun(){
    printf("퀵 정렬을 하는 프로그램입니다\n");
    printf("숫자 8개를 입력해주세요\n");
    
    for(int i=0; i<8; i=i+1){
        scanf("%d", &array[i]);
    }
    
    printf("\n");
    printf("입력하신 숫자");
    printf("\n");
    
    for(int i=0; i<8; i=i+1){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 포인터를 이용한 swap함수
void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}




void quick_sort(int* array, int start, int end){
    
    if(start>=end) return;
    
    int mid=(start+end)/2;
    int pivot=array[mid];
    printf("mid위치 = %d\n", mid);
    printf("pivot값 = %d\n", pivot);
    printf("\n");
    
    // 피벗은 중간으로 잡았다.
    // 시작 부분을 중간으로 보낸다. 피벗 값을 맨 앞으로 두기 위해서
    printf("스왑전 start mid %d %d\n", array[start],array[mid]);
    swap(&array[start],&array[mid]);
    printf("스왑후 start mid %d %d\n", array[start],array[mid]);
    int p=start+1; // 위의 논리에서 피봇의 값이 pivot=array[mid]정해지고 피봇이 1번째 배열로 들어가고, 위치가 1번째 배열로 들어간 피봇 값의 다음 배열 값 인덱스를 위한 변수다.
    int q=end; // 이것은 배열의 맨뒤에서부터 배교를 당하는 변수다.
    
    while(1){
        printf("while 전구문 array[%d] = %d\n",p, array[p]);
        while(array[p]<=pivot){ p++; } // p는 앞으로 나아가며 비교한다.
        printf("while 후구문 array[%d] = %d\n",p, array[p]);
        printf("while 전구문 array[%d] = %d\n",q, array[q]);
        while(array[q]>pivot){ q--; }// q는 끝에서부터 시작하니 점점 뒤로오며 비교한다.
        printf("while 후구문 array[%d] = %d\n",q, array[q]);
        
        if(p>q) break;  // 앞에서 오는 p와 뒤에서 오는 q가 만나면 정지한다.
        
        printf("while 구문  swap전 array[p] array[q] %d %d\n",array[p], array[q]);
        swap(&array[p],&array[q]); // while조건에 array[p],array[q]가 여기서 자리를 바꾼다.
        //바꾸고 난뒤 p,q는 아직 그 값이 똑같고, 바뀐 이후에 p,q가 카운트가 된다.
        printf("while 구문  swap후 array[p] array[q] %d %d\n\n",array[p], array[q]);
    }
    
    printf("마지막 swap전 array[start] array[q] %d %d\n", array[start], array[q]);
    swap(&array[start],&array[q]);  // 마지막에 피벗값 맨 앞에 있고, 마지막남은 비교대상이랑 자리를 바꾸면 최종 정렬이 수행된다.
    printf("마지막 swap후 array[start] array[q] %d %d\n\n", array[start], array[q]);
    printf("일단 정렬 마치고 난 후 배열 상태\n");
    for(int t=0; t<8; t++){
        printf("%d ", array[t]);
    }
    printf("\n");
    
    
    printf("재귀 분할전의 q의 값 = %d\n", q);
    printf("분할 왼쪽 재귀시작\n");
    quick_sort(array,start,q-1);
    printf("분할 오른쪽 재귀시작\n");
    quick_sort(array,q+1,end);
    
}




