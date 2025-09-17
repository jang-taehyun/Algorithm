#include <iostream>
using namespace std;

long long segtree[4000001] = { 0, };
long long arr[1000001] = { 0, };
long long len;

void Init(long long start, long long end, long long num)
{
    if (start == end)
    {
        segtree[num] = arr[start];
        return;
    }

    Init(start, (start + end) / 2, num * 2);
    Init((start + end) / 2 + 1, end, num * 2 + 1);

    segtree[num] = segtree[num * 2] + segtree[num * 2 + 1];
}

void Update(long long start, long long end, long long num, long long idx, long long value)
{
    if (start > idx || end < idx)
        return;

    if (start == end)
    {
        if (start == idx)
            segtree[num] = value;
        return;
    }

    Update(start, (start + end) / 2, num * 2, idx, value);
    Update((start + end) / 2 + 1, end, num * 2 + 1, idx, value);

    segtree[num] = segtree[num * 2] + segtree[num * 2 + 1];
}

long long Query(long long start, long long end, long long num, long long left, long long right)
{
    if (right < start || left > end)
        return 0;
    if (start == left && end == right)
        return segtree[num];

    long long mid = (start + end) / 2;
    if (left <= mid && mid <= right)
    {
        long long leftQuery, rightQuery;
        leftQuery = Query(start, mid, num * 2, left, mid);
        rightQuery = Query(mid + 1, end, num * 2 + 1, mid+1, right);
        return leftQuery + rightQuery;
    }
    else if (right < mid)
        return Query(start, mid, num * 2, left, right);
    else
        return Query(mid + 1, end, num * 2 + 1, left, right);
}

int main()
{
    long long tmp1, tmp2, tmp3, tmp4;

    cin >> len >> tmp1 >> tmp2;
    for (int i = 1; i <= len; ++i)
        cin >> arr[i];

    Init(1, len, 1);

    tmp3 = tmp1 + tmp2;
    while (tmp3--)
    {
        cin >> tmp1 >> tmp2 >> tmp4;

        if (tmp1 == 1)
            Update(1, len, 1, tmp2, tmp4);
        else
            cout << Query(1, len, 1, tmp2, tmp4) << '\n';
    }

    return 0;
}
