#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt=0, MinIdx = 0;
    
    while(k)
    {
        cnt = number.length();
        MinIdx = cnt - 1;
        for(int i=0; i<cnt-1; ++i)
        {
            if(number[i] < number[i+1])
            {
                number.erase(number.begin()+i);
                break;
            }
            
            if(number[i] < number[MinIdx])
                MinIdx = i;
        }
        
        if(cnt == number.length())
            number.erase(number.begin() + MinIdx);
        
        k--;
    }
    
    answer = number;
    return answer;
}
