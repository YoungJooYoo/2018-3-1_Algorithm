/*
 * 작성자 정보: 2016101453 컴퓨터학부 유영주
 * 목적 및 개요: 3-1학기 알고리즘 과제  <제9주 되추적(Backtracking) 프로그래밍 과제>
 * 과제수행날짜: 2018.05.07(월)
 * 프로그램 특징: 되추적을 이용한 여왕말 문제 해결
 * 사용언어: C언어
 * 참조자료 : https://www.thecrazyprogrammer.com/2015/03/c-program-for-n-queens-problem-using-backtracking.html
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.4
 *   IDE: Xcode 9.3
 *   Compiler: gcc 4.2.1
 *   Text Encoding: UTF-8
 */


/*
 * 숙제사항:
          n-Queen 여왕말 문제를 확장(5-Queen, 7-Queen)하여
          n개의 Queen이 서로 상대방을 위협하지 않도록 하는 되추적 프로그래밍을 작성하세요.
          즉 queen()함수호출과 col[] 배열의 값을 출력하고, 그 결과를 가지고 상태공간트리를 만들어 보세요.
 */



#include<stdio.h>
#include<math.h>

int board[20],count;   // 체스보드의 크기는 일단 20개로 잡는다.

int main(int argc, const char * argv[]) {
    
    int n;  // 체스판의 갯수 n  인덱스 i, j선언
    void queen(int row,int n);
    
    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens:");  // 체스판 몇개로 하신건가요?
    scanf("%d",&n);
    queen(1,n);
    printf("\n");
    return 0;
}

//function for printing the solution ,  체스판을 시각화하는 print 함수
void print(int n)
{
    int i,j;
    printf("\n\nSolution %d:\n\n",++count);  // 여왕 말을 두는 방법은 여러가지다. 방법을의 갯수를 출력
    
    for(i=1;i<=n;++i)   // 체스판의 갯수 중 가로 행 갯수 출력
        printf("\t%d",i);
    
    for(i=1;i<=n;++i) // 체스판 갯수 중 세로 열 갯수 출력
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j) //for nxn board , 실제 체스판( 2차원 배열) 출력
        {
            if(board[i]==j)
                printf("\tQ"); //queen at i,j position  퀸함수에 board[row]=column, column은 j의미 성립하면 q 출력
            else
                printf("\t-"); //empty slot
        }
    }
}

/*funtion to check conflicts
 If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;++i)
    {
        //checking column and digonal conflicts
        if(board[i]==column)   // 퀸은 대각선에 둘 수 없으므로 체크한다.
            return 0;
        else
            if(abs(board[i]-column)==abs(i-row))
                return 0;
    }
    
    return 1; //no conflicts
}

//function to check for proper positioning of queen
void queen(int row,int n)   // row는 1부터 시작
{
    int column;
    for(column=1;column<=n;++column) // 열은 입력 받은 n개 만큼
    {
        if(place(row,column))  // place 함수의 값에 따라 if구문 실행
        {
            board[row]=column; //no conflicts so place queen 충돌없으니 여왕배치
            if(row==n) //dead end 행이 끝나면 프린트
                print(n); //printing the board configuration
            else //try queen with next position
                queen(row+1,n);  // 행이 아직 끝나지 않았으면 row+1로 계속 진행한다.
        }
    }
}
