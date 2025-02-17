#include <iostream>
#include <deque>

using namespace std;

typedef struct _s_
{
    long long n;
    int idx;
} Node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	deque<Node> s;
    long long tmp;
    int len, clen, idx=0;
    
    cin >> len >> clen;
    for(int i=0; i<len; i++)
    {
        cin >> tmp;
        
        while(!s.empty() && s.back().n >= tmp)
            s.pop_back();
        s.push_back({tmp, i});
        while(!s.empty() && (i - clen + 1) >= 0 && s.front().idx < (i - clen + 1))
            s.pop_front();
        
        cout << s.front().n << ' ';
    }
    
	return 0;
}
