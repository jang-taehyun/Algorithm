/*
problem : 정수 n을 1, 2, 3의 합으로 나타내는 방법을 구해라
input : 정수 n
output : 정수 n을 1, 2, 3의 합으로 나타내는 방법

idea(brute force)
- n을 1, 2, 3의 합으로 나타내는 방법의 수를 root로 설정하고, 3개의 child node를 갖는 tree로 만든다.
- child node는 (n-1), (n-2), (n-3)을 1, 2, 3의 합으로 나타내는 방법의 수를 뜻한다.
  - parent node는 child node에 저장된 숫자들의 합이다.
- DFS 방식으로 n >= 0일때까지 탐색한다.
- tree의 구조
                         (n)
      (n-1)             (n-2)             (n-3)
(n-2) (n-3) (n-4) (n-3) (n-4) (n-5) (n-4) (n-5) (n-6)
*/
#include <iostream>
using namespace std;

int DFS(int n)
{
    // n=0이라면 1을 반환하고 traversal 중단
    // n=0일 때 1, 2, 3 아무것도 안 쓰고 표현 가능하기 때문에 1이다.
    if(n == 0)
        return 1;
    
    int node=0;
    
    // child node 방문
    if(n-1 >= 0)
        node += DFS(n-1);
    if(n-2 >= 0)
        node += DFS(n-2);
    if(n-3 >= 0)
        node += DFS(n-3);
    
    // node에 저장된 방법의 수 return
    return node;
}

int main()
{
    // test할 횟수 testcase
    int testcase=0;
    // input
    int n=0;
    
    // test할 횟수 testcase 입력
    cin >> testcase;
    
    while(testcase--)
    {
        // n 입력
        cin >> n;
    
        // 결과값 출력
        cout << DFS(n) << endl;
    }
    
    return 0;
}
