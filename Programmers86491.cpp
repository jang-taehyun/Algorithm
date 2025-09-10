// https://school.programmers.co.kr/learn/courses/30/lessons/86491

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w=0, h=0, tmp;
    int cnt = sizes.size();
    
    for(int i=0; i<cnt; ++i)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    
    w=sizes[0][0], h=sizes[0][1];
    for(int i=1; i<cnt; ++i)
    {
        w = (sizes[i][0] > w ? sizes[i][0] : w);
        h = (sizes[i][1] > h ? sizes[i][1] : h);
    }
    
    answer = w * h;
    return answer;
}
