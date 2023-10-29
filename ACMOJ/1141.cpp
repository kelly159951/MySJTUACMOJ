#include<iostream>
using namespace std;
int mo1 = 999971;
int mo2 = 999931;
inline int ctoii(char ch) {
	if (ch >= '0' && ch <= '9') return ch - '0' + 1;
	if (ch >= 'a' && ch <= 'z') return ch - 'a' + 11;
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 37;
	return 0;
}
int haxi1(char* str) {
	int ha=0;
	for (int i = 0; str[i] != 0; i++) {
		ha = (ha * 317 + ctoii(str[i])) % mo1;
	}
	return ha;
}
int haxi2(char* str) {
	int ha=0;
	for (int i = 0; str[i] != 0; i++) {
		ha = (ha * 577 + ctoii(str[i])) % mo2;
	}
	return ha;
}

int main() {
	int n;
	cin >> n;
	char* str = new char[1501];
	bool yuan1[1000000];
	bool yuan2[1000000];
	for (int i = 0; i < 100000; i++) {
		yuan1[i] = 0;
		yuan2[i] = 0;
	}
	int an = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int t1 = haxi1(str);
		int t2 = haxi2(str);
		if (!(yuan1[t1] && yuan2[t2])){
			an++;
			yuan1[t1]= 1;
			yuan2[t2] = 1;
		}
	}
	cout << an << endl;
	delete[] str;
}