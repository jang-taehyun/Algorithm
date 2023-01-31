/*
problem : 1부터 n까지 자연수 중 중복을 허용하여 m개를 고를 때 non-decreasing order인 수열을 모두 출력하라.
input : 자연수 n, m
output : 1부터 n까지 자연수 중 중복을 허용하여 m개를 고를 때 non-decreasing order로 정렬된 수열

idea : 숫자를 DFS 방식으로 탐색하면 수열을 채운다.
*/
#include <iostream>
using namespace std;

int output[8];    // 수열 output
int bound;        // bound == n
int choose;       // choose == m

void DFS(int currentCount, int startNumber)
{
    // m개를 모두 골랐다면 수열 출력 후 function 종료
    if(currentCount == choose)
    {
        for(int i=0; i<choose; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    // startNumber부터 n까지 DFS 방식으로 탐색하면서 수열을 채운다.
    for(int i=startNumber; i<=bound; i++)
    {
        output[currentCount] = i;
        DFS(currentCount+1, i);
    }
}

int main()
{
    cin >> bound >> choose;
    DFS(0, 1);
    
    return 0;
}
