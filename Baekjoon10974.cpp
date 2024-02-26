/*
problem : 1부터 n까지의 숫자로 만들 수 있는 모든 수열을 사전순으로 출력해라.
input : 숫자의 범위 n
output : 1부터 n까지의 숫자로 만들 수 있는 모든 수열

idea : DFS 방식으로 1부터 n까지 숫자를 탐색하면서 수열을 만든다. 이때 중복없이 숫자를 사용해야 하므로, 방문하였다면 방문 표시를 남기면서 탐색한다.
*/
#include <iostream>
using namespace std;

int range;            // 숫자의 범위 range == n
int output[8];        // 만들어진 수열 output
bool isVisited[9];    // 숫자 방문 여부 isVisited

void DFS(int currentCount)
{
    // 1부터 n까지의 숫자를 모두 골랐다면, 만들어진 수열을 출력한 후 탐색을 종료한다.
    if(currentCount == range)
    {
        for(int i=0; i<range; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    // 1부터 n까지의 숫자들을 DFS 방식으로 탐색한다.
    // 이때, 이미 방문한 숫자(이미 수열에 포함된 숫자)는 고르지 않는다.
    for(int i=1; i<range+1; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i]=true;
            output[currentCount]=i;
            DFS(currentCount+1);
            isVisited[i]=false;
        }
    }
}

int main()
{
    // input 입력
    cin >> range;
    
    // 1부터 n까지 DFS 방식으로 수열을 만든다.
    DFS(0);
    
    return 0;
}
