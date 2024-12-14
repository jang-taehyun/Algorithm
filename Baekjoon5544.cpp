#include <iostream>
using namespace std;

int main()
{
    int team;
    int score[101] = {0, };
    int res[101] = {0, };
    int loop;
    int t1, t2, i1, i2;
    
    cin >> team;
    loop = (team * (team - 1))/2;
    
    for(int i=0; i<loop; i++)
    {
        cin >> t1 >> t2 >> i1 >> i2;
        
        if(i1 > i2)
        {
            score[t1] += 3;
        }
        else if(i1 < i2)
        {
            score[t2] += 3;
        }
        else
        {
            score[t1]++;
            score[t2]++;
        }
    }
    
    for(int i=1; i<=team; i++)
    {
        for(int j=1; j<=team; j++)
        {
            if(i == j)
                continue;
            
            if(score[i] < score[j])
                res[i]++;
        }
    }
    
    for(int i=1; i<=team; i++)
        cout << (res[i] + 1) << '\n';
    
    return 0;
}
