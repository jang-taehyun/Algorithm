#include <iostream>
using namespace std;

int main()
{
    unsigned int people;
    unsigned int tshirt[6] = { 0, };
    unsigned int tshirt_divider=0, pen_divider=0;
    unsigned int tshirt_res=0;
    
    cin >> people;
    for(int i=0; i<6; ++i)
        cin >> tshirt[i];
    cin >> tshirt_divider >> pen_divider;
    
    for(int i=0; i<6; ++i)
    {
        tshirt_res += (tshirt[i] / tshirt_divider);
        
        if(tshirt[i] % tshirt_divider)
            tshirt_res++;
    }
    
    cout << tshirt_res << '\n';
    cout << (people / pen_divider) << ' ' << (people % pen_divider);
    
    return 0;
}
