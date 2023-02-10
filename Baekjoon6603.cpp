/*
problem : 각 test마다 주어지는 n개의 element에서 중복없이 6개를 뽑는 방법을 모두 구해라.
input : 수열 array
output : 각 test마다 수열 array에서 중복없이 6개의 element를 뽑는 방법

idea : 수열 array를 DFS 방식으로 탐색하여 6개를 뽑은 후 뽑은 결과를 출력한다.
여기에서 만들어지는 tree는 다음과 같다.
             (1)
  (2)     (3)   (4)  (5)
(3 4 5)  (4 5)  (5)
*/
#include <iostream>
using namespace std;

const int choose = 6;  // 고를 element의 개수 choose(6)
int input[12];         // 주어지는 수열 input == array
int length;            // 수열 array의 길이 == n
bool isVisited[12];    // 수열 array의 index번째 요소 방문 여부 isVisited
int output[choose];    // 수열 array에서 6개의 element를 뽑아 만들 수 있는 수열 output

void DFS(int currentCount, int startIndex)
{
    // choose개를 모두 뽑았다면, 만들어진 수열 출력 후 탐색 종료
    if(choose == currentCount)
    {
        for(int i=0; i<choose; i++)
            cout << output[i] << ' ';
        cout << '\n';
        
        return;
    }
    
    // DFS 방식으로 startIndex번째부터 시작하여 choose개의 element를 뽑아 수열을 만든다.
    for(int i=startIndex; i<length; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i] = true;
            output[currentCount] = input[i];
            DFS(currentCount+1, i+1);
            isVisited[i] = false;
        }
    }
}

int main()
{
    while(1)
    {
        // 수열의 길이 length 입력
        // 만약 0이라면, loop 종료
        cin >> length;
        if(!length)
            break;
        
        // 수열 array의 element 입력
        for(int i=0; i<length; i++)
            cin >> input[i];
        
        // DFS 방식으로 수열 array에서 choose개를 골라 수열을 만든다.
        DFS(0, 0);
        cout << '\n';
    }
    
    return 0;
}
