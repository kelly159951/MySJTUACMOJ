#include <iostream>
#include <cstdio>
using namespace std;

/*
0 返回链表长度；
1 在位置i插入一个数。注意这里是指插入的数在插入后处于位置i，即插入在现在位置i数字的前面；
2 输出位置i的数。如果i超出链表长度，请输出-1；
3 删除位置i的数，整个链表长度减1；
4 删除位置i的数并将它插入至链表的尾端；
5 输出链表中最大的数。如果表为空请输出-1；
*/

namespace LIST
{

    struct NODE {
        int element;
        NODE* next;
        // TODO
    };

    NODE* head = nullptr;
    int len = 0;

    //初始化
    void init() {
    }

    //获取位置为i的链结（i从0开始）
    NODE* get_i(int i) {
        NODE* tmp = head;
        while (i-- > 0) tmp = tmp->next;
        return tmp;
    }

    void insert(int i, int x) {
        if (len == 0) {
            NODE* temp = new NODE;
            temp->element = x;
            temp->next = temp;
            head = temp;
            len++;
        }
        else {
            if (i == 0) {
                NODE* temp = new NODE;
                temp->element = x;
                temp->next = head;
                head = temp;
                len++;
                NODE* ind = get_i(len - 1);
                ind->next = head;
            }
            else if (i == len) {
                NODE* temp = new NODE;
                temp->element = x;
                temp->next = head;
                get_i(len - 1)->next = temp;
                len++;
            }
            else {
                NODE* ind = get_i(i - 1);
                NODE* temp = new NODE;
                temp->element = x;
                temp->next = ind->next;
                ind->next = temp;
                len++;
            }
        }
    }

    void remove(int i) {
        if (i == 0) {
            if (len == 1) {
                delete head;
                head = nullptr;
            }
            else {
                NODE* tmp = head;
                head = head->next;
                NODE* en = get_i(len - 2);
                en->next = head;
                delete tmp;
            }
            len--;
        }
        else {
            NODE* ind = get_i(i - 1);
            NODE* inds = ind->next;
            ind->next = inds->next;
            delete inds;
            len--;
        }
    }
    void remove_insert(int i) {
        int temp = get_i(i)->element;
        remove(i);
        insert(len, temp);
    }
    void get_length() {
        cout << len << endl;
    }
    void query(int i) {
        if (i >= len) {
            cout << -1 << endl;
            return;
        }
        else {
            auto x = [](int i) {
                NODE* tmp = head;
                while (i-- > 0) tmp = tmp->next;
                return tmp;
            } (i);
            cout << x->element << endl;

        }
    }
    void get_max() {
        if (len == 0) {
            cout << -1 << endl;
            return;
        }
        else {
            int ma = head->element;
            NODE* temp = head;
            for (int i = 0; i < len; i++) {
                temp = temp->next;
                if (temp->element > ma) {
                    ma = temp->element;
                }
            }
            cout << ma << endl;
        }
    }
    void clear() {
        if (head == nullptr) return;
        NODE* tmp = head, * tmp1;
        while (tmp->next != head) {
            tmp1 = tmp->next;
            delete tmp;
            tmp = tmp1;
        }
        delete tmp;
        len = 0;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch (op) {
        case 0:
            LIST::get_length();
            break;
        case 1:
            cin >> p >> x;
            LIST::insert(p, x);
            break;
        case 2:
            cin >> p;
            LIST::query(p);
            break;
        case 3:
            cin >> p;
            LIST::remove(p);
            break;
        case 4:
            cin >> p;
            LIST::remove_insert(p);
            break;
        case 5:
            LIST::get_max();
            break;
        }
    }
    LIST::clear();
    return 0;
}