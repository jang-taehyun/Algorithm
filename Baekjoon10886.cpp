#include <iostream>
using namespace std;

int main()
{
    int cnt;
    int disagree=0, agree=0;
    int input;
    
    cin >> cnt;
    while(cnt--)
    {
        cin >> input;
        (input ? ++agree : ++disagree);
    }
    
    cout << (agree > disagree ? "Junhee is cute!" : "Junhee is not cute!");
    
    return 0;
}
