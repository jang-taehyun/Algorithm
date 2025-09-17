#include <iostream>
using namespace std;

typedef unsigned long long ULL;

ULL arr[100001] = {0, };
ULL maxTree[400001] = {0, };
ULL minTree[400001] = {0, };

void InitMinTree(ULL start, ULL end, ULL num)
{
    if(start == end)
    {
        minTree[num] = arr[start];
        return;
    }
    
    ULL mid = (start + end) / 2;
    InitMinTree(start, mid, num*2);
    InitMinTree(mid+1, end, num*2+1);
    
    minTree[num] = (minTree[num*2] < minTree[num*2+1] ? minTree[num*2] : minTree[num*2+1]);
}

void InitMaxTree(ULL start, ULL end, ULL num)
{
    if(start == end)
    {
        maxTree[num] = arr[start];
        return;
    }
    
    ULL mid = (start + end) / 2;
    InitMaxTree(start, mid, num*2);
    InitMaxTree(mid+1, end, num*2+1);
    
    maxTree[num] = (maxTree[num*2] > maxTree[num*2+1] ? maxTree[num*2] : maxTree[num*2+1]);
}

ULL MaxQuery(ULL start, ULL end, ULL num, ULL left, ULL right)
{
    if(right < start || end < left)
        return 0;
    if(start == left && end == right)
        return maxTree[num];
    
    ULL mid = (start + end) / 2;
    if(left <= mid && mid <= right)
    {
        ULL leftNode, rightNode;
        leftNode = MaxQuery(start, mid, num*2, left, mid);
        rightNode = MaxQuery(mid+1, end, num*2+1, mid+1, right);
        return (leftNode > rightNode ? leftNode : rightNode);
    }
    else if(right < mid)
        return MaxQuery(start, mid, num*2, left, right);
    else
        return MaxQuery(mid+1, end, num*2+1, left, right);
}

ULL MinQuery(ULL start, ULL end, ULL num, ULL left, ULL right)
{
    if(right < start || end < left)
        return 1000000001;
    if(start == left && end == right)
        return minTree[num];
    
    ULL mid = (start + end) / 2;
    if(left <= mid && mid <= right)
    {
        ULL leftNode, rightNode;
        leftNode = MinQuery(start, mid, num*2, left, mid);
        rightNode = MinQuery(mid+1, end, num*2+1, mid+1, right);
        return (leftNode < rightNode ? leftNode : rightNode);
    }
    else if(right < mid)
        return MinQuery(start, mid, num*2, left, right);
    else
        return MinQuery(mid+1, end, num*2+1, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ULL len, cnt, s, e;
    
    cin >> len >> cnt;
    for(int i=1; i<=len; ++i)
        cin >> arr[i];
    InitMinTree(1, len, 1);
    InitMaxTree(1, len, 1);
    
    while(cnt--)
    {
        cin >> s >> e;
        cout << MinQuery(1, len, 1, s, e) << ' ' << MaxQuery(1, len, 1, s, e) << '\n';
    }
    
    return 0;
}
