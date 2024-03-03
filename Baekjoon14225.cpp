/*
Problem : 입력된 수열을 모두 조합한 후, 나올 수 없는 가장 작은 자연수를 구해라.
Input : 수열 S
Output : 나올 수 없는 가장 작은 자연수

Idea
- 수열 S를 오름차순으로 정렬한다.
- bruteforce를 이용해, 수열 S에서 나올 수 있는 모든 조합을 구하고 방문 표시를 한다.
- 방문 표시를 검사해 나올 수 없은 가장 작은 자연수를 구한다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ArrayLength;                      // 수열 S의 길이
int Input[20];                        // 수열 S
bool visited[2000001];                // 조합된 수의 방문 여부
bool ArrayVisited[20];                // 수열 S의 각 요소의 방문 여부

void Bruteforce(int Start, int Sum, int Length)
{
    // 수열의 길이만큼 모두 골랐다면, 함수 종료
    if (Length >= ArrayLength)
        return;

    // 시작점에서부터 '수열의 길이'만큼 요소를 선택하고,
    // 방문 표시를 한다.
    for (int i = Start; i < ArrayLength; i++)
    {
        // 아직 방문하지 않는 점이라면 방문한다.
        if (!ArrayVisited[i])
        {
            ArrayVisited[i] = true;
            visited[Sum + Input[i]] = true;
            Bruteforce(i, Sum + Input[i], Length + 1);
            ArrayVisited[i] = false;
        }
    }
}

int main()
{
    // 수열의 길이와 수열 S 입력
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> Input[i];

    // Bruteforce로 모든 조합을 구하고 방문 표시를 한다.
    Bruteforce(0, 0, 0);

    // 결과값 출력
    for (int i = 1; i < 2000001; i++)
        if (!visited[i])
        {
            cout << i;
            break;
        }

    return 0;
}