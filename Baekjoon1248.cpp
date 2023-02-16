/*
problem : Sij(Sij = a(i) + a(i+1) + ... a(j))의 부호가 n(n+1)/2개 주어질 때, 거기에 맞는 n개의 정수를 구해라.
input : 정수의 개수 n, Sij의 부호
output : Sij의 부호에 맞는 n개의 정수로 이루어진 수열

idea : -10~10 사이의 정수를 하나 고른 후, 현재까지 만들어진 수열이 Sij와 같은지 확인한다.
-> row index를 고정하고, column index를 하나씩 줄여가면서 Sij와 같은지 확인한다.
*/
#include <iostream>
using namespace std;

char sign[10][10];             // Sij의 부호 sign
int n;                         // 정수의 개수 n
int output[10];                // 만들어진 수열 output

// 현재까지 만들어진 수열이 Sij와 맞는지 확인
// -> row를 고정하고 column을 계산한다.
bool Check(int row)
{
    int sum=0;
    for(int column=row; column>-1; column--)
    {
        sum += output[column];
        
        if(sign[column][row] == '+' && sum <= 0)
            return false;
        if(sign[column][row] == '-' && sum >= 0)
            return false;
        if(sign[column][row] == '0' && sum != 0)
            return false;
    }
    
    return true;
}

void DFS(int currentIndex)
{
    // n개를 모두 채웠다면 만들어진 수열 출력 후 프로그램 종료
    if(currentIndex == n)
    {
        for(int i=0; i<n; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        exit(0);
        
        return;
    }
    
    // DFS 방식을 이용해 n개의 element를 고른다.
    for(int i=-10; i<=10; i++)
    {
        output[currentIndex] = i;
        if(Check(currentIndex))
            DFS(currentIndex+1);
    }
}

int main()
{    
    // input 입력
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            cin >> sign[i][j];
    
    // 탐색 시작
    DFS(0);
    
    return 0;
}
