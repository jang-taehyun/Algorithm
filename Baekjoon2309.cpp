/*
problem : 9���� ������ �� 7���� ��� Ű�� ���� 100�� �Ǵ� ��츦 Ű�� ������������ ���
input : 9���� �������� Ű height
ouput : �� �� 7���� ��� Ű�� ���� 100�� �Ǵ� ��츦 ������������ ���

idea : ��� �������� Ű�� ��ģ ��, ������� 2�� �����Ͽ� ���ǿ� �´��� Ȯ��
*/
#define HUMAN_NUM 9
#define HUMAN_HEIGHT_SUM 100

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    // �������� Ű height
    int height[HUMAN_NUM];
    // ������ ������ exclude
    bool exclude[HUMAN_NUM];
    // �����̵��� Ű �� sum
    int sum = 0;

    // ������ ������ exclude �ʱ�ȭ & �������� Ű height �Է� �� ��� �������� Ű�� ���Ѵ�.
    memset(exclude, false, sizeof(exclude));
    for (int index = 0; index < HUMAN_NUM; index++)
    {
        cin >> height[index];
        sum += height[index];
    }

    // �����̸� Ű ������� ������������ ����
    sort(height, height + HUMAN_NUM);

    // 0��°, 1��° �����̺��� �����Ͽ� ���ǿ� �´��� Ȯ��
    for (int firstExclude = 0, secondExclude = firstExclude + 1; firstExclude < HUMAN_NUM, secondExclude < HUMAN_NUM; secondExclude++)
    {
        exclude[firstExclude] = true;
        exclude[secondExclude] = true;

        // ����(7���� �������� ���� 100)�� �����ϸ� �������� Ű ��� �� loop ����
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
�ѹ��� Ǯ�� ���� ����
1) sizeof �����ڿ� ���� ��Ȯ�ϰ� ���� ����
   sizeof �����ڴ� ������ �Ҵ�� �޸��� ũ��(byte)�� ��ȯ�Ѵ�!
   -> �� int arr[9]��� �迭�� ������ ��, 'sizeof(arr) / sizeof(int) == 9'
2) sort �Լ��� �߸� ���
   sort(�迭�� �ּ�, �迭�� �ּ�+�迭 �ȿ� �����ϴ� ����� ����)
3) memset �Լ��� �߸� ���
   memset(�迭�� �ּ�, �ʱ�ȭ�� ��, �迭�� �Ҵ�� �޸��� ũ��)
*/