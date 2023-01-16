/*
problem : ���� E, S, M(1<=E<=15, 1<=S<=28, 1<=M<=19)�� ��Ÿ���� ��� n�� ���ض�.
input : ���� E, S, M(1<=E<=15, 1<=S<=28, 1<=M<=19)
output : E, S, M�� ��Ÿ���� ��� n

idea : n�� �ϳ��� �����ϸ鼭, n%15, n%28, n%19�� E, S, M�� �������� �Ǵ�
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
    // modula ���꿡 �� �ǿ����� EModula, SModula, MModula
    const int EModula = 15, SModula = 28, MModula = 19;
    // modula ���� ��� EResult, SResult, MResult
    int EResult = 0, SResult = 0, MResult = 0;
    // ��� n
    int n = 0;

    // E, S, M �Է�
    cin >> E >> S >> M;

    // unsigned int n�� �ϳ��� �����ϸ鼭 modula ���� ��, E, S, M�� ������ Ȯ��
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