#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int res[31] = {0, };
    
    for(int i=0; i<lost.size(); ++i)
        res[lost[i]]--;
    for(int i=0; i<reserve.size(); ++i)
        res[reserve[i]]++;
    
    for(int i=1; i<=n; ++i)
        if(res[i] < 0)
        {
            if(i > 0 && res[i-1] > 0)
            {
                res[i-1]--;
                res[i]++;
            }
            else if(i < n && res[i+1] > 0)
            {
                res[i+1]--;
                res[i]++;
            }
        }
    
    for(int i=1; i<=n; ++i)
        if(res[i] < 0)
            answer--;
    
    
    return answer;
}
