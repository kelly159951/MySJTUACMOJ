#include<iostream>
#include<vector>
using namespace std;

//元素交换次数=前面比他大的+后面比他小的


void rever(int n, int start, int end, int* a, int* an,int* temp) {

    
    if (start + 1 >= end)return;
    if (start + 2 == end) {
        if (a[start] > a[start+1]) {
            an[a[start]-1]++;
            an[a[start + 1]-1]++;
            swap(a[start], a[start + 1]);
        }
        return;
    }
    int mid = (start + end) / 2;
    rever(n,start, mid,a,an,temp);
    rever(n,mid, end,a,an,temp);
    int* w = new int[end - start ];//用于merge
    int i = start, j = mid, k = 0;
    
    ;//用于存储merge前数据的地址
    for (int i = start; i < end; i++) {
        temp[a[i]-1] = i;
    }
    // 循环比较两个数组的元素，并将较小的元素添加到合并数组中
    while (i < mid && j < end) {
        if (a[i] < a[j]) {
            w[k++] = a[i++];
        }
        else {
            w[k++] = a[j++];
        }
    }

    // 将剩余的元素添加到合并数组中
    while (i < mid) {
        w[k++] = a[i++];
    }

    while (j < end) {
        w[k++] = a[j++];
    }
    for (int p = 0; p < end-start; p++) {
        an[w[p] - 1] += abs(temp[w[p] - 1] - p-start);
        a[p + start] = w[p];
    }
    delete[] w;
    /*
    cout << "start" << endl;
    cout << start << " " << end << endl;
    for (int i = 0; i < n; i++)cout << a[i];
    cout << endl;
    for (int i = 0; i < n; i++)cout << an[i];
    cout << endl;
    */
}


int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    int* an = new int[n];
    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        an[i] = 0;
    }

    //每个数移动的次数=前比他大的数+后比他小的数
    rever(n, 0, n, a, an,temp);
    for (int i = 0; i < n; i++)cout << an[i] <<" ";
    delete[] a;
    delete[] an;
}