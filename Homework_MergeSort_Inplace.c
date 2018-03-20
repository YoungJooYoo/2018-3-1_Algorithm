/*
 * 학번 및 이름 : 2016101453 컴퓨터학부 유영주
 * 목적 및 개요:  3-1학기  알고리즘 과제 <8개의 임의의 수를 정렬하는 제자리 정렬>
 * 과제수행날짜: 2018.03.20(화)
 * 프로그램 특징: 제자리 정렬을 이용한 정렬 프로그램
 *
 * 사용언어: C언어
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.3
 *   IDE: Xcode 9.2
 *   Compiler gcc 4.2.1
 *   Text Encoding : UTF-8
 */



// 아아아아아ㅏ아아아 미완성!!!! 오류를 못잡겠어!!!


#include<stdio.h>
#include<stdlib.h>

// 8은 배열의 인덱스다
//함수선언
void inplace_merge_sort(int sort_array_start, int sort_array_mid, int sort_array_end); // 배열을 정렬하는 함수
void Devide(int array_start, int array_end); // 배열을 분할하는 함수

int array[8] = {0,0,0,0,0,0,0,0};
int sorted_array[8] = {0,0,0,0,0,0,0,0};
int array_start = 0;
int array_end = 7;


int main(){
    printf("정렬할 숫자를 8개 입력해주세요\n");
    
    for(int input_i=0; input_i<8; input_i++){
        scanf("%d", &array[input_i]);
        //함수실행 구문 넣고
        // 각 함수마다. printf로 주소 출력하기
    }
    
    printf("입력하신 8개의 숫자입니다.\n");
    for(int print_i=0; print_i<8; print_i++){
        printf("%d ",array[print_i]);
    }
    printf("\n");
    
    //매개변수로 쓸 인수를 여기에
    //함수실행
    Devide(array_start,array_end);
    
    printf("8개의 숫자가 정렬되었습니다.\n");
    for(int print_i=0; print_i<8; print_i++){
        printf("%d ",array[print_i]);
    }
    printf("\n");

    
}


void inplace_merge_sort(int sort_array_start, int sort_array_mid, int sort_array_end) {
    
    int i=sort_array_start; // 원본 배열을 변수를 비교위한 인덱스, 비교대상_1
    int j=sort_array_mid+1; // 원본 배열을 변수를 비교위한 인덱스, 비고대상_2
    int k=sort_array_start; // 새로 생성한 배열을 위한 인덱스
    
    //printf("변수확인 i=%d j=%d k=%d \n", i,j,k); 변수까지 이상무
    
    while(i<=sort_array_mid && j<=sort_array_end){ //여기서 합쳐지면서 정렬을 수행한다.
        // i는 왼쪽을 정렬하고 mid까지가 마지막, J는 오른쪽을 정렬 end가 마지막.
        
        //문제는 조건절에서 복사가 제대로 안된다.  2는복사 되는데 1이 복사가 안되 1->8순차입력시
        if(array[i]<array[j]){
            printf("복사전 while문 테스트 배열출력문  = %d\n", array[i]);
            printf("복사전 while문 테스트 임시배열출력문  = %d\n", sorted_array[k]);
            sorted_array[k]=array[i];
            printf("복사후 while문 테스트 배열출력문  = %d\n", array[i]);
            printf("복사후 while문 테스트 임시배열출력문  = %d\n", sorted_array[k]);
            i=i+1;
            
        }
        else{
            printf("복사전while문 테스트 배열출력문  = %d\n", array[i]);
            printf("복사전while문 테스트 임시배열출력문  = %d\n", sorted_array[k]);
            sorted_array[k]=array[j];
            printf("복사후while문 테스트 배열출력문 = %d\n", array[i]);
            printf("복사후while문 테스트 임시배열출력문 = %d\n", sorted_array[k]);
            j=j+1;
            
        }
        k=k+1;
    }
    
        if(i>sort_array_mid){ // 정렬이 수행되고 남은 배열들을 그대로 복사한다 why? 이미 정렬이 되어있으니 그냥 복사
            //새로운 임시 변수 추가하기
            
            int copy_j = j;  //원래배열을 임시배열에 복사를 위한 반복구문의 인덱스
            int copy_k = k;  //원래배열을 임시배열에 복사를 위한 반복구문의 인덱스
            
            for(copy_j=j; copy_j<=sort_array_end; copy_j++){
            sorted_array[copy_k] =array[copy_j]; //정렬이 환료후 남은 분할(왼쪽부분)을 임시배열로 복사
                copy_k=copy_k+1;
            }
        }
        else{
            int copy_i = i;  //원래배열을 임시배열에 복사를 위한 반복구문의 인덱스
            int copy_k2 = k;  //원래배열을 임시배열에 복사를 위한 반복구문의 인덱스
            
            for (copy_k2=k; copy_i<=sort_array_mid; copy_i++){
                sorted_array[copy_k2] =array[copy_i]; //정렬이 환료후 남은 분할(왼쪽부분)을 임시배열로 복사
                copy_k2=copy_k2+1;
            }
        }
        //배열이 정리된 추가 배열을 원래 배열에 넣는 작업을 한다.
        for(int t=0; t<8; t++){
            array[t] = sorted_array[t];
        }
}

void Devide(int array_start, int array_end){
    int array_mid=0;
    
    if(array_start<array_end){
        array_mid = (array_start+array_end)/2;
        Devide(array_start,array_mid);
        Devide(array_mid+1,array_end);
        printf("디바이드함수 매개변수 잘 먹었나 확인 = %d %d\n",array_start, array_end);
        inplace_merge_sort(array_start, array_mid,array_end);
    }
}
