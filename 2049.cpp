#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

class illegalSize {};
class outOfBound {};

template <class elemType>
class seqStack
{
private:
	elemType* array;    //ջ�洢���飬���ʵ�ʵ�����Ԫ�ء�
	int Top;            //ջ���±ꡣ
	int maxSize;	    //ջ������ܴ�ŵ�Ԫ�ظ�����
	void doubleSpace();
public:
	seqStack(int initSize = 100); //��ʼ��˳��ջ
	bool isEmpty() { return (Top == -1); }; //ջ�շ���true,���򷵻�false��
	bool isFull() { return (Top == maxSize - 1); };//ջ������true,���򷵻�false��
	elemType top();// ����ջ��Ԫ�ص�ֵ�����ı�ջ��
	void push(const elemType& e);//��Ԫ��eѹ��ջ����ʹ���Ϊ�µ�ջ����
	void pop(); //��ջ��Ԫ�ص�ջ��
	void clear() { Top = -1; }; //���ջ������Ԫ��
	~seqStack() { delete[]array; }; //�ͷ�ջռ�õĶ�̬����
};

template <class elemType>
seqStack<elemType>::seqStack(int initSize)//��ʼ��˳��ջ
{
	array = new elemType[initSize];
	if (!array) throw illegalSize();
	Top = -1;
	maxSize = initSize;
}

template <class elemType>
void seqStack<elemType>::doubleSpace()
{
	elemType* tmp;
	int i;

	tmp = new elemType[maxSize * 2];
	if (!tmp) throw illegalSize();

	for (i = 0; i <= Top; i++) tmp[i] = array[i]; 	// ������ƽ�㡣
	delete[]array;
	array = tmp;
	maxSize = 2 * maxSize;
}

template <class elemType>
elemType seqStack<elemType>::top()// ����ջ��Ԫ�ص�ֵ�����ı�ջ��
{
	if (isEmpty()) throw outOfBound();
	return array[Top];
}

template <class elemType>
void seqStack<elemType>::push(const elemType& e)//��Ԫ��eѹ��ջ����ʹ���Ϊ�µ�ջ����
{
	if (isFull()) doubleSpace();//ջ��ʱ���·���2���Ŀռ䣬����ԭ�ռ����ݿ���
	array[++Top] = e;      	// �½������µ�ջ��λ�á�
}

template <class elemType>
void seqStack<elemType>::pop()//��ջ��Ԫ�ص�ջ��
{
	if (Top == -1) throw outOfBound();
	Top--;
}

#endif // SEQSTACK_H_INCLUDED
#include<iostream>
using namespace std;
int main() {
	int n,a,b,m,k;
	cin >> n;
	int* left = new int[n+1];
	int* right = new int[n+1];
	int* depth = new int[n+1];
	int* father = new int[n+1];
	depth[1] = 1;
	father[1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		left[i] = a;
		right[i] = b;
		if (a != -1) {
			father[a] = i;
			depth[a] = depth[i] + 1;
		}
		if (b != -1) {
			father[b] = i;
			depth[b] = depth[i] + 1;
		}
	}
	
	cin >> m;
	for (int _ = 0; _ < m; _++) {
		cin >> k;
		for (int i = 1; i <= n; i++) {
			if (depth[i] % k == 0) {
				int tmp = left[i];
				left[i] = right[i];
				right[i] = tmp;
			}
			


		
		}


		seqStack<int> s1;
		seqStack<int> s2;
		int p = 1;
		int flag;
		int zero = 0, one = 1;

		s1.push(p); s2.push(zero);

		while (!s1.isEmpty())
		{
			flag = s2.top(); s2.pop();
			p = s1.top();

			if (flag == 1)
			{
				s1.pop();
				cout << p<<" ";
				if (right[p] == -1) continue;
				s1.push(right[p]);
				s2.push(zero);
			}
			else
			{
				s2.push(one);
				if (left[p] != -1)
				{
					s1.push(left[p]);
					s2.push(zero);
				}
			}
		}
		cout << endl;
		

	}
	delete[] left;
	delete[] right;
	delete[] depth;
	delete[] father;
}