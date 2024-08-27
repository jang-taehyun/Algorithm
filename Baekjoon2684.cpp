#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string input;
    string tmp;
    int len;
    int res[8];
    
    cin >> len;
    while(len--)
    {
        cin >> input;
        
        memset(res, 0, sizeof(res));
        
        for(int i=0; i<input.length()-2; i++)
        {
            tmp = "";
            for(int j=0; j<3; j++)
                tmp += input[i+j];
            
            if("TTT" == tmp)
                res[0]++;
            else if("TTH" == tmp)
                res[1]++;
            else if("THT" == tmp)
                res[2]++;
            else if("THH" == tmp)
                res[3]++;
            else if("HTT" == tmp)
                res[4]++;
            else if("HTH" == tmp)
                res[5]++;
            else if("HHT" == tmp)
                res[6]++;
            else if("HHH" == tmp)
                res[7]++;
        }
        
        for(int i=0; i<8; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}
