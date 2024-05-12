#include <iostream>
#include <list>
using namespace std;

list<int> q;
int res = 0;
int target;

void MoveRight()
{
    while (q.front() != target)
    {
        q.push_front(q.back());
        q.pop_back();
        res++;
    }
}

void MoveLeft()
{
    while (q.front() != target)
    {
        q.push_back(q.front());
        q.pop_front();
        res++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list<int>::iterator iter;
    int len, count;
    int idx = 0;

    cin >> len >> count;
    for (int i = 1; i <= len; i++)
        q.push_back(i);

    while (count--)
    {
        cin >> target;

        for (iter = q.begin(); iter != q.end(); iter++)
        {
            if (target == *iter)
                break;
            idx++;
        }

        if (q.size() % 2)
        {
            if (q.size() / 2 >= idx)
                MoveLeft();
            else
                MoveRight();
        }
        else
        {
            if (q.size() / 2 > idx)
                MoveLeft();
            else
                MoveRight();
        }

        q.pop_front();
        idx = 0;
    }

    cout << res;

    return 0;
}