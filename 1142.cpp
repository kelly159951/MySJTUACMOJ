#include<iostream>
using namespace std;

int main() {
    long n, k, m, t;
    cin >> k >> n;
    long* prime = new long[n];
    long* s = new long[k+1];//存放了一系列point
    long* ans = new long[n+1];//存放丑数，第一个为1
    ans[0] = 1;
    for (int i = 1; i <= k; i++){
        cin >> prime[i];
        s[i] = 0;
    }
    for (int i = 1; i <= n; i++) {//n次循环寻找n个丑数
        m = -1;
        //cout << "p";
        for (int j = 1; j <= k; j++) {
            //cout << "o";
            t= prime[j] * ans[s[j]];//获取每个素数和他对应的下一个要乘的丑数
            //cout << "s";
            while (t <= ans[i - 1]) {//找到第一个比前一个丑数大的丑数
                s[j]++;
                t = prime[j] * ans[s[j]];
                //cout << "j";
            }
            if (m != -1) {
                m = min(m, t);
            }
            else { m = t; }
        }
        ans[i] = m;
        //cout << m << endl;
    }
    cout << ans[n];
    delete[] prime;
    delete[] s;
    delete[] ans;
}
