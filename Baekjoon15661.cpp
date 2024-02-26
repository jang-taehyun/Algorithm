/*
problem : n개의 element 중에서 1개 이상을 골라 2개의 그룹으로 나눌 때, 두 그룹의 W의 합의 차이(|W1-W2|)의 최소값을 구해라.
input : element의 개수, 각각의 element의 weight
output : n개의 element 중에서 1개 이상을 골라 2개의 그룹으로 나눌 때, 두 그룹의 W의 합의 차이(|W1-W2|)의 최소값

idea : n개의 element를 DFS 방식으로 1~n/2개까지 고른 후, 고른 그룹과 고르지 않은 그룹의 W의 합의 차이(|W1-W2|)를 구한다.
*/
#include <iostream>
using namespace std;

int n;                // element의 개수
int S[20][20];        // 각각의 element의 weight
bool isChoose[20];    // element의 선택 여부
int result=999999999; // |W1-W2|의 최소값

// |W1-W2| 계산
void GroupCalculation(int choose)
{
    // 두 그룹을 각각의 array에 저장
    int chooseGroup[20];
    int notChooseGroup[20];
    
    int index1=0, index2=0;
    for(int i=0; i<n; i++)
    {
        if(isChoose[i])
            chooseGroup[index1++]=i;
        else
            notChooseGroup[index2++]=i;
    }
    
    // W1, W2 계산
    int W1=0;
    for(int i=0; i<choose; i++)
        for(int j=0; j<choose; j++)
            W1 += S[chooseGroup[i]][chooseGroup[j]];
    
    int W2=0;
    for(int i=0; i<n-choose; i++)
        for(int j=0; j<n-choose; j++)
            W2 += S[notChooseGroup[i]][notChooseGroup[j]];
    
    // |W1-W2| 계산 후, 이전에 얻었던 최소값보다 더 작은지 확인
    result = abs(W1-W2) < result ? abs(W1-W2) : result;
}

void DFS(int currentCount, int startIndex, int choose)
{
    // choose개를 모두 골랐다면 두 그룹의 W의 합을 구한 후, 차이가 최소값인지 확인한다.
    // 이후, 탐색을 종료한다.
    if(currentCount == choose)
    {
        GroupCalculation(choose);
        return;
    }
    
    // n개의 element 중에서 DFS 방식을 이용해 choose개를 고른다.
    // 이때 선택된 element들은 increasing order로 sort되어 있으므로 startIndex부터 시작한다.
    for(int i=startIndex; i<n; i++)
    {
        if(!isChoose[i])
        {
            isChoose[i]=true;
            DFS(currentCount+1, i+1, choose);
            isChoose[i]=false;
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
    
    // DFS 방식을 이용해 n개의 element 중 1~n/2개를 고른 후 |W1-W2|의 최소값을 구한다.
    for(int i=1; i<=n/2; i++)
        DFS(0, 0, i);
    
    // 결과값 출력
    cout << result;
    
    return 0;
}
