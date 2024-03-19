
#include<vector>
#include<iostream>
#include<algorithm>
#include <cmath>
#include <iomanip> 
using namespace std;

const long double INF = 9223372036854775807;
long double ret = INF;
long double pow_2(long long x) {
    return x * x;
}

struct point {
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {}
    long double distance_2(const point& other) const {
        return sqrt(pow_2(x - other.x) + pow_2(y - other.y));
    }
};

long double solve(vector <point>& a, int l, int r) {
    if (l + 2 >= r)return INF;//只有两个点
    int m = (l + r) / 2;
    long double temp = min(solve(a, l, m), solve(a, m, r));//两边分别求最小值
    ret = min(temp, ret);
    //计算两部分之间的最小周长三角形
    vector<point> strip;
    //筛选有可能的点
    for (int i = l; i < r; i++) {
        if (abs(a[i].x - a[m].x) < ret) {
            strip.push_back(a[i]);
            //cout << "k" << i;
        }

    }
    //按y排序
    sort(strip.begin(), strip.end(), [](auto& u, auto& v) {
        return u.y < v.y;
        });
    int s = strip.size();
    //cout << strip.size()<< endl;
    //cout << "j";
    //cout << s;
    for (int i = 0; i < s; i++) {
        //cout << "t";
        for (int j = i + 1; j < s; j++) {
           // cout << "s" ;
            if (strip[j].y - strip[i].y >= ret)break;
            
            for (int z = j + 1; z < s; z++) {
                if (strip[j].y - strip[i].y+ strip[z].y - strip[i].y+ strip[z].y - strip[j].y >= ret)break;
                ret = min(ret, strip[i].distance_2(strip[j]) + strip[j].distance_2(strip[z]) + strip[i].distance_2(strip[z]));
               // long double r = strip[i].distance_2(strip[j]) + strip[j].distance_2(strip[z]) + strip[i].distance_2(strip[z]);
                //cout << ret << endl;
               // if (r < ret) {
                  //  cout << i << j << z << endl;
                 //   ret = r;
                //}
            }
            
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector <point> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(point(x, y));
    }
    sort(a.begin(), a.end(), [](auto& u, auto& v) {//按x升序排列
        return u.x < v.x;
        });
    cout << fixed << setprecision(10) << solve(a, 0, n) << endl;
}