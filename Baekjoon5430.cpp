/*
problem : ������(R)�� ����(D) ������ �̿��� �Է����� �־��� �迭�� ���� �� ��� ��ȭ�Ǵ��� ����ض�.
input : �迭 S, �����
output : ���� ���� �迭�� ���

idea
- deque�� �̿��� input�� �Է¹޴´�.
- ������ ������ ������ ���� ���� ������ �ݴ� �������� �����Ѵ�.
- ���� ���� ������ �� ��, deque�� ����ִٸ� error�� ���
*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    int test;                // �׽�Ʈ�� Ƚ��
    bool dir = true;           // ���� ����
                             // 0 : front, 1 : back
    bool IsError = false;      // error �߻� ����
    int ArrayLength;         // �迭�� ����
    deque<int> s;            // �迭 s

    string Operators;        // �Էµ� �����
    string input;            // �Էµ� �迭
    string tmp = "";

    cin >> test;
    while (test--)
    {
        // �ʱ�ȭ
        s.clear();
        dir = true;
        IsError = false;

        // ����, �迭 �Է�
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

        // ����
        for (int i = 0; i < Operators.length(); i++)
        {
            // ����(D) ����
            if (Operators[i] == 'D')
            {
                // deque�� ����ִٸ� error ���
                if (s.empty())
                {
                    IsError = true;
                    break;
                }
                // �� element�� �ִٸ� direction�� ���� ����
                else
                {
                    if (dir)
                        s.pop_front();
                    else
                        s.pop_back();

                    ArrayLength--;
                }
            }
            // ������(R) ����
            else if (Operators[i] == 'R')
            {
                dir = !dir;
            }
        }

        // ��� ���
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