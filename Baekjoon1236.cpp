#include <iostream>
#include <string>
#include <cstring>
#define MAX(x, y) (x) > (y) ? (x) : (y)
using namespace std;

int main()
{
    bool NotEmptyColumn[50];
    bool NotEmptyRow[50];
    string inputs;
    int col, row;
    int comp1=0, comp2=0;
    
    memset(NotEmptyColumn, false, sizeof(NotEmptyColumn));
    memset(NotEmptyRow, false, sizeof(NotEmptyRow));
    
    cin >> col >> row;
    for(int i=0; i<col; i++)
    {
        cin >> inputs;
        for(int j=0; j<row; j++)
        {
            if(inputs[j] == 'X')
            {
                NotEmptyColumn[i] = true;
                NotEmptyRow[j] = true;
            }
        }
    }
    
    for(int i=0; i<col; i++)
        if(!NotEmptyColumn[i])
            comp1++;
    
    for(int i=0; i<row; i++)
        if(!NotEmptyRow[i])
            comp2++;

    cout << (MAX(comp1, comp2));
    
    return 0;
}
