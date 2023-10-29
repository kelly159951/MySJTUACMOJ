#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int act;//输入操作
	int step = 0;//记录总数据末尾位置
	int* stack = new int[n];//记录总数据
	char temp;//输入字符
	int* check = new int[n];//存储匹配剩余项
	int index=0;//存储check末尾位置
	int te=0;
	for (int _ = 0; _ < n; _++) {
		cin >> act;
		switch (act) {
		case 1:
			cin >> temp;
			if (temp == '{')te = 1;
			else if (temp == '[')te = 2;
			else if (temp == '(')te = 3;
			else if (temp == '}')te = 4;
			else if (temp == ']')te = 5;
			else if (temp == ')')te = 6;

			stack[step] = te;
			step++;
			if (index > 0 && te-check[index - 1] == 3)index--;
			else {
				check[index] = te;
				index++;
			}
			break;
		case 2:
			if (step > 0) {
				step--;
			}

			index = 0;
			for (int i = 0; i < step; i++) {
				if (index > 0 && stack[i] - check[index - 1] == 3)index--;
				else {
					check[index] = stack[i];
					index++;
				}
			}
			break;

		case 3:
			if (step == 0)break;
			else if (stack[step - 1] == 1) cout << '{' << endl;
			else if (stack[step - 1] == 2) cout << '[' << endl;
			else if (stack[step - 1] == 3) cout << '(' << endl;
			else if (stack[step - 1] == 4) cout << '}' << endl;
			else if (stack[step - 1] == 5) cout << ']' << endl;
			else if (stack[step - 1] == 6) cout << ')' << endl;

			break;
		case 4:
			if (index == 0)cout << "YES" << endl;
			else cout << "NO" << endl;
			break;
		}
	}
	delete[] stack;
	delete[] check;
}