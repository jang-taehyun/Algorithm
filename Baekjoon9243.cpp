#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char input[1001] = {0, };
    char cmp[1001] = {0, };
    bool IsSuccess = true;
    
    cin >> n >> input >> cmp;
    
    for(int i=0; i<strlen(input); ++i)
    {
        if((n%2 && input[i] == cmp[i]) || (!(n%2) && input[i] != cmp[i]))
        {
            IsSuccess = false;
            break;
        }
    }
    
    cout << (IsSuccess ? "Deletion succeeded" : "Deletion failed");
    
    return 0;
}
