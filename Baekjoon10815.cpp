/*
problem : -10^7 ~ 10^7 사이의 숫자가 적혀있는 카드를 n개 가지고 있을 때,
          -10^7 ~ 10^7 사이의 숫자가 적혀있는 카드 m개 중 가지고 있는 카드를 구해라.
input : 가지고 있는 카드의 개수 n(1 ~ 5*10^5), 가지고 있는 카드에 적혀 있는 숫자들,
        비교할 카드의 개수 m(1 ~ 5*10^5), 비교할 카드들에 적혀 있는 숫자들
output : -10^7 ~ 10^7 사이의 숫자가 적혀있는 카드 m개 중 가지고 있는 카드

idea
- n개의 숫자들을 저장하고 오름차순으로 정렬
- m개의 숫자들 중 1개가 입력될 때마다 binary search를 이용해 탐색
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_HAVE 500000
using namespace std;

int Having[MAX_HAVE];                // 가지고 있는 숫자 카드들
int HavingCount;                     // 가지고 있는 숫자 카드의 개수

bool BinarySearch(int _target)
{
    int Start = 0;
    int Last = HavingCount - 1;
    int Middle;

    // start가 last를 넘어가면 중단
    while (Start <= Last)
    {
        Middle = (Start + Last) / 2;

        if (Having[Middle] == _target)
            return true;

        if (Having[Middle] < _target)
            Start = Middle + 1;
        else
            Last = Middle - 1;
    }

    // 찾지 못했으므로 false 반환
    return false;
}

int main()
{
    int PresentCount;                // 제시된 숫자 카드의 개수
    int PresentNumber;               // 제시된 숫자 카드
    vector<bool> IsHave;             // 제시된 숫자 카드를 가지고 있는지 여부
    bool result;                     // binary search 후 결과

    // 가지고 있는 카드의 수와 카드에 적힌 숫자 입력
    cin >> HavingCount;
    for (int i = 0; i < HavingCount; i++)
        cin >> Having[i];

    // 입력된 숫자 카드들을 오름차순으로 정렬
    sort(Having, Having + HavingCount);

    // 제시된 카드 중 가지고 있는 숫자 카드를 vector에 저장
    cin >> PresentCount;
    for (int i = 0; i < PresentCount; i++)
    {
        cin >> PresentNumber;

        result = BinarySearch(PresentNumber);
        IsHave.push_back(result);
    }

    // 결과값 출력
    for (int i = 0; i < PresentCount; i++)
        cout << IsHave[i] << ' ';

    return 0;
}