#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> dic(n);
	int t;
	for (int i = 0; i < n-1; i++) {
		cin >> t;
		dic[t].push_back(i + 1);
	}
	int flag = 1;

	vector<int> temp1 = {0};
	vector<int> temp2 = {};
	while (flag < n) {
		for (int i = 0; i < temp1.size(); i++) {
			if (dic[temp1[i]].size() < 2) {
				if (n - flag > int(dic[temp1[i]].size())) {
					cout << "false" << endl;
					return 0;
				}
				else {
					cout << "true" << endl;
					return 0;
				}
			}
			temp2.push_back(dic[temp1[i]][0]);
			temp2.push_back(dic[temp1[i]][1]);
			flag += 2;
		}
		temp1 = temp2;
		temp2 = {};
	}
	cout << "true" << endl;
	return 0;
}