/*
problem : n개의 element을 2개의 그룹으로 나눠 |W1[i][j]-W2[i][j]|의 최소값을 구해라.
input : element의 개수, S[i][j]
output : |W1[i][j]-W2[i][j]|

idea : n개의 element을 DFS 방식으로 2개의 그룹으로 나눈다.
그 후 n/2개를 고르면 S[i][j]를 이용해, W1[i][j]와 W2[i][j]를 구해 |W1[i][j]-W2[i][j]|를 구한다.
*/
#include <iostream>
using namespace std;

int n;                  // element의 개수
int S[20][20];          // S[i][j]
int result=99999999;    // |W1[i][j]-W2[i][j]|의 최소값
bool isVisited[20];     // element 방문 여부

// |W1[i][j]-W2[i][j]| 계산
void GroupCalculation()
{
    // 2개의 그룹을 각각의 array에 저장
    int chooseGroup[10];
    int notChooseGroup[10];
    
    int index1=0, index2=0;
    for(int i=0; i<n; i++)
    {
        if(isVisited[i])
            chooseGroup[index1++]=i;
        else
            notChooseGroup[index2++]=i;
    }
    
    // W1, W2 계산
    int W1=0, W2=0;
    for(int i=0; i<n/2; i++)
    {
        for(int j=0; j<n/2; j++)
        {
            W1 += S[chooseGroup[i]][chooseGroup[j]];
            W2 += S[notChooseGroup[i]][notChooseGroup[j]];
        }
    }
    
    // 이전에 얻어진 최소값과 현재 얻어진 최소값 비교
    result = abs(W1-W2) < result ? abs(W1-W2) : result;
}

void DFS(int currentCount, int startIndex)
{
    // n/2개를 모두 골랐다면 |W1[i][j]-W2[i][j]| 계산 후 탐색 종료
    if(currentCount == n/2)
    {
        GroupCalculation(); 
        return;
    }
    
    // DFS 방식으로 startIndex번째부터 시작하여 n개의 element 중에서 n/2개를 선택한다.
    for(int i=startIndex; i<n; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i]=true;
            DFS(currentCount+1, i+1);
            isVisited[i]=false;
        }
    }
}

int main()
{    
    // input 입력
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> S[i][j];
    
    // |W1[i][j]-W2[i][j]|의 최소값 찾기
    DFS(0, 0);
    
    // 결과값 출력
    cout << result;
    
    return 0;
}
