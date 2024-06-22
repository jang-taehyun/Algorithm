#include <iostream>
using namespace std;

int main()
{
    int boxUsage=0;
    int bookSize=0;
    int boxCount, bookCount;
    int tmp;
    
    cin >> boxCount >> bookCount;
    for(int i=0; i<boxCount; i++)
    {
        cin >> tmp;
        boxUsage += tmp;
    }   
    for(int i=0; i<bookCount; i++)
    {
        cin >> tmp;
        bookSize += tmp;
    }
    
    cout << (boxUsage - bookSize);
    
    return 0;
}
