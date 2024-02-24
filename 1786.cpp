#include <iostream>
#include<string>
#include <map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map<string, string> mapString;
	string* s = new string[n + 1000];
	string* t = new string[n + 1000];
	//string* f = new string[n + 1000];
	//string* e = new string[n + 1000];
	int change = 0;
	for (int i = 0; i < n; i++)cin >> s[i];
	for (int i = 0; i < n; i++)cin >> t[i];
	for (int i = 0; i < n; i++) {
		if (mapString.find(s[i]) != mapString.end()) {
			if (mapString[s[i]] == t[i])continue;
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			mapString[s[i]]=t[i];
		}
		
	}
	cout << "Yes" << endl;
	delete[] s;
	delete[] t;

	return 0;

}
