#include <iostream>
#include <string>
using namespace std;

int main()
{
    string row, column;
    int cx, cy;
    bool IsFinish = false;
    char res[31][31] = {0, };
    
    cin >> row >> column;
    for(int i=0; i<row.length(); i++)
    {
        if(IsFinish)
            break;
        
        for(int j=0; j<column.length(); j++)
            if(row[i] == column[j])
            {
                cy = i;
                cx = j;
                IsFinish = true;
                break;
            }
    }
    
    for(int i=0; i<column.length(); i++)
        res[i][cy] = column[i];
    for(int i=0; i<row.length(); i++)
        res[cx][i] = row[i];
    
    for(int i=0; i<column.length(); i++)
    {
        for(int j=0; j<row.length(); j++)
        {
            if(res[i][j] == 0)
                cout << '.';
            else
                cout << res[i][j];
        }
            
        cout << '\n';
    }
    
    return 0;
}
