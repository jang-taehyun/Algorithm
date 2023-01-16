/*
problem : 정수 E, S, M(1<=E<=15, 1<=S<=28, 1<=M<=19)이 나타내는 양수 n을 구해라.
input : 정수 E, S, M(1<=E<=15, 1<=S<=28, 1<=M<=19)
output : E, S, M이 나타내는 양수 n

idea : n을 하나씩 증가하면서, n%15, n%28, n%19이 E, S, M과 동일한지 판단
*/
#include <iostream>
using namespace std;

int ModulaResult(int n, int modula)
{
    int result = n % modula;
    if (!result)
        result = modula;

    return result;
}

int main()
{
    // E, S, M
    int E = 0, S = 0, M = 0;
    // modula 연산에 들어갈 피연산자 EModula, SModula, MModula
    const int EModula = 15, SModula = 28, MModula = 19;
    // modula 연산 결과 EResult, SResult, MResult
    int EResult = 0, SResult = 0, MResult = 0;
    // 양수 n
    int n = 0;

    // E, S, M 입력
    cin >> E >> S >> M;

    // unsigned int n을 하나씩 증가하면서 modula 연산 시, E, S, M과 같은지 확인
    while (true)
    {
        n++;

        EResult = ModulaResult(n, EModula);
        SResult = ModulaResult(n, SModula);
        MResult = ModulaResult(n, MModula);

        if ((EResult == E) && (SResult == S) && (MResult == M))
        {
            cout << n;
            break;
        }
    }

    return 0;
}