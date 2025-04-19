#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _node_
{
    string name;
    int day;
    int month;
    int year;
} Node;

bool comp(Node ref1, Node ref2)
{
    if (ref1.year < ref2.year)
		return true;
	else if (ref1.year == ref2.year)
    {
		if (ref1.month < ref2.month)
			return true;
		else if (ref1.month == ref2.month)
        {
			if (ref1.day < ref2.day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main()
{
    int test;
    vector<Node> s;
    string name;
    int day, month, year;
    
    cin >> test;
    for(int i=0; i<test; ++i)
    {
        cin >> name >> day >> month >> year;
        s.push_back({name, day, month, year});
    }
    
    sort(s.begin(), s.end(), comp);
    
    cout << s[test-1].name << '\n' << s[0].name;
    
    return 0;
}
