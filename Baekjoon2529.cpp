/*
problem : k개의 부등호 기호를 만족하는 (k+1)자리 정수 중 최대값과 최소값을 구해라.
input : k개의 부등호 기호
output : (k+1)자리 정수 중 최대값과 최소값

idea : DFS 방식을 이용해 (k+1)자리 정수를 만든 후 k개의 부등호와 맞는지 확인한다.
*/
#include <iostream>
#include <cstring>
using namespace std;

char inequality[9];                   // 부등호 inequality
int inequalityCount;                  // 부등호개수 inequalityCount
char currentNumber[11];               // 현재 만들어진 정수 currentNumber
char minimum[11];                     // 현재까지 통과된 정수 중 가장 작은 정수(문자열) minimum
long long minimumNumber=9999999999;   // 현재까지 통과된 정수 중 가장 작은 정수(정수) minimumNumber
char maximum[11];                     // 현재까지 통과된 정수 중 가장 큰 정수(문자열) maximum
long long maximumNumber;              // 현재까지 통과된 정수 중 가장 큰 정수(정수) maximumNumber
bool isVisited[10];                   // 숫자 탐색 여부 isVisited

void DFS(int currentCount)
{
    // (k+1)개의 정수를 모두 골랐다면, k개의 부등호를 모두 만족하는지 확인한 후 탐색 종료
    if(currentCount == inequalityCount+1)
    {
        for(int i=0, j=0; i<inequalityCount, j<inequalityCount+1; i++, j++)
        {
            if(inequality[i] == '<' && currentNumber[j] > currentNumber[j+1])
                return;
            if(inequality[i] == '>' && currentNumber[j] < currentNumber[j+1])
                return;
        }
        
        long long temp = atoll(currentNumber);
        if(temp > maximumNumber)
        {
            strcpy(maximum, currentNumber);
            maximumNumber=temp;
        }
        if(temp < minimumNumber)
        {
            strcpy(minimum, currentNumber);
            minimumNumber=temp;
        }
        
        return;
    }
    
    // DFS 방식을 이용해 (k+1)개의 정수를 고른다.
    for(int i=0; i<10; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i]=true;
            currentNumber[currentCount]=i+'0';
            DFS(currentCount+1);
            isVisited[i]=false;
        }
    }
}

int main()
{
    // input 입력
    cin >> inequalityCount;
    for(int i=0; i<inequalityCount; i++)
        cin >> inequality[i];
    
    // DFS 방식을 이용해 (k+1)개의 정수를 고른 후, k개의 부등호와 맞는지 확인한다.
    DFS(0);
    
    // 찾아진 최소값과 최대값 출력
    cout << maximum << '\n' << minimum;
    
    return 0;
}
