#include<iostream>
#include<vector>
#include <random>
#include <chrono>
#include<map>
#include<math.h>
#include <algorithm>

using namespace std;

// use precise time as random seed
const int RANDOM_SEED = chrono::system_clock::now().time_since_epoch().count();
mt19937 rng(RANDOM_SEED); // random number generator

int randint(int l, int r) { // rand in [l, r]
    return int(rng() % (r - l + 1) + l);
}
using namespace std;
int n, k;
vector <int> a;
int i, j;
void read_input_data_vector()
{
    int m;
    cin >> n >> k >> m; a.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    unsigned int z = a[m - 1];
    for (int i = m; i < n; i++)
    {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
}


int partition(vector <int>& a, int i, int j) {

    int ran = randint(i, j);
    int pivot = a[ran];
    int start = i;
    int end = j;
    int hole = i;
    if (a[i] != pivot) {
        for (int p = i; p <= j; p++) {
            if (a[p] == pivot) {
                swap(a[i], a[p]);
                break;
            }
        }
    }

    while (i < j) {
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

    int point = start;
    for (int p = start; p < i; p++) {
        if (a[p] != pivot) {
            a[point++] = a[p];
        }
    }
    for (int p = point; p < i; p++)a[p] = pivot;

    point = end;
    for (int p = end; p > i; p--) {
        if (a[p] != pivot) {
            a[point--] = a[p];
        }
    }
    for (int p = i; p <= point; p++)a[p] = pivot;

    for (int s = start; s < end; s++) {
        if (a[s] == pivot) {
            i = s;
            break;
        }
    }
    for (int s = end; s > i; s--) {
        if (a[s] == pivot) {
            j = s;
            break;
        }
    }
    if (i < k && j >= k-1)return pivot;
    if (j < k-1) {
        return partition(a, j+1, end);
    }
    else {
        return partition(a, start, i-1);
    }


}


int main() {
    read_input_data_vector();
    //n = 10;
    //a = { 10,9,8,7,6,5,4,3,2,1 };
    //k = 8;
    i = 0;
    j = n-1;
    

    cout << partition(a, i, j);;
}
