/*
problem : n���� ȸ�ǰ� �־��� ��, ȸ�Ǹ� �ִ�� �� �� �ִ� ��츦 ���ض�.
input : n���� ȸ��
output : ȸ�Ǹ� �ִ�� �� �� �ִ� ���

idea
- �Էµ� ���� ȸ�� ������ �ð��� ���� ������������ sort
- ù ��° ȸ���� ������ �ð��� �������� ���� ȸ���� ���� �ð��� ���غ��� ũ�ٸ�,
  ������ ���� ȸ���� ������ �ð����� update�ϰ� ���� ȸ�Ǹ� �����Ѵ�.(greedy)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> Schedule;            // ȸ�� schedule
    int ScheduleCnt;                            // ȸ�� schedule�� ����
    int Start, End;                             // ȸ���� ���� �ð�, ������ �ð�
    int res = 1;                                // �ִ�� �� �� �ִ� ȸ���� Ƚ��

    // ȸ�� schedule �Է�
    cin >> ScheduleCnt;
    for (int i = 0; i < ScheduleCnt; i++)
    {
        cin >> Start >> End;
        Schedule.push_back(make_pair(End, Start));
    }

    // ȸ�� schedule�� ������ �ð��� �������� ������������ ����
    sort(Schedule.begin(), Schedule.begin() + ScheduleCnt);

    // greedy
    End = Schedule[0].first;
    for (int i = 1; i < ScheduleCnt; i++)
    {
        if (Schedule[i].second >= End)
        {
            res++;
            End = Schedule[i].first;
        }
    }

    // ����� ���
    cout << res;

    return 0;
}