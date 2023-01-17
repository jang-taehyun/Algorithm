/*
problem : 100������ destination�� ä�η� ���� ���� �ּҷ� ������ ��ư�� Ƚ���� ���ض�. �� �� ���峭 ��ư�� ���� �� ����.
input : ������ ä�� destination, ���峭 ��ư�� �� brokenNum, ���峭 ��ư brokenButton
output : destination���� ���� ���� �ּҷ� ������ ��ư�� Ƚ��

idea : ���峭 ��ư�� ���� channel�� ���� �� �ִ��� Ȯ�� �� ��, n���� ���� ä�ο��� n���� ���� ��� or n���� ū ä�ο��� n���� ���� ��� or 100���� ������ n���� ���� ����� ���Ͽ� ���� �ּҰ��� ���
*/
#define MAX 999999999
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    // ������ destination
    int destination;
    // ��ü ä�� channel
    bool channel[1000001];
    // ���峭 ��ư�� �� brokenNum
    int brokenNum = 0;
    // ���峭 ��ư brokenButton
    char brokenButton[11];
    // 3���� ��쿡�� ������ ���� �����ϴ� resArray
    int resArray[3];
    // ���� ��� res
    int res = 0;

    // ��ü ä�� channel, ���峭 ��ư brokenButton, 3���� ��쿡�� ������ �� resArray �ʱ�ȭ
    fill_n(channel, sizeof(channel) / sizeof(bool), true);
    fill_n(brokenButton, sizeof(brokenButton) / sizeof(char), NULL);
    fill_n(resArray, sizeof(resArray) / sizeof(int), 0);

    // ������ destination�� ���峭 ��ư�� �� brokenNum, ���峭 ��ư brokenButton �Է�
    cin >> destination >> brokenNum;
    for (int i = 0; i < brokenNum; i++)
        cin >> brokenButton[i];

    // ��ư�� ������ �ּ� Ƚ�� ���ϱ�
    if (destination != 100)
    {
        // ��ü ä���� ���� ��ư���� �̿��� ���� �� �ִ� �� Ȯ��
        for (int loop1 = 0; loop1 < 1000001; loop1++)
        {
            string currentChannel = to_string(loop1);
            for (int loop2 = 0; loop2 < brokenNum; loop2++)
            {
                if (currentChannel.find(brokenButton[loop2]) != string::npos)
                {
                    channel[loop1] = false;
                    break;
                }
            }
        }

        int resultSmallerDestination = MAX;
        int resultBiggerDestination = MAX;

        // ������ destination�κ��� ��ư�� ���� �� �ִ� ���� ����� ä�� ã��
        // 1. ������ destination���� ���� ����
        for (int loop = destination; loop > -1; loop--)
            if (channel[loop])
            {
                resultSmallerDestination = loop;
                break;
            }

        // 2. ������ destination���� ū ����
        for (int loop = destination; loop < destination + abs(destination - 100); loop++)
        {
            if (channel[loop])
            {
                resultBiggerDestination = loop;
                break;
            }
        }

        // 3���� ��� �� �ּҰ� ���ϱ�
        // 1. ������ destination���� ���� �������� ������ ���
        resArray[0] = abs(resultSmallerDestination - destination) + (to_string(resultSmallerDestination).length());
        // 2. ������ destination���� ū �������� ������ ���
        resArray[1] = abs(resultBiggerDestination - destination) + (to_string(resultBiggerDestination).length());
        // 3. 100���� +/-���� �̿��� ������ destination���� ���� ���
        resArray[2] = abs(destination - 100);

        res = resArray[0];
        for (int loop = 0; loop < 3; loop++)
            if (res > resArray[loop])
                res = resArray[loop];
    }

    // ��� ���
    cout << res;

    return 0;
}