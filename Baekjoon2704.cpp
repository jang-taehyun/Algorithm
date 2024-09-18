#include <iostream>
#include <string>

using namespace std;

int T;

string s;

int main()
{
	cin >> T;

	while (T--) {

		cin >> s;

		int H = stoi(s.substr(0, 2)), M = stoi(s.substr(3, 2)), S = stoi(s.substr(6, 2));

		for (int k = 5; k > -1; k--) {

			if (H & (1 << k)) cout << 1;

			else cout << 0;

			if (M & (1 << k)) cout << 1;

			else cout << 0;

			if (S & (1 << k)) cout << 1;

			else cout << 0;

		}

		cout << ' ';

		for (int k = 5; k > -1; k--) {

			if (H & (1 << k)) cout << 1;

			else cout << 0;

		}

		for (int k = 5; k > -1; k--) {

			if (M & (1 << k)) cout << 1;

			else cout << 0;

		}

		for (int k = 5; k > -1; k--) {

			if (S & (1 << k)) cout << 1;

			else cout << 0;

		}

		cout << '\n';

	}

}