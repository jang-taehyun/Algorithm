/*
problem : n*n board���� 2�� ä���� ĭ�� a�� �ְ�, 1�� ä���� ĭ�� b���� �ִ�.
          ĭ ������ �Ÿ��� (|x1-x2| + |y1-y2|)�� ����� ��,
          2�� ä���� ĭ a�� ĭ �� m���� ��� (|x1-x2| + |y1-y2|)�� ���� �ּҰ��� ���ض�.
input : n*n board, ���� ���� m
output : 2�� ä���� ĭ a�� ĭ �� m���� ��� (|x1-x2| + |y1-y2|)�� ���� �ּҰ�

idea
- 2�� ä���� ĭ�� vector�� �ִ´�.
- DFS ����� ���� 2�� ä���� ĭ �� m���� ����, (|x1-x2| + |y1-y2|)�� ���� ���Ѵ�.
- ������� ������ �հ� ���� ������ ���� ���� update
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int BoardLength;                  // board�� �� ���� ����
int Board[50][50];                // board
int ChooseCount;                  // �� ����
vector<pair<int, int>> Two;       // 2�� ä���� ĭ���� ����
vector<pair<int, int>> One;       // 1�� ä���� ĭ���� ����
bool visited_Two[14];             // 2�� ä���� ĭ�� �� �湮 ����
int res = 99999999;               // �����

void DFS(int cnt, int start)
{
    // m���� ��� ����ٸ�, (|x1-x2| + |y1-y2|)�� ���� ���Ѵ�.
    if (cnt >= ChooseCount)
    {
        int ComputeSum = 0;
        int tmp1, tmp2;
        int cx, cy;

        for (int i = 0; i < One.size(); i++)
        {
            tmp1 = 99999999;
            for (int j = 0; j < Two.size(); j++)
            {
                // ���� �ʴ� ĭ�� ���꿡�� ����
                if (!visited_Two[j])
                    continue;

                // 1�� ĭ�� �������� �� 2�� ĭ�� �� (|x1-x2| + |y1-y2|)�� ���� ���� ���� ����
                tmp2 = abs(One[i].first - Two[j].first) + abs(One[i].second - Two[j].second);
                tmp1 = min(tmp1, tmp2);
            }

            // �ּҰ��� ����ٸ�, �����ؼ� ���Ѵ�.
            ComputeSum += tmp1;
        }

        // ������ ���� ���� ���� ���� ���� ���� update
        res = min(res, ComputeSum);

        return;
    }

    // m���� ��ġ�� ����.
    for (int i = start; i < Two.size(); i++)
    {
        if (visited_Two[i])
            continue;

        visited_Two[i] = true;
        DFS(cnt + 1, i + 1);
        visited_Two[i] = false;
    }
}

int main()
{
    // n*n board, �� ���� �Է�
    cin >> BoardLength >> ChooseCount;
    for (int i = 0; i < BoardLength; i++)
    {
        for (int j = 0; j < BoardLength; j++)
        {
            cin >> Board[i][j];

            if (Board[i][j] == 1)
                One.push_back(make_pair(i, j));
            else if (Board[i][j] == 2)
                Two.push_back(make_pair(i, j));
        }
    }

    // 2�� ĭ�� �� m���� ��� (|x1-x2| + |y1-y2|)�� ���� �ּҰ��� ���Ѵ�.
    DFS(0, 0);

    // ����� ���
    cout << res;

    return 0;
}