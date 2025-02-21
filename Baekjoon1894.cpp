#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long double ld;

pair<ld, ld> p1, p2, p3, p4;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed;
	cout.precision(3);

	while (cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second) {
		if (p2 == p3) swap(p1, p2);
		else if (p1 == p4) swap(p3, p4);
		else if (p2 == p4) swap(p1, p2), swap(p3, p4);
		cout << p1.first + (p2.first - p1.first) + (p4.first - p1.first) << ' ' << p1.second + (p2.second - p1.second) + (p4.second - p1.second) << '\n';
	}
}