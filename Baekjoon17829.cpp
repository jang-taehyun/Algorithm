#include <iostream>
using namespace std;

int arr[1024][1024] = { 0, };

int DivideQuad(int y, int x, int len)
{
    int num[4] = { 0, };
    int tmp;
    
    if(len > 2)
    {
        num[0] = DivideQuad(y, x, len/2);
        num[1] = DivideQuad(y, x+len/2, len/2);
        num[2] = DivideQuad(y+len/2, x, len/2);
        num[3] = DivideQuad(y+len/2, x+len/2, len/2);
    }
    else
    {
        num[0] = arr[y][x];
        num[1] = arr[y][x+1];
        num[2] = arr[y+1][x];
        num[3] = arr[y+1][x+1];
    }
    
    for(int i=0; i<4; ++i)
        for(int j=i+1; j<4; ++j)
            if(num[i] < num[j])
            {
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
    
    return num[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int len;
    int res=0;
    
    cin >> len;
    for(int i=0; i<len; ++i)
        for(int j=0; j<len; ++j)
            cin >> arr[i][j];
    
    res = DivideQuad(0, 0, len);
    cout << res;
    
    return 0;
}
