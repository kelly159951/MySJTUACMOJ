#include<iostream>
using namespace std;
inline int ctoii(char ch) {
	if (ch >= '0' && ch <= '9') return ch - '0' + 1;
	if (ch >= 'a' && ch <= 'z') return ch - 'a' + 11;
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 37;
	return 0;
}

int myhash(char* ch) {
	int h = 0;
	for (int i = 0; ch[i] != 0 && i < 2000; ++i) {
		h = (long long)(h * 353 + ctoii(ch[i])) % 999983;
	}
	return h;
}
int myhash1(char* ch) {
	int h = 0;
	for (int i = 0; ch[i] != 0 && i < 2000; ++i) {
		h = (long long)(h * 61 + ctoii(ch[i])) % 999979;
	}
	return h;
}

int main() {
	int n;
	cin >> n;
	int* an=new int[999983];
	int* bn = new int[999979];
	int hash1=0;
	int hash2 = 0;
	int un=0;
	char charPtr[2000];
	for (int i = 0; i < 999983; i++) {
		an[i] = 0;
	}
	for (int i = 0; i < 999979; i++) {
		bn[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> charPtr;
		hash1 = myhash(charPtr);
		hash2 = myhash1(charPtr);
		//cout << hash1 << endl;
		//cout << hash2 << endl;
		if (an[hash1] == 1 && bn[hash2] == 1) {
			continue;
		}
		else {
			an[hash1] = 1;
			bn[hash2] = 1;
			un++;
		}
	}

	cout << un << endl;
	delete[] an;
	delete[] bn;
}

