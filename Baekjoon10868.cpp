#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> tree;
vector<int> arr;

void Init(int start, int end, int num)
{
    if(start == end)
    {
        tree[num] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    Init(start, mid, num*2);
    Init(mid+1, end, num*2+1);
    
    tree[num] = (tree[num*2] < tree[num*2+1] ? tree[num*2] : tree[num*2+1]);
}

int Query(int start, int end, int num, int left, int right)
{
    if(start == left && end == right)
        return tree[num];
    
    if(start > right || end < left)
        return 1000000001;
    
    int mid = (start + end) / 2;
    if(left <= mid && mid <= right)
    {
        int leftQuery = Query(start, mid, num*2, left, mid);
        int rightQuery = Query(mid+1, end, num*2+1, mid+1, right);
        return (leftQuery < rightQuery ? leftQuery : rightQuery);
    }
    else if(mid > right)
        return Query(start, mid, num*2, left, right);
    else
        return Query(mid+1, end, num*2+1, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, s, e;
    
    cin >> n >> m;
    arr.resize(n+1, 0);
    tree.resize(4 * (n+1), 0);
    
    for(int i=1; i<=n; ++i)
        cin >> arr[i];
    Init(1, n, 1);
    
    while(m--)
    {
        cin >> s >> e;
        cout << Query(1, n, 1, s, e) << '\n';
    }
    
    return 0;
}
