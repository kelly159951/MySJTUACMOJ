#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node(int d, node* n) {
		data = d;
		next = n;
	}
};
int main() {
	int n, m, data, p, q;
	cin >> n >> m;
	node** lists = new node* [n];
	for (int i = 0; i < n; i++) {
		cin >> data;
		node* w = new node(data, nullptr);
		lists[i] = w;
	}
	for (int i = 0; i < m; i++) {
		cin >> data;
		switch (data) {
		case 0:
			cin >> p >> q;
			if (lists[p] == nullptr)lists[p] = lists[q];
			else if (lists[q] != nullptr) {
				node* temp1, * temp2, * tail;
				temp1 = lists[p];
				temp2 = lists[q];
				if (temp1->data <= temp2->data) {
					lists[p] = temp1;
					tail = temp1;
					temp1 = temp1->next;
				}
				else {
					lists[p] = temp2;
					tail = temp2;
					temp2 = temp2->next;
				}
				while (temp1 && temp2) {
					if (temp1->data <= temp2->data) {
						tail->next = temp1;
						temp1 = temp1->next;
					}
					else {
						tail->next = temp2;
						temp2 = temp2->next;
					}
					tail = tail->next;
				}
				if (temp1)tail->next = temp1;
				else if (temp2)tail->next = temp2;
			}
			lists[q] = nullptr;
			break;
		case 1:
			cin >> q;
			if (lists[q]) {
				cout << lists[q]->data << endl;
				lists[q] = lists[q]->next;
			}
			else cout << -1 << endl;
			break;
		case 2:
			cin >> q >> p;
			node* te = new node(p, nullptr);
			if (lists[q] == nullptr)lists[q] = te;
			else if (lists[q]->data >= p) {
				te->next = lists[q];
				lists[q] = te;
			}
			else {
				node* tem = lists[q];
				while (tem->next && tem->next->data < p)tem = tem->next;
				if (tem->next) {
					node* s = tem->next;
					tem->next = te;
					te->next = s;
				}
				else {
					tem->next = te;
				}
			}
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (lists[i]) {
			node* t = lists[i];
			while (t) {
				node* t1 = t;
				t = t->next;
				delete t1;
			}
		}
	}
	delete[] lists;

}