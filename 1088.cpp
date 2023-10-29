#include<iostream>
using namespace std;
/*int main() {
    int n;
    int m;
    cin >> n >> m;
    int left = 0, right = 0; //记录最后一个数左边和后边的数字的个数
    int derection = 0;//记录倒推的方向（1左0右边），开始时默认向右
    for (int i = 1; i <= n; i++) {
        if (((((m - 1) / i) % 2) + derection) % 2 ) {
            left++;
            derection = 0;
        }
        else {
            right++;
            derection = 1;
        }
        cout << i << endl;
        cout << left << right << endl;

    }
    if (derection) {
        cout << left << right << endl;
        return 0;
    }
    cout << right << left << endl;
    return 0;

}*/

int main() {
    int n, m, N;
    cin >> n >> m;
    N = n;
    int* remain=new int[N + 1];//记录每个人的出局顺序
    int point = 0;//当前报数人的编号，初始值为0
    int direction = 1;// 报数方向，true右，false左
    int i = 1;
    while(n > 1) {
        if (direction) {//向右
            point += m;
            while (point >= n) {//超出则换方向
                direction = 1 - direction;
                point -= (n - 1);
            }
            if (!direction)point = n + 1 - point;//向左则调整以一下当前报号数字
        }
        else {
            point -= m;
            while (point < 1) {
                point += (n - 1);
                direction = 1 - direction;
            }
            if (direction)point = n + 1 - point;
        }
        remain[i] = point;//记录第i个被淘汰的人的编号
        cout << point << endl;
        if (direction and point != n)point --;
        if (direction and point == n)direction = false;//到最后一个则反向
        if (!direction and point == 1)point --, direction = true;
        i++;
        n--;
    }

 

    //统计编号比
    int an = 1;
    for (int i = N - 1; i > 0; i--) {
        if (remain[i] <= an)an++;
    }
    cout << an << endl;
    delete[] remain;
}
