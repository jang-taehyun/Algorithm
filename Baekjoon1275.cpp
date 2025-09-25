#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree;

void Init(int start, int end, int num, vector<long long>& arr);
long long Query(int start, int end, int num, int left, int right);
void Update(int start, int end, int num, int idx, long long value);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int len, turn;
    vector<long long> arr;
    int s, e, idx, tmp;
    long long v;
    
    cin >> len >> turn;
    
    arr.resize(len+1, 0);
    tree.resize(len*4+1, 0);
    
    for(int i=1; i<=len; ++i)
        cin >> arr[i];
    Init(1, len, 1, arr);
    arr.clear();
    
    while(turn--)
    {
        cin >> s >> e >> idx >> v;
        
        if(s > e)
        {
            tmp = s;
            s = e;
            e = tmp;
        }
        
        cout << Query(1, len, 1, s, e) << '\n';
        Update(1, len, 1, idx, v);
    }
    
    return 0;
}

void Init(int start, int end, int num, vector<long long>& arr)
{
    if(start == end)
    {
        tree[num] = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    Init(start, mid, num*2, arr);
    Init(mid+1, end, num*2+1, arr);
    
    tree[num] = tree[num*2] + tree[num*2+1];
}

long long Query(int start, int end, int num, int left, int right)
{
    if(start == left && end == right)
        return tree[num];
    
    if(right < start || left > end)
        return 0;
    
    int mid = (start+end)/2;
    long long leftQuery, rightQuery;
    if(left <= mid && mid <= right)
    {
        leftQuery = Query(start, mid, num*2, left, mid);
        rightQuery = Query(mid+1, end, num*2+1, mid+1, right);
        return leftQuery + rightQuery;
    }
    else if(right < mid)
        return Query(start, mid, num*2, left, right);
    else
        return Query(mid+1, end, num*2+1, left, right);
}

void Update(int start, int end, int num, int idx, long long value)
{
    if(start == end)
    {
        if(start == idx)
            tree[num] = value;
        return;
    }
    
    int mid = (start+end)/2;
    if(mid >= idx)
        Update(start, mid, num*2, idx, value);
    else
        Update(mid+1, end, num*2+1, idx, value);
    
    tree[num] = tree[num*2] + tree[num*2+1];
}
