#include<iostream>
using namespace std;
struct node {
    int value;
    node* next;
    node() :next(NULL) {};
    node(int a, node* N = NULL) {
        value = a;
        next = N;
    }
};
struct LinkedList {
    node* head;
public:
    //初始化
    void initialize() {
        head=new node();
        int n;
        scanf("%d", &n);//输入函数：输入数字并赋值给变量n
        int* a = new int[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            head->next = new node(a[n - i], head->next);
        }
        delete[] a;
    }

    void insert(int i, int x) {
        if (i < 0)return;
        node* temp=head;
        int time = 0;
        while (temp->next != NULL && time < i) {
            temp = temp->next;
            time++;
        }
        temp->next = new node(x, temp->next);
        return;
    }

    //删除第i个数
    void erase(int i) {
        if (i <= 0)return;
        node* temp = head;
        int time = 0;
        while (temp->next != NULL && time < i-1) {
            temp = temp->next;
            time++;
        }
        if (temp->next == NULL)return;
        node* tm = temp->next;
        temp->next = tm->next;
        delete tm;
        return;
    }


    //奇偶位互换
    void swap() {
        if (head->next==NULL || head->next->next == NULL)return;
        node* a = head;
        node* b = head;
        node* temp = head;
        while ((a=a->next)!=NULL && (b=a->next)!=NULL) {
            temp->next = b;
            a->next = b->next;
            b->next = a;
            temp = a;
        }
        return;
    }

    //把前i个数整体往后移动x位
    void moveback(int i, int x) {
        node *a = head->next;
        node *b = head->next;
        for (int _ = 1; _ < i; _++) {
            b = b->next;
        }
        node* c = b->next;
        node* d = b->next;
        for (int _ = 1; _ < x; _++) {
            d = d->next;
        }
        head->next = c;
        b->next = d->next;
        d->next = a;
        return;
    }

    //获取第i个数
    int query(int i) {
        if (i <= 0)return -1;
        node* temp = head;
        int time = 0;
        while (temp != NULL && time < i) {
            temp = temp->next;
            time++;
        }
        if (temp == NULL)return -1;
        return temp->value;
    }

    //输出整个单链表，用空格隔开
    void printAll() {
        node* temp = head->next;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }

    void ClearMemory() {
        node* temp = head->next;
        while (temp != NULL) {
            node* s = temp->next;
            delete temp;
            temp = s;
        }
        delete head;
        return;
    }
};

int main() {
    LinkedList List;
    int m, op, i, x;
    List.initialize();
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &i, &x);
            List.insert(i, x);
        }
        else if (op == 2) {
            scanf("%d", &i);
            List.erase(i);
        }
        else if (op == 3) {
            List.swap();
        }
        else if (op == 4) {
            scanf("%d%d", &i, &x);
            List.moveback(i, x);
        }
        else if (op == 5) {
            scanf("%d", &i);
            printf("%d\n", List.query(i));
        }
        else if (op == 6) {
            List.printAll();
        }
    }
    List.ClearMemory();
    return 0;
}