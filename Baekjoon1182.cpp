/*
problem : n개의 element를 가진 수열 array의 부분 집합 중 element의 합이 m이 되는 부분 집합의 개수를 구해라.
input : 수열 array, 합 m
output : 수열 array의 부분 집합 중 합이 m이 되는 부분 집합의 개수

idea
- 수열 array의 모든 부분 집합의 개수 : 2^n
  -> n개의 bit가 주어질 때, 각 bit의 상태는 수열 array의 element의 포함 여부와 같다.
     ex) 5개의 bit가 주어질 때 상태
         10진수로 1 == 00001 -> 1번째 요소만 포함
         10진수로 2 == 00010 -> 2번째 요소만 포함
         10진수로 3 == 00011 -> 1번째, 2번째 요소만 포함
         ...
         10진수로 31 == 11111 -> 1, 2, 3, 4, 5번째 요소 모두 포함
- 이를 이용해 가능한 모든 방법을 모두 탐색하여 합이 m이 되는 부분 집합의 개수를 구한다.
*/
#include <iostream>
using namespace std;

int main()
{
    int input[20];        // n개의 element를 가진 수열 input == array
    int length;           // 수열 array의 길이 length == n
    int summary;          // 부분 집합의 element의 합 summary == m
    int arrayCount=0;     // 합이 m이되는 부분 집합의 개수 arrayCount
    
    // input 입력
    cin >> length >> summary;
    for(int i=0; i<length; i++)
        cin >> input[i];
    
    // 1번째 경우부터 (2^n-1)번째 경우까지 모든 경우를 탐색해 합이 m이 되는 부분 집합의 개수를 구한다.
    // 공집합은 포함하지 않으므로 1번째 경우부터 시작한다.
    for(int testcase=1; testcase < (1 << length); testcase++)
    {
        int sum=0;
        
        // 수열 array의 1번째 element부터 n번째 element까지 포함 여부를 확인한 후, 포함된다면 sum에 더해준다.
        for(int bitIndex=0; bitIndex<length; bitIndex++)
            if(testcase & (1 << bitIndex))
                sum += input[bitIndex];
        
        if(sum == summary)
            arrayCount++;
    }
    
    // 결과 출력
    cout << arrayCount;
    
    return 0;
}
