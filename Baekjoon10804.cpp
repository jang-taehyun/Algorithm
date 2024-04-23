#include <iostream>
using namespace std;

int main()
{
    int arr[20];
    int start, end, tmp;

    for (int i = 0; i < 20; i++)
        arr[i] = i + 1;

    for (int i = 0; i < 10; i++)
    {
        cin >> start >> end;
        start--;
        end--;

        for (int j = 0; j <= (end - start) / 2; j++)
        {
            tmp = arr[start + j];
            arr[start + j] = arr[end - j];
            arr[end - j] = tmp;
        }
    }

    for (int i = 0; i < 20; i++)
        cout << arr[i] << ' ';

    return 0;
}