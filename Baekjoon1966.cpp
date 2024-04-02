/*
problem : k���� ���ڰ� queue�� ���� ��, index�� n�� ���ڰ� queue���� �� ��°�� ������������ ���ض�.
input : k���� ����, ���ϰ��� �ϴ� ������ ��ġ n
output : index�� n�� ���ڰ� queue���� �� ��°�� ������������

idea
- �� �׽�Ʈ���̽����� queue�� �ʱ�ȭ�Ѵ�.
- queue�� front�� push �Ǵ� pop�Ͽ� index�� n�� ���ڰ� queue���� �� ��°�� ������������ ���Ѵ�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    queue<pair<int, bool>> q;            // k���� ���ڰ� �� queue
                                         // first : ����, bool : ã�����ϴ� ��ġ����
    vector<int> s;                       // ������ �ϴ� ã�����ϴ� �켱����
    int QueueSize, TargetIndex;          // queue�� ũ��, ã�����ϴ� ��ġ
    int test;                            // test Ƚ��
    int res = 0;                           // �����
    int idx = 0;                           // vector�� index

    int tmp1;
    bool tmp2;

    cin >> test;
    while (test--)
    {
        // input �Է�
        cin >> QueueSize >> TargetIndex;
        for (int i = 0; i < QueueSize; i++)
        {
            cin >> tmp1;

            if (i == TargetIndex)
                q.push(make_pair(tmp1, true));
            else
                q.push(make_pair(tmp1, false));

            s.push_back(tmp1);
        }

        // vector�� ������������ sort
        sort(s.begin(), s.end(), greater<int>());

        // ����
        while (!q.empty())
        {
            tmp1 = q.front().first;
            tmp2 = q.front().second;
            q.pop();

            // �������ϴ� �켱�������� Ȯ��
            if (s[idx] == tmp1)
            {
                res++;
                idx++;

                // ã���� �ϴ� ��ġ�� ã�Ҵٸ� �A Ƚ���� ��� �� loop ����
                if (tmp2)
                {
                    cout << res << '\n';
                    break;
                }
            }
            else
            {
                q.push(make_pair(tmp1, tmp2));
            }
        }

        // �ʱ�ȭ
        while (!q.empty())
            q.pop();
        s.clear();
        res = 0;
        idx = 0;
    }

    return 0;
}