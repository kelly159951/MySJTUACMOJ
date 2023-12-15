#include<iostream>
using namespace std;
void adjust(int a[], int n, int i)
//对尺寸为n的数组a，假设根为0下标元素，
//调整下标为i的元素，使得以i为根的二叉树为一个大顶堆。
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

    //从倒数第一个非叶子结点开始调整，首次建立大顶堆
    for (i = (n - 1) / 2; i >= 0; i--)
        adjust(a, n, i);

    //换大顶，逐次减少参与的元素，重新调整为大顶堆
    for (j = n - 1; j >= 1; j--)
    {
        //大顶和第i个位置元素交换
        temp = a[0];
        a[0] = a[j];
        a[j] = temp;

        //调整第0个元素
        adjust(a, j, 0);
    }
}


void quicksort(int a[], int start, int end)
{
    int i, j, hole;
    int temp;

    //序列中没有元素或只有一个元素，递归结束
    if (end <= start) return;

    temp = a[start];
    hole = start;
    i = start; //从左到右搜索的指针
    j = end;   //从右到左搜索的指针

    while (i < j)
    {
        //从j位置开始从后往前找第一个小于temp的值
        while ((j > i) && (a[j] >= temp)) j--;
        if (j == i) break;
        a[hole] = a[j];
        hole = j;

        //从i位置开始从前往后找第一个大于等于temp的值
        while ((i < j) && (a[i] < temp)) i++;
        if (j == i) break;
        a[hole] = a[i];
        hole = i;
    }
    a[hole] = temp;

    //对标杆位置左边的序列实施同样的方法
    quicksort(a, start, hole - 1);
    //对标杆位置右边的序列实施同样的方法
    quicksort(a, hole + 1, end);
}

void quickSort(int a[], int n)
{
    quicksort(a, 0, n - 1);
}

int main() {
	int n;
	cin >> n;
	int* lis = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> lis[i];
	}
    quickSort(lis, n);
    for (int i = 0; i < n; i++) {
        cout << lis[i]<<" ";
    }



	delete[] lis;
}