/*
problem : binary tree를 preorder, inorder, postorder traversal한 결과를 모두 출력해라.
input : binary tree
output : preorder, inorder, postorder로 traversal한 결과

idea
- 2차원 array를 이용해 tree를 저장한다.
- traversal 시작
  1) preorder : root -> left -> right
  2) inorder : left -> root -> right
  3) postorder : left -> right -> root
- 만약 array에 저장된 값이 0보다 작으면 탐색 중단(.이기 때문)
*/
#include <iostream>
using namespace std;

int tree[26][2];            // binary tree

void Preorder(int idx)
{
    if(idx < 0)
        return;
    
    char node = idx+'A';
  
    cout << node;
    Preorder(tree[idx][0]);
    Preorder(tree[idx][1]);
}

void Inorder(int idx)
{
    if(idx < 0)
        return;
    
    char node = idx+'A';
  
    Inorder(tree[idx][0]);
    cout << node;
    Inorder(tree[idx][1]);
}

void Postorder(int idx)
{
    if(idx < 0)
        return;
    
    char node = idx+'A';
  
    Postorder(tree[idx][0]);
    Postorder(tree[idx][1]);
    cout << node;
}

int main()
{
    // input 입력
    int node;
    cin >> node;
    while(node--)
    {
        char root, left, right;
        cin >> root >> left >> right;

        tree[root-'A'][0] = left-'A';
        tree[root-'A'][1] = right-'A';
    }
    
    // preorder
    Preorder(0);
    cout << '\n';
    
    // inorder
    Inorder(0);
    cout << '\n';
    
    // postorder
    Postorder(0);
    cout << '\n';
    
    return 0;
}
