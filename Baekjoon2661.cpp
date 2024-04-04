/*
problem : 길이가 n이고 각 요소가 1, 2, 3 중 하나인 수열에서
          임의의 길이의 인접한 두 개의 부분 수열이 동일하지 않는 수열 중
          가장 작은 수를 나타내는 수열을 구해라.
input : 수열의 길이 n
output : 임의의 길이의 인접한 두 개의 부분 수열이 동일하지 않는 수열 중 가장 작은 수를 나타내는 수열

idea
- root가 고른 초기 숫자, node가 현재까지 완성한 수열, level이 고른 횟수를 의미하는 tree를 만든다.
- tree를 DFS 방식으로 탐색
- non-promising 조건 : 뒤에서부터 시작하여 길이가 (고른 횟수/2)가 될때까지 반복해 인접한 수열이 같은 수열일 경우
*/
#include <iostream>
#include <string>
using namespace std;

int ChooseCount;

// promising 검사
bool Promising(string current)
{
    for (int i = 1; i <= current.length() / 2; i++)
        if (current.substr(current.length() - i, i) == current.substr(current.length() - 2 * i, i))
            return false;
    return true;
}

// tree 탐색
bool DFS(string current, int cnt)
{
    if (!Promising(current))
        return false;

    // 모두 골랐다면 출력 후 탐색 중단
    if (cnt >= ChooseCount)
    {
        cout << current;
        return true;
    }

    // 탐색
    for (int i = 1; i <= 3; i++)
        if (DFS(current + to_string(i), cnt + 1))
            return true;

    // 찾지 못했으므로 false 반환
    return false;
}

int main()
{
    // 수열의 길이 입력
    cin >> ChooseCount;

    // tree 탐색
    for (int i = 1; i <= 3; i++)
        if (DFS(to_string(i), 1))
            break;

    return 0;
}