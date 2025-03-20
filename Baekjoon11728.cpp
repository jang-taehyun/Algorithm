#include <iostream>
using namespace std;

int main()
{
    int alen, blen;
    int a[1000000];
    int b[1000000];
    int aIdx = 0, bIdx = 0, rIdx = 0;
    int output;
    
    cin >> alen >> blen;
    for(int i=0; i<alen; ++i)
        cin >> a[i];
    for(int i=0; i<blen; ++i)
        cin >> b[i];
    
    while(aIdx < alen || bIdx < blen)
    {
        // 두 개의 배열들을 모두 넣지 못한 경우
        if(aIdx < alen && bIdx < blen)
        {
            // a 배열의 요소가 더 작은 경우
            if(a[aIdx] < b[bIdx])
            {
                output = a[aIdx];
                ++aIdx;
            }
            // b 배열의 요소가 더 작거나 같은 경우
            else
            {
                output = b[bIdx];
                ++bIdx;
            }
        }
        // b 배열만 모두 넣은 경우
        else if(aIdx < alen)
        {
            output = a[aIdx];
            ++aIdx;
        }
        // a 배열만 모두 넣은 경우
        else
        {
            output = b[bIdx];
            ++bIdx;
        }
        
        // 결과 출력
        cout << output << ' ';
    }
    
    return 0;
}
