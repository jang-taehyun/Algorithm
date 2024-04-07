/*
problem : 두 개의 숫자를 더하고 다시 2개의 소수로 나눌 수 있는지 판별해라.
input : 2개의 숫자
output : 두 개의 숫자를 더하고 다시 2개의 소수로 나눌 수 있는지 여부

idea
- 소수는 에라토스테네스의 체를 이용해 2*10^6까지 구한다.
- 두 개의 숫자를 더한 결과가 짝수라면 무조건 2개의 소수로 나눌 수 있다.(골드바흐의 추측)
- 두 개의 숫자를 더한 결과가 홀수라면 (2+소수)로 나눌 수 있는지 확인한다.
*/
#include <iostream>
#include <vector>
#define BOUND 2000001
using namespace std;

bool IsNotPrimary[BOUND];        // 소수인지 아닌지 여부

int main()
{
    int test;
    long long input1, input2;
    long long sum;
    vector<int> prime;
    bool IsAble = true;

    // 에라토스테네스의 체를 이용해 2*10^6까지의 범위의 숫자 중 소수를 찾고 따로 저장
    for (int i = 2; i * i < BOUND; i++)
        if (!IsNotPrimary[i])
            for (int j = i * i; j < BOUND; j += i)
                IsNotPrimary[j] = true;

    for (long long i = 2; i < BOUND; i++)
        if (!IsNotPrimary[i])
            prime.push_back(i);

    // 테스트케이스 횟수 입력
    cin >> test;

    while (test--)
    {
        // 두 개의 수 입력
        cin >> input1 >> input2;

        sum = (long long)input1 + input2;

        // 판별
        // 합이 2 또는 3인 경우
        if (sum == 2 || sum == 3)
            cout << "NO" << '\n';
        // 합이 짝수인 경우
        else if (!(sum % 2))
            cout << "YES" << '\n';
        // 합이 홀수인 경우
        else if (sum % 2)
        {
            sum -= 2;
            IsAble = true;

            // (sum-2)가 저장된 소수로 나눠지는지 확인
            for (int i = 0; i < prime.size() && (long long)prime[i] * prime[i] <= sum; i++)
            {
                if (!(sum % prime[i]))
                {
                    cout << "NO" << '\n';
                    IsAble = false;
                    break;
                }
            }

            if (IsAble)
                cout << "YES" << '\n';
        }

    }

    return 0;
}