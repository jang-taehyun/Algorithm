/*
Find Next Greatest Number problem
- �Էµ� array�� Monotonic stack�� ����� decreasing���� sort�� array�� ����� ������ �̿�
- Monotonic stack : element�� increasing �Ǵ� decreasing���� sort�Ǿ� �ִ� array

�����ڷ� : https://iridescentboy.tistory.com/146
*/
#include <iostream>
#include <stack>
using namespace std;

typedef unsigned int uint;

int main()
{
    uint len;
    uint SourceArray[500001];
    stack<uint> MonotonicStack;

    scanf("%u", &len);
    for (uint i = 0; i < len; i++)
    {
        scanf("%u", &SourceArray[i]);

        // Monotonic Stack�� �ִ� element �� ���� element���� ū element�� ã�� ������ pop
        while (!MonotonicStack.empty() && SourceArray[MonotonicStack.top()] < SourceArray[i])
            MonotonicStack.pop();

        // Monotonic Stack�� ����ִٸ� 0�� ���
        // Monotonic Stack�� ������� �ʴٸ�, top�� ���
        if (MonotonicStack.empty())
            printf("0 ");
        else
            printf("%d ", MonotonicStack.top() + 1);

        // Monotonic Stack�� ���� element�� index�� push
        MonotonicStack.push(i);
    }

    return 0;
}