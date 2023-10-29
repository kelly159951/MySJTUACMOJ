#include<iostream>
using namespace std;
class illegalSize {};
class outOfBound {};

template <class elemType>
class linkStack;

template <class elemType>
class Node
{
    friend class linkStack<elemType>;
private:
    elemType data;
    Node* next;
public:
    Node() { next = NULL; }
    Node(const elemType& x, Node* p = NULL)
    {
        data = x; next = p;
    }
};

template <class elemType>
class linkStack
{
private:
    Node<elemType>* Top;
public:
    linkStack() { Top = NULL; }; //初始化栈，使其为空栈
    bool isEmpty() { return (Top == NULL); }; //栈为空返回true,否则返回false。
    bool isFull() { return false; }; //栈满true，否则false。结点空间不连续，故总能满足
    elemType top();
    void push(const elemType& e);
    void pop();
    ~linkStack();
};

template <class elemType>
elemType linkStack<elemType>::top()
{
    if (!Top) throw outOfBound();//栈空
    return Top->data;
}

template <class elemType>
void linkStack<elemType>::push(const elemType& e)
{
    Top = new Node<elemType>(e, Top);
}

template <class elemType>
void linkStack<elemType>::pop()
{
    Node<elemType>* tmp;
    if (!Top) throw outOfBound();//栈空

    tmp = Top; //用tmp记住原栈顶结点空间，用于弹栈后的空间释放
    Top = Top->next; //实际将栈顶结点弹出栈

    delete tmp;//释放原栈顶结点空间
}

template <class elemType>
linkStack<elemType>::~linkStack()
{
    Node<elemType>* tmp;
    while (Top)
    {
        tmp = Top;
        Top = Top->next;
        delete tmp;
    }
}


int main() {

    char sufStr;
    int op1=0, op2=0, op=0;   
    int tmp=0, i=0;   
    linkStack<int> s;
    cin >> sufStr;
    int temp=0;
    int ex = 1;
    while (sufStr!= '@')
    {
        if ((sufStr >= '0') && (sufStr <= '9')) //数字转为整数后进栈
        {
            tmp = sufStr - '0';
            temp += tmp * ex;
            ex *= 10;
        }
        else if (sufStr == '.') {
            s.push(temp);
            temp = 0;
            ex = 1;
        }
        else
        {
            op2 = s.top(); 
            s.pop();      
            op1 = s.top(); 
            s.pop();
            switch (sufStr)
            {
            case '*': op = op1 * op2; break; 
            case '/': op = op1 / op2; break;
            case '+': op = op1 + op2; break;
            case '-': op = op1 - op2; break;
            };
            s.push(op); //每一步计算结果进栈
        }
        cin >> sufStr;
    }
    op = s.top(); 
    s.pop();
    cout << op << endl;
    return 0;
}
