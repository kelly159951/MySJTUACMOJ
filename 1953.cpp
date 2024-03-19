#include<vector>
#include<map>
#include<iostream>
#include<math.h>
#include <algorithm>

using namespace std;


pair<int, int> partition(vector <int>& a, int pivot) {
    int i = 0;
    int j = a.size()-1;
    int hole = 0;
    if (a[0] != pivot) {
        for (int p = 0; p <= j; p++) {
            if (a[p] == pivot) {
                swap(a[0], a[p]);
                break;
            }
        }
    }

    while (i < j){
        while ((j > i) && (a[j] >= pivot)) j--;
        if (j == i) break;
        a[hole] = a[j];
        hole = j;
        while ((i < j) && (a[i] < pivot)) i++;
        if (j == i) break;
        a[hole] = a[i];
        hole = i;
    }
    a[hole] = pivot;
    
    int point = 0;
    for (int p = 0; p < i; p++) {
        if (a[p] != pivot) {
            a[point++] = a[p];
        }
    }
    for (int p = point; p < i; p++)a[p] = pivot;

    point = a.size() - 1;
    for (int p = a.size()-1; p >i; p--) {
        if (a[p] != pivot) {
            a[point--] = a[p];
        }
    }
    for (int p = i; p <= point; p++)a[p] = pivot;

    for (int s = 0; s < a.size(); s++) {
        if (a[s] == pivot) {
            i = s;
            break;
        }
    }
    for (int s = a.size()-1;s>i; s--) {
        if (a[s] == pivot) {
            j = s;
            break;
        }
    }
    int temp = (i + j) / 2;
    i = temp;
    j = temp+1;
    return { i,j };
}




int main() {
    int n, pivot;
    cin >> n >> pivot;
    vector <int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    auto [l, r] = partition(arr, pivot);
    for (auto i : arr) cout << i << ' ';
    cout << '\n' << l << ' ' << r << '\n';
}
/*
int main() {
    int n, pivot;
    cin >> n >> pivot;
    vector <int> arr, before;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    before = arr;
    auto [l, r] = partition(arr, pivot);
    cout << "Returns: " << l << " " << r << endl;
    cout << "Array after modification:";
    for (auto i : arr) {
        cout << ' ' << i;
    }
    cout << endl;
    // check solution:
    vector <int> after = arr;
    sort(before.begin(), before.end());
    sort(after.begin(), after.end());
    if (before != after) {
        cout << "FAILED: numbers not matched" << endl;
        return 1;
    }
    if (l < 0 || r > n || l > r || (l == r && (l == 0 || l == n))) {
        cout << "FAILED: l r at bad position" << endl;
        return 1;
    }
    int left = 0, right = 0, mid = 0;
    for (int i = 0; i < l; i++) {
        if (arr[i] > pivot) {
            cout << "FAILED: position " << i << " is greater than pivot" << endl;
            return 1;
        }
        if (arr[i] == pivot) left++;
    }
    for (int i = l; i < r; i++) {
        if (arr[i] != pivot) {
            cout << "FAILED: position " << i << " is not equal to pivot" << endl;
            return 1;
        }
        mid++;
    }
    for (int i = r; i < n; i++) {
        if (arr[i] < pivot) {
            cout << "FAILED: position " << i << " is less than pivot" << endl;
            return 1;
        }
        if (arr[i] == pivot) right++;
    }
    double ratio = max(left, right) * 1. / (left + mid + right);
    cout << "Ratio: " << ratio << endl;
    if (max(left, right) > 10 && ratio > 0.8) {
        cout << "FAILED: too imbalanced" << endl;
        return 1;
    }
    cout << "OK" << endl;
}
*/