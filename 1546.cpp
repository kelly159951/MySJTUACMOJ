#include<iostream>
using namespace std;

void adjust(int a[], int n, int i)
{
    int maxChild;
    int temp;

    while (true)
    {
        maxChild = 2 * i + 1;  //i的左子下标

        if (maxChild > n - 1) return;
        if (maxChild + 1 <= n - 1) //i还有右子
        {
            if (a[maxChild + 1] >= a[maxChild]) //右子大于等于左子
                maxChild++; //右子最大
        }

        if (a[i] > a[maxChild]) return; //最大孩子小于父结点
        //最大孩子大于等于父结点，父结点向下调整
        temp = a[i];
        a[i] = a[maxChild];
        a[maxChild] = temp;

        i = maxChild;  //继续向下调整
    }
}
void heapSort(int a[], int n)
{
    int i, j;
    int temp;
    for (i = (n - 1) / 2; i >= 0; i--)adjust(a, n, i);
    for (i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
    for (j = n - 1; j >= 1; j--)
    {
        temp = a[0];
        a[0] = a[j];
        a[j] = temp;
        adjust(a, j, 0);
    }
    for (i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
}
int main() {
	int n;
	cin >> n;
	int* stack = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> stack[i];
	}
    heapSort(stack, n);

	delete[] stack;
}