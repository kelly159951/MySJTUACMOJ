#include<iostream>
using namespace std;
/*int number = 0;
struct node {
	char data;
	node *l, *r;
	node() {
		data = '#';
		l = nullptr;
		r = nullptr;
	}
	node(char d) {
		data = d;
		l = nullptr;
		r = nullptr;
	}
};
void build(node* root) {
	char l,r;
	cin >> l;
	if (l != '.') {
		node* left = new node(l);
		root->l = left;
		number++;
		build(left);
	}
	cin >> r;
	if (r != '.') {
		node* right = new node(r);
		root->r = right;
		number++;
		build(right);
	}
}

void midorder(node* root) {
	node** stack = new node*[number];
	int* flag = new int[number];
	for (int i = 0; i < number; i++)flag[i] = 0;
	int point = 0;
	stack[point] = root;
	while (point>=0) {
		node* temp = stack[point];
		if (flag[point] == 0 && temp->l!=nullptr) {
			flag[point] = 1;
			stack[++point] = temp->l;
			flag[point] = 0;
		}
		else {
			cout << temp->data << ' ';
			if (temp->r != nullptr) {
				stack[point] = temp->r;
				flag[point] = 0;
			}
			else point--;
		}

	}
	delete[] stack;
	delete[] flag;
}

void postorder(node* root) {
	node** stack = new node * [number];
	int* flag = new int[number];
	for (int i = 0; i < number; i++)flag[i] = 0;
	int point = 0;
	stack[point] = root; 
	while (point >= 0) {
		node* temp = stack[point];
		if (flag[point] == 0 ) {
			if (temp->l != nullptr) {
				flag[point] = 1;
				stack[++point] = temp->l;
				flag[point] = 0;
			}
			else flag[point] = 1;
		}
		else if (flag[point] == 1) {
			if (temp->r != nullptr) {
				flag[point] = 2;
				stack[++point] = temp->r;
				flag[point] = 0;
			}
			else flag[point] = 2;
		}
		else {
			cout << temp->data << ' ';
			point--;
		}

	}
	delete[] stack;
	delete[] flag;
}


int main() {
	char s;
	cin >> s;
	node* root = new node(s);
	number++;
	build(root);
	midorder(root);
	cout << endl;
	postorder(root);
}
*/


int main() {
	int* stack = new int[200000];
	int* stack2 = new int[200000];
	int* an= new int[200000];
	int* an2 = new int[200000];

	int num = 0, flag1 = 0, flag2 = 0, point = -1, point2 = -1;
	char* s = new char[7];
	cin >> s;
	int t = 0;
	int temp = 0;
	while (s[t] != '\0' && s[t] != '.')temp = 10 * temp + s[t++] - '0';
	while (!(point == -1 && s[0] == '.')) {
		if (s[0] != '.') {
			stack[++point] = temp;
			num++;
		}
		else an[flag1++] = stack[point--];

		if (s[0] == '.' && stack2[point2] == -1) {
			an2[flag2++] = stack2[--point2];
			stack2[point2] = -1;
			while (stack2[point2] == -1 && stack2[point2 - 1] == -1){
				point2 -= 2;
				an2[flag2++] = stack2[point2];
				stack2[point2] = -1;
			}
		}
		else {
			if (s[0] == '.')stack2[++point2] = -1;
			else stack2[++point2] = temp;
		}
		cin >> s;
		t = 0; temp = 0;
		while (s[t] != '\0' && s[t] != '.')temp = 10 * temp + s[t++] - '0';
	}

	stack2[++point2] = -1;
	while (stack2[point2] == -1 && stack2[point2 - 1] == -1) {
		point2 -= 2;
		an2[flag2++] = stack2[point2];
		stack2[point2] = -1;
	}

	for (int i = 0; i < num; i++)cout << an[i] << ' ';
	cout << endl;
	for (int i = 0; i < num; i++)cout << an2[i] << ' ' ;
	cout << endl;
	delete[] stack;
	delete[] stack2;
	delete[] an;
	delete[] an2;
	delete[] s;
}