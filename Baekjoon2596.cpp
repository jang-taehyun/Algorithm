#include <iostream>
using namespace std;

string input="";
string res="";
int len, tmp1;
char tmp2;
char board[8][7] = {"000000", "001111", "010011", "011100",
                    "100110", "101001", "110101", "111010"};

int IsFind()
{
    int idx=0;
    int diff=0;
    
    while(1)
    {
        if(idx > 7)
            return 0;
        
        for(int i=0; i<6; i++)
        {
            if(board[idx][i] != input[i])
                diff++;
        }
        
        if(diff < 2)
            return idx+1;
        
        idx++;
        diff=0;
    }
}

int main()
{
    cin >> len;
    
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<6; j++)
        {
            cin >> tmp2;
            input += tmp2;
        }
        
        tmp1 = IsFind();
        if(tmp1)
        {
            switch(tmp1)
            {
                case 1:
                    res += 'A';
                    break;
                case 2:
                    res += 'B';
                    break;
                case 3:
                    res += 'C';
                    break;
                case 4:
                    res += 'D';
                    break;
                case 5:
                    res += 'E';
                    break;
                case 6:
                    res += 'F';
                    break;
                case 7:
                    res += 'G';
                    break;
                case 8:
                    res += 'H';
                    break;
            }
        }
        else
        {
            res = to_string(i+1);
            break;
        }
        
        input.clear();
    }
    
    cout << res;
    
    return 0;
}
