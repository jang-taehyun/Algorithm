/*
problem : n개의 수와 최대 4n개의 연산자가 주어졌을 때, 숫자의 순서를 바꾸지 않고 숫자 사이에 연산자를 넣어 만들 수 있는 수식의 최대값과 최소값을 구해라.
input : n개의 수, 최대 4n개의 연산자
output : 숫자의 순서를 바꾸지 않고 숫자 사이에 연산자를 넣어 만들 수 있는 수식의 최대값, 최소값

idea
- brute force를 이용해 연산자들을 (n-1)개 선택한다.
- 수식이 완성되면 수식을 계산해 최솟값과 최대값을 update한다.
*/
#include <iostream>
using namespace std;

int ArrayLength;                        // 수열의 길이
int InputArray[11];                     // 입력받은 수열(n개의 수)
int OperationCount[4];                  // 사용할 수 있는 연산자의 개수
                                        // 0 : +, 1 : -, 2 : *, 3 : /
int MaximumResult = -1000000000;        // 나올 수 있는 수식의 최대값
int MinimumResult = 1000000000;         // 나올 수 있는 수식의 최소값

void Bruteforce(int Length, int ComputeResult)
{
    // 수식을 완성했다면 최솟값과 최대값 update
    if (Length >= ArrayLength - 1)
    {
        if (ComputeResult > MaximumResult)
            MaximumResult = ComputeResult;
        if (ComputeResult < MinimumResult)
            MinimumResult = ComputeResult;

        return;
    }

    // 사용할 수 있는 연산자 중 하나를 골라 연산을 한다.
    for (int i = 0; i < 4; i++)
    {
        if (OperationCount[i])
        {
            OperationCount[i]--;
            switch (i)
            {
            case 0:
                Bruteforce(Length + 1, ComputeResult + InputArray[Length + 1]);
                break;
            case 1:
                Bruteforce(Length + 1, ComputeResult - InputArray[Length + 1]);
                break;
            case 2:
                Bruteforce(Length + 1, ComputeResult * InputArray[Length + 1]);
                break;
            case 3:
                Bruteforce(Length + 1, ComputeResult / InputArray[Length + 1]);
                break;
            }
            OperationCount[i]++;
        }
    }
}

int main()
{
    // n개의 숫자와 연산자의 개수 입력
    cin >> ArrayLength;
    for (int i = 0; i < ArrayLength; i++)
        cin >> InputArray[i];
    for (int i = 0; i < 4; i++)
        cin >> OperationCount[i];

    // brute force를 이용해 연산자들을 (n-1)개 선택하여 나온 수식의 최대값과 최소값을 구한다.
    Bruteforce(0, InputArray[0]);

    // 결과값 출력
    cout << MaximumResult << '\n' << MinimumResult;

    return 0;
}