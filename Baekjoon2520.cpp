#include <iostream>
#define MIN(x, y) (x) < (y) ? (x) : (y)
using namespace std;

int main()
{
    int test;
    int DoughIngredients[5] = {0, };
    int NeedDough[5] = {8, 8, 4, 1, 9};
    int Topping[4] = {0, };
    int NeedTopping[4] = {1, 30, 25, 10};
    int tmp;
    int kneading = 1e9;
    int cake = 0;
    
    cin >> test;
    while(test--)
    {
        for(int i=0; i<5; i++)
        {
            cin >> DoughIngredients[i];
            tmp = (DoughIngredients[i] * 16) / NeedDough[i];
            kneading = MIN(kneading, tmp);
        }
            
        for(int i=0; i<4; i++)
        {
            cin >> Topping[i];
            tmp = Topping[i] / NeedTopping[i];
            cake += tmp;
        }
        
        cout << (MIN(cake, kneading)) << '\n';
        
        kneading = 1e9;
        cake = 0;
    }
    
    
    return 0;
}
