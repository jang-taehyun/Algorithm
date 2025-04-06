#include <iostream>
using namespace std;

int main()
{
    int idx;
    char input[1001] = {0, };
    
    cin >> input >> idx;
    cout << input[idx-1];
    
    return 0;
}
