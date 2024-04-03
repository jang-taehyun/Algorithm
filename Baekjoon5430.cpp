/*
problem : 뒤집기(R)와 빼기(D) 연산을 이용해 입력으로 주어진 배열이 연산 후 어떻게 변화되는지 출력해라.
input : 배열 S, 연산들
output : 연산 후의 배열의 모습

idea
- deque을 이용해 input을 입력받는다.
- 뒤집기 연산이 나오면 현재 빼는 방향을 반대 방향으로 세팅한다.
- 만약 빼기 연산을 할 때, deque이 비어있다면 error을 출력
*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    int test;                // 테스트할 횟수
    bool dir = true;           // 빼는 방향
                             // 0 : front, 1 : back
    bool IsError = false;      // error 발생 여부
    int ArrayLength;         // 배열의 길이
    deque<int> s;            // 배열 s

    string Operators;        // 입력된 연산들
    string input;            // 입력된 배열
    string tmp = "";

    cin >> test;
    while (test--)
    {
        // 초기화
        s.clear();
        dir = true;
        IsError = false;

        // 연산, 배열 입력
        cin >> Operators;
        cin >> ArrayLength;
        cin >> input;
        for (int i = 0; i < input.length(); i++)
        {
            tmp = "";
            if (input[i] >= '0' || input[i] <= '9')
            {
                while (i < input.length())
                {
                    if (input[i] >= '0' && input[i] <= '9')
                        tmp = tmp + input[i];
                    else
                        break;

                    i++;
                }
            }

            if (tmp.length())
                s.push_back(stoi(tmp));
        }

        // 연산
        for (int i = 0; i < Operators.length(); i++)
        {
            // 빼기(D) 연산
            if (Operators[i] == 'D')
            {
                // deque이 비어있다면 error 출력
                if (s.empty())
                {
                    IsError = true;
                    break;
                }
                // 뺄 element가 있다면 direction에 따라 제거
                else
                {
                    if (dir)
                        s.pop_front();
                    else
                        s.pop_back();

                    ArrayLength--;
                }
            }
            // 뒤집기(R) 연산
            else if (Operators[i] == 'R')
            {
                dir = !dir;
            }
        }

        // 결과 출력
        if (!IsError)
        {
            cout << '[';

            if (dir)
            {
                for (int i = 0; i < ArrayLength; i++)
                {
                    cout << s[i];

                    if (i != ArrayLength - 1)
                        cout << ',';
                }
            }
            else
            {
                for (int i = ArrayLength - 1; i >= 0; i--)
                {
                    cout << s[i];

                    if (i != 0)
                        cout << ',';
                }
            }

            cout << ']';
            cout << '\n';
        }
        else
            cout << "error" << '\n';
    }

    return 0;
}