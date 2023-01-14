/*
problem : 9명의 난쟁이 중 7명을 골라 키의 합이 100이 되는 경우를 키의 오름차순으로 출력
input : 9명의 난쟁이의 키 height
ouput : 이 중 7명을 골라 키의 합이 100이 되는 경우를 오름차순으로 출력

idea : 모든 난쟁이의 키를 합친 후, 순서대로 2명씩 제외하여 조건에 맞는지 확인
*/
#define HUMAN_NUM 9
#define HUMAN_HEIGHT_SUM 100

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    // 난쟁이의 키 height
    int height[HUMAN_NUM];
    // 제외할 난쟁이 exclude
    bool exclude[HUMAN_NUM];
    // 난쟁이들의 키 합 sum
    int sum = 0;

    // 제외할 난쟁이 exclude 초기화 & 난쟁이의 키 height 입력 및 모든 난쟁이의 키를 합한다.
    memset(exclude, false, sizeof(exclude));
    for (int index = 0; index < HUMAN_NUM; index++)
    {
        cin >> height[index];
        sum += height[index];
    }

    // 난쟁이를 키 순서대로 오름차순으로 정렬
    sort(height, height + HUMAN_NUM);

    // 0번째, 1번째 난쟁이부터 제외하여 조건에 맞는지 확인
    for (int firstExclude = 0, secondExclude = firstExclude + 1; firstExclude < HUMAN_NUM, secondExclude < HUMAN_NUM; secondExclude++)
    {
        exclude[firstExclude] = true;
        exclude[secondExclude] = true;

        // 조건(7명의 난쟁이의 합이 100)에 부합하면 난쟁이의 키 출력 후 loop 종료
        if (sum - height[firstExclude] - height[secondExclude] == HUMAN_HEIGHT_SUM)
        {
            for (int index = 0; index < HUMAN_NUM; index++)
                if (!exclude[index])
                    cout << height[index] << '\n';
            break;
        }

        exclude[firstExclude] = false;
        exclude[secondExclude] = false;

        if (secondExclude == HUMAN_NUM - 1)
        {
            firstExclude++;
            secondExclude = firstExclude;
        }
    }

    return 0;
}

/*
한번에 풀지 못한 이유
1) sizeof 연산자에 대해 정확하게 알지 못함
   sizeof 연산자는 변수에 할당된 메모리의 크기(byte)를 반환한다!
   -> 즉 int arr[9]라는 배열이 존재할 때, 'sizeof(arr) / sizeof(int) == 9'
2) sort 함수를 잘못 사용
   sort(배열의 주소, 배열의 주소+배열 안에 존재하는 요소의 개수)
3) memset 함수를 잘못 사용
   memset(배열의 주소, 초기화할 값, 배열에 할당된 메모리의 크기)
*/