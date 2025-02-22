#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char A[101];
  char B[101][101];
  int a=0, r, c, k=0;
  cin >> A;
  a = strlen(A);
  
  for(int i=1; i<=a; i++){
    for(int j=1; j<=a; j++){
      if(i*j==a){
        if(i>j) break;
        else{
          r = i;
          c = j;
        }
      }
    }
  }
  for(int i=0; i<c; i++){
    for(int j=0; j<r; j++){
      B[j][i] = A[k];
      k++;
    }
  }
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cout << B[i][j];
    }
  }
  return 0;
}
