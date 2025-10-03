// https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int sum=0;
    int next=0;
};

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<Node> q;
    Node cur;
    
    q.push({numbers[0], 1});
    q.push({-numbers[0], 1});
    
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if(cur.next >= numbers.size())
        {
            if(cur.sum == target)
                ++answer;
            continue;
        }
        
        q.push({cur.sum + numbers[cur.next], cur.next+1});
        q.push({cur.sum - numbers[cur.next], cur.next+1});
    }
    
    return answer;
}
