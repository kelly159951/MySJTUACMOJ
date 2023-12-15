#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node(int dta) {
		data = dta;
		next = nullptr;
	}
};
int main() {
	int n, s, m, t, cn=0;
	cin >> n;
	node* head = nullptr;
	node* p = nullptr;
	node* next;

	for (int i = 0; i < n; i++) {
		cin >> s;
		next = new node(s);
		if (p!=nullptr) {
			p->next = next;
			p = next;
		}
		else {
			head = next;
			p = next;
		}
	}
	
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> t; 
		cn++;
		if (head->data == t) {
			continue;
		}
		else {
			p = head;
			while (p->next != nullptr ) {
				cn++;
				if (p->next->data == t) {
					next = p->next;
					p->next=next->next;
					next->next = head;
					head = next;
					break;
				}
				else {
					p = p->next;
				}
			}
		}
		
	}
	cout << cn << endl;
	while (head != nullptr) {
		next = head->next;
		delete head;
		head = next;
	}
	return 0;

}