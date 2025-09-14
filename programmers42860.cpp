#include <string>
#include <queue>
using namespace std;

int alpha[26] = { 0, };

struct Node
{
    string str;
    int idx;
    int cnt;
};

int BFS(string& name)
{
    string tmp;
    queue<Node> q;
    Node cur, next;
    int left=0, right=0;
    int cnt1=0, cnt2=0;
    int res = 0x7f;
    
    while(name.length() != tmp.length())
        tmp += "A";
    tmp[0] = name[0];
    
    cur.str = tmp;
    cur.idx = 0;
    cur.cnt = alpha[name[0] - 'A'];
    
    q.push(cur);
    
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if(name == cur.str)
        {
            res = (res > cur.cnt ? cur.cnt : res);
            continue;
        }
        
        for(int i=0; i<name.length(); ++i)
        {
            if(cur.str[i] != name[i])
            {
                left = (cur.idx + name.length() - 1) % name.length();
                right = (cur.idx + 1) % name.length();
                
                cnt1 = 1;
                cnt2 = 1;
                
                while(left != i)
                {
                    left = (left + name.length() - 1) % name.length();
                    cnt1++;
                }
                
                while(right != i)
                {
                    right = (right + 1) % name.length();
                    cnt2++;
                }
                
                tmp = cur.str;
                tmp[i] = name[i];
                
                next.str = tmp;
                next.idx = i;
                next.cnt = cur.cnt + (cnt1 < cnt2 ? cnt1 : cnt2) + alpha[name[i] - 'A'];
                
                q.push(next);
            }
        }
    }
        
    return res;
}

int solution(string name) {
    int answer = 0;
    int cnt = 1;
    
    for(int i=1; i<=13; ++i)
    {
        alpha[i] = cnt;
        alpha[26-i] = cnt;
        ++cnt;
    }
    
    answer = BFS(name);
    return answer;
}
