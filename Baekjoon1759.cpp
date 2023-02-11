/*
problem : n개의 char형 element에서 m개를 뽑아 increasing order로 sort된 문자열 중 모음이 1개, 자음이 2개 이상인 문자열을 모두 출력해라.
input : n개의 char형 element, 고를 element의 개수
output : n개의 char형 element에서 m개를 뽑아 increasing order로 sort된 문자열 중 모음이 1개, 자음이 2개 이상인 문자열

idea : 주어진 char형 element를 increasing order로 sort한 후 DFS 방식으로 탐색하여 m개를 뽑아 문자열을 만든다.
이때, 만들어진 문자열이 모음이 1개, 자음이 2개 이상 포함되어 있다면 출력한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

char input[15];        // n개의 char형 element를 가진 문자열 input
int length;            // 문자열의 길이 length == n
int choose;            // 고를 element의 개수 choose == m
char output[16];       // m개의 element를 골라 만들어진 문자열 output
bool isVisited[15];    // 각 element들의 방문 여부 isVisited

int vowel;             // 만들어진 문자열에서 모음의 개수 vowel
int consonant;         // 만들어진 문자열에서 자음의 개수 consonant

bool isVowel(char alpha)
{
    switch(alpha)
    {
        case 'a' : case 'e' : case 'i' : case 'o' : case 'u' :
            return true;
        default : 
            return false;
    }
}

void DFS(int currentCount, int startIndex)
{
    // m개를 모두 골랐다면, 만들어진 문자열이 모음 1개, 자음 2개 이상을 포함하는지 확인한 후 탐색 종료
    // 만약 모음 1개, 자음 2개 이상을 포함하면 문자열을 출력한다.
    if(currentCount == choose)
    {
        if(vowel >= 1 && consonant >= 2)
            cout << output << '\n';
        
        return;
    }
    
    // 문자열 input에서 startIndex 번째 문자부터 시작하여 DFS 방식으로 탐색해 m개를 뽑아 문자열을 만든다.
    // 이때 선택한 문자가 모음인지 자음인지 확인한 후, 1을 증가시킨다.
    for(int i=startIndex; i<length; i++)
    {
        if(!isVisited[i])
        {
            isVisited[i]=true;
            output[currentCount]=input[i];
            (isVowel(output[currentCount]) ? vowel : consonant) += 1;
            
            DFS(currentCount+1, i+1);
            
            isVisited[i]=false;
            (isVowel(output[currentCount]) ? vowel : consonant) -= 1;
        }
    }
}

int main()
{
    // input 입력
    cin >> choose >> length;
    for(int i=0; i<length; i++)
        cin >> input[i];
    
    // n개의 element를 increasing order로 sort
    sort(input, input+length);
    
    // n개의 element를 DFS 방식으로 m개를 뽑아 문자열을 만든다.
    DFS(0, 0);
    
    return 0;
}
