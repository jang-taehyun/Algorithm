#include <iostream>
using namespace std;

int main(){
    int cut, piece = 1, a = 1;
    cin>>cut;
    for(int i = 0; i < cut; i++){
        if(i%2 != 0){
            a += 1;
        }
        piece += a;
    }
    cout<<piece;
    return 0;
}