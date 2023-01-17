/*
problem : 100번에서 destination번 채널로 가기 위해 최소로 누르는 버튼의 횟수를 구해라. 이 때 고장난 버튼은 누룰 수 없다.
input : 목적지 채널 destination, 고장난 버튼의 수 brokenNum, 고장난 버튼 brokenButton
output : destination까지 가기 위해 최소로 누르는 버튼의 횟수

idea : 고장난 버튼에 따라 channel을 만들 수 있는지 확인 한 후, n보다 작은 채널에서 n까지 가는 방법 or n보다 큰 채널에서 n까지 가는 방법 or 100에서 시작해 n까지 가는 방법을 비교하여 그중 최소값을 출력
*/
#define MAX 999999999
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    // 목적지 destination
    int destination;
    // 전체 채널 channel
    bool channel[1000001];
    // 고장난 버튼의 수 brokenNum
    int brokenNum = 0;
    // 고장난 버튼 brokenButton
    char brokenButton[11];
    // 3가지 경우에서 나오는 값을 저장하는 resArray
    int resArray[3];
    // 최종 결과 res
    int res = 0;

    // 전체 채널 channel, 고장난 버튼 brokenButton, 3가지 경우에서 나오는 값 resArray 초기화
    fill_n(channel, sizeof(channel) / sizeof(bool), true);
    fill_n(brokenButton, sizeof(brokenButton) / sizeof(char), NULL);
    fill_n(resArray, sizeof(resArray) / sizeof(int), 0);

    // 목적지 destination과 고장난 버튼의 수 brokenNum, 고장난 버튼 brokenButton 입력
    cin >> destination >> brokenNum;
    for (int i = 0; i < brokenNum; i++)
        cin >> brokenButton[i];

    // 버튼을 누르는 최소 횟수 구하기
    if (destination != 100)
    {
        // 전체 채널을 숫자 버튼만을 이용해 만들 수 있는 지 확인
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

        // 목적지 destination로부터 버튼을 만들 수 있는 가장 가까운 채널 찾기
        // 1. 목적지 destination보다 작은 구간
        for (int loop = destination; loop > -1; loop--)
            if (channel[loop])
            {
                resultSmallerDestination = loop;
                break;
            }

        // 2. 목적지 destination보다 큰 구간
        for (int loop = destination; loop < destination + abs(destination - 100); loop++)
        {
            if (channel[loop])
            {
                resultBiggerDestination = loop;
                break;
            }
        }

        // 3가지 경우 중 최소값 구하기
        // 1. 목적지 destination보다 작은 구간에서 나오는 결과
        resArray[0] = abs(resultSmallerDestination - destination) + (to_string(resultSmallerDestination).length());
        // 2. 목적지 destination보다 큰 구간에서 나오는 결과
        resArray[1] = abs(resultBiggerDestination - destination) + (to_string(resultBiggerDestination).length());
        // 3. 100에서 +/-만을 이용해 목적지 destination으로 가는 방법
        resArray[2] = abs(destination - 100);

        res = resArray[0];
        for (int loop = 0; loop < 3; loop++)
            if (res > resArray[loop])
                res = resArray[loop];
    }

    // 결과 출력
    cout << res;

    return 0;
}