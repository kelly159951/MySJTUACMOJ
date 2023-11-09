//solution1:构建数组，遇到0-1-1就删除并插入-1
#include<iostream>
using namespace std;
int main() {
	int sta[500000];
	int point = 0;
	int data;
	cin >> data;
	while (data != -2) {
		sta[point] = data;
		point++;
		if (data == -1 && point > 2 && sta[point - 2] == -1 && sta[point - 3] == 0) {
			point -= 3;
			sta[point] = -1;
			point++;
			while (point > 2 && sta[point - 1] == -1 && sta[point - 2] == -1 && sta[point - 3] == 0) {
				point -= 3;
				sta[point] = -1;
				point++;
			}
		}
		cin >> data;
	}
	int num = 0, num1 = 0;
	for (int i = 0; i < point; i++) {//统计少加了多少-1
		if (sta[i] == -1)num1++;
		else num++;
	}
	for(int i=0;i<num-num1+1;i++){
		sta[point] = -1;
		point++;
		while (point > 2 && sta[point - 1] == -1 && sta[point - 2] == -1 && sta[point - 3] == 0) {
			point -= 3;
			sta[point] = -1;
			point++;
		}
	}


	cout << sta[0];
	for (int i = 1; i < point; i++)cout << " " << sta[i] ;
}


/*
solution2：每次遇到1，就把他的父亲结点标记为不能删掉，直到遇到已经被标记不被删掉的，这时候我们知道它的祖先已经被标记过了，就能停下来
#include <iostream>
#include <vector>

using namespace std;
class node;

vector<node*> mem;

class node {
public:
	bool del, finished;
	node* left, * right, * parent;
	int value;
	node(int val, node* par) {
		del = true;
		left = nullptr;
		right = nullptr;
		value = val;
		parent = par;
		finished = false;
	}
	~node() {
		delete left;
		delete right;
	}
};

node* construct(node* par) {
	int i;
	cin >> i;
	if (i == -1) return nullptr;
	if (i == -2) {
		node* t = new node(0, par);
		t->finished = true;
		return t;
	}
	node* tmp = new node(i, par);
	mem.push_back(tmp);
	if (i == 1) {
		node* tmp0 = tmp;
		while (tmp0 != nullptr && tmp0->del) {
			tmp0->del = false;
			tmp0 = tmp0->parent;
		}
	}
	tmp->left = construct(tmp);
	if (tmp->left && tmp->left->finished) {
		tmp->finished = true;
		return tmp;
	}
	tmp->right = construct(tmp);
	if (tmp->right && tmp->right->finished) {
		tmp->finished = true;
		return tmp;
	}
	return tmp;
}

void search(node* n) {
	if (n == nullptr) {
		cout << -1 << ' ';
		return;
	}
	if (!n->del) {
		cout << n->value << ' ';
		search(n->left);
		search(n->right);
	}
	else {
		cout << -1 << ' ';
	}

}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	node* tree = construct(nullptr);
	search(tree);
	delete tree;
	return 0;
}
*/