/*
Find Next Greatest Number problem
- 입력된 array을 Monotonic stack을 사용해 decreasing으로 sort된 array로 만드는 과정을 이용
- Monotonic stack : element가 increasing 또는 decreasing으로 sort되어 있는 array

참고자료 : https://iridescentboy.tistory.com/146
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

        // Monotonic Stack에 있는 element 중 현재 element보다 큰 element를 찾을 때까지 pop
        while (!MonotonicStack.empty() && SourceArray[MonotonicStack.top()] < SourceArray[i])
            MonotonicStack.pop();

        // Monotonic Stack이 비어있다면 0을 출력
        // Monotonic Stack이 비어있지 않다면, top을 출력
        if (MonotonicStack.empty())
            printf("0 ");
        else
            printf("%d ", MonotonicStack.top() + 1);

        // Monotonic Stack에 현재 element의 index를 push
        MonotonicStack.push(i);
    }

    return 0;
}