/*
problem : n*m 칸의 숫자가 적힌 직사각형 종이를 1*k 또는 p*1 짜리 조각으로 나눈 후 조각의 합을 구할 때, 최대값을 구해라.
input : n*m 칸의 직사각형
output : 조각들의 합의 최대값

idea : bit를 이용해, 각 경우((0 ~ m*n) == (0 ~ (1 << m*n)))에서 나오는 합 중에서 최대값을 구한다.
ex) 3(0000 0000 0000 0101)을 다음과 같은 형태로 생각할 수 있다.
    0000
    0000
    0000
    0101
    여기에서 0은 column으로 찢어진 종이, 1은 row로 찢어진 종이로 생각한다.
*/
#include <iostream>
using namespace std;

int main()
{
    int rectangle[4][4];        // n*m 칸의 직사각형 rectangle
    int column;                 // 세로 column
    int row;                    // 가로 row
    int result=0;               // 최대값 result
    
    // input 입력
    cin >> column >> row;
    for(int i=0; i<column; i++)
    {
        string input;
        cin >> input;
        for(int j=0; j<row; j++)
            rectangle[i][j] = input[j]-'0';
    }
    
    // 각 경우에서 나오는 조각들의 합 중 최대값을 찾는다.
    for(int testcase=0; testcase < (1 << (column * row)); testcase++)
    {
        // 현재 경우에서 나온 합 sum
        int sum=0;
        
        // column으로 조각난 종이(bit에서 0으로 표시된 자리)의 합을 구한다.
        for(int i=0; i<column; i++)
        {
            for(int j=0; j<row; j++)
            {
                // NOT 연산과 AND 연산을 이용해 0으로 표시되었는지 확인
                // 이때 i*column+j가 아닌 i*row+j을 해준다.(2*3 직사각형의 경우를 생각하면 한번에 이해된다.)
                if(~testcase & (1 << (i*row+j)))
                {
                    // 0으로 표시된 자리를 조합해 숫자 만들기
                    int number=0;
                    while(j<row && ~testcase & (1 << (i*row+j)))
                    {
                        number*=10;
                        number+=rectangle[i][j];
                        j++;
                    }
                    
                    // 만들어진 숫자를 sum에 더하기
                    sum += number;
                }
            }
        }
        
        // row로 조각난 종이(bit에서 1로 표시된 자리)의 합을 구한다.
        for(int j=0; j<row; j++)
        {
            for(int i=0; i<column; i++)
            {
                // AND 연산을 이용해 1으로 표시되었는지 확인
                if(testcase & (1 << (i*row+j)))
                {
                    // 1로 표시된 자리를 조합해 숫자 만들기
                    int number=0;
                    while(i<column && testcase & (1 << (i*row+j)))
                    {
                        number*=10;
                        number+=rectangle[i][j];
                        i++;
                    }
                    
                    // 만들어진 숫자를 sum에 더하기
                    sum += number;
                }
            }
        }
        
        // 현재 경우에서 만들어진 숫자와 이전에 만들어진 최대값 중 더 큰 것을 최대값으로 한다.
        result = sum > result ? sum : result;
    }
    
    // 최대값 출력
    cout << result;
    
    return 0;
}
