#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* line = new int[n+100];
	int* check = new int[n+100];
	int m = 0;
	int t1 = 0, t2 = 0;
	vector<vector<int>> circle;
	int numcir = 0;
	for (int i = 1; i < n + 1; i++) {
		cin >> line[i];
		check[i] = 0;
	}
	//找出所有的环并存入vector中
	for (int i = 1; i < n+1; i++) {
		if (check[i] == 0 && line[i] != i) {
			check[i] = 1;
			int tmp = line[i];
			circle.push_back({ i });
			//cout << tmp;
			numcir++;
			while (tmp != i) {
				circle[numcir - 1].push_back(tmp);
				check[tmp] = 1;
				tmp = line[tmp];
				//cout << tmp;
			}
		}
		else check[i] = 1;
	}


	//判断输出次数
	vector<int> next;
	if (numcir > 0)m = 1;
	for (int i = 0; i < numcir; i++) {
		if (circle[i].size() > 2) {
			m = 2;
			next.push_back(i);
			t1 += circle[i].size() / 2;
			t2 += (circle[i].size()-1) / 2;
		}
		else t1++;
	}
	cout << m << endl;

	if (m > 0) {
		cout << t1;
		for (int i = 0; i < circle.size(); i++) {
			for (int j = 0; j < circle[i].size() / 2; j++) {
				cout << " " << circle[i][j] << " " << circle[i][circle[i].size() - j - 1];
			}
		}
		cout << endl;
	}
	if (m > 1) {
		cout << t2;
		for (int i = 0; i < next.size(); i++) {
			for (int j = 0; j < (circle[next[i]].size()-1) / 2; j++) {
				cout << " " << circle[next[i]][j+1] << " " << circle[next[i]][circle[i].size() - j  - 1];
			}
		}
		cout << endl;
	}
	delete[] line;
	delete[]check;
}

