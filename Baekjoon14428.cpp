#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int idx, value;
    
    Node() : idx(0), value(0) {}
    Node(int idx, int value) : idx(idx), value(value) {}
    
    Node& operator<(Node& node)
    {
        if(this->value != node.value)
            return (this->value < node.value ? *this : node);
        else
            return (this->idx < node.idx ? *this : node);
    }
};

vector<Node> tree;

void Init(int start, int end, vector<int>& arr, int num)
{
    if(start == end)
    {
        tree[num].idx = start;
        tree[num].value = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    Init(start, mid, arr, num*2);
    Init(mid+1, end, arr, num*2+1);
    
    tree[num] = tree[num*2] < tree[num*2+1];
}

Node Query(int start, int end, int num, int left, int right)
{
    if(start == left && end == right)
        return tree[num];
    if(end < left || start > right)
        return Node(100001, 1000000001);
    
    int mid = (start + end) / 2;
    if(left <= mid && mid <= right)
    {
        Node leftQuery = Query(start, mid, num*2, left, mid);
        Node rightQuery = Query(mid+1, end, num*2+1, mid+1, right);
        return (leftQuery < rightQuery);
    }
    else if(right < mid)
        return Query(start, mid, num*2, left, right);
    else
        return Query(mid+1, end, num*2+1, left, right);
}

void Update(int start, int end, int num, int idx, int value)
{
    if(start == end)
    {
        if(start == idx)
            tree[num].value = value;
        
        return;
    }
    
    int mid = (start + end) / 2;
    if(idx <= mid)
        Update(start, mid, num*2, idx, value);
    else
        Update(mid+1, end, num*2+1, idx, value);
    
    tree[num] = tree[num*2] < tree[num*2+1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len, cnt;
    vector<int> arr;
    int command, tmp1, tmp2;
    
    cin >> len;
    
    arr.resize(len+1, 0);
    tree.resize(len*4+1);
    for(int i=1; i<=len; ++i)
        cin >> arr[i];
    Init(1, len, arr, 1);
    
    arr.clear();
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> command >> tmp1 >> tmp2;
        
        if(1 == command)
            Update(1, len, 1, tmp1, tmp2);
        else
            cout << Query(1, len, 1, tmp1, tmp2).idx << '\n';
    }
    
    return 0;
}
