#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	double A,B,C;
	double I,J,K;
	cin >> A >> B >> C;
	cin >> I >> J >> K;
	
	double a = A/I;
	double b = B/J;
	double c = C/K;
	
	double min = a < b ? a : b;
	min = min < c ? min : c;
	
	cout<< fixed << setprecision(6) <<A-min*I <<' '<< B-min*J <<' '<< C-min*K;
	return 0;
}
