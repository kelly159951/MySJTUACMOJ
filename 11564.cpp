//#include<iostream>
//
//using namespace std;
//int main() {
//	int n, si, sj, ei, ej, cnt=0;//
//	cin >> n;
//	int map[6][6];
//	int price[6][6];//从起点到此处的代价和
//	int state[6][6];//从起点到此处的状态
//	int visit[6][6];
//	for (int _ = 0; _ < n; _++) {
//		//以price小为准则更新state
//		//更新操作：
//		cnt = 0;
//		for (int i = 0; i < 6; i++) {
//			for (int j = 0; j < 6; j++) {
//				cin >> map[i][j];
//				price[i][j] = 2147483647;
//				visit[i][j] = 0;
//			}
//		}
//		cin >> si >> sj >> ei >> ej;
//		//for (int i = 0; i < 6; i++) {
//		//	for (int j = 0; j < 6; j++) {
//		//		cout << map[i][j];
//		//	}
//		//	cout << endl;
//		//}
//		state[si][sj] = 1;
//		cnt = 1;
//		visit[si][sj] = 1;
//		price[si][sj] = 0;
//		int p;
//		while (cnt < 36) {
//			p = 2147483647;
//			int ni=-1;
//			int nj=-1;
//			for (int i = 0; i < 6; i++) {
//				for (int j = 0; j < 6; j++) {
//					if (visit[i][j] != 0) {
//						//cout << "visit" << i << j << endl;
//						visit[i][j] = 2;
//						int p1 = 2147483647;
//						int state1 = state[i][j];
//						if (i > 1) {
//							if (map[i - 1][j] * state[i][j] + map[i][j] * ((map[i - 1][j] * state[i][j]) % 4 + 1) < p1) {
//								p1 = map[i - 1][j] * state[i][j] + map[i][j] * ((map[i - 1][j] * state[i][j]) % 4 + 1);
//								state1 = (map[i][j] * ((map[i - 1][j] * state[i][j]) % 4 + 1)) % 4 + 1;
//							}
//						}
//						if (i < 5) {
//							if (map[i + 1][j] * state[i][j] + map[i][j] * ((map[i + 1][j] * state[i][j]) % 4 + 1) < p1) {
//								p1 = map[i + 1][j] * state[i][j] + map[i][j] * ((map[i + 1][j] * state[i][j]) % 4 + 1);
//								state1 = (map[i][j] * ((map[i + 1][j] * state[i][j]) % 4 + 1)) % 4 + 1;
//							}
//						}
//						if (j > 1) {
//							if (map[i][j-1] * state[i][j] + map[i][j] * ((map[i][j-1] * state[i][j]) % 4 + 1) < p1) {
//								p1 = map[i][j-1] * state[i][j] + map[i][j] * ((map[i][j-1] * state[i][j]) % 4 + 1);
//								state1 = (map[i][j] * ((map[i][j-1] * state[i][j]) % 4 + 1)) % 4 + 1;
//							}
//						}
//						if (j < 5) {
//							if (map[i][j + 1] * state[i][j] + map[i][j] * ((map[i][j + 1] * state[i][j]) % 4 + 1) < p1) {
//								p1 = map[i][j + 1] * state[i][j] + map[i][j] * ((map[i][j + 1] * state[i][j]) % 4 + 1);
//								state1 = (map[i][j] * ((map[i][j + 1] * state[i][j]) % 4 + 1)) % 4 + 1;
//							}
//						}
//						if (i > 1) {
//							if (map[i - 1][j] * state[i][j] <= p && visit[i - 1][j] == 0) {
//								p = map[i - 1][j] * state[i][j];
//								ni = i - 1;
//								nj = j;
//							}
//							if (map[i - 1][j] * state[i][j] + price[i][j] < price[i - 1][j]) {
//								price[i - 1][j] = map[i - 1][j] * state[i][j] + price[i][j];
//								state[i - 1][j] = (map[i - 1][j] * state[i][j]) % 4 + 1;
//							}
//							if (map[i - 1][j] * state1+p1 <= p && visit[i - 1][j] == 0) {
//								p = map[i - 1][j] * state1+p1;
//								ni = i - 1;
//								nj = j;
//							}
//							if (map[i - 1][j] * state1 + p1+price[i][j] < price[i - 1][j]) {
//								price[i - 1][j] = map[i - 1][j] * state1 + p1 + price[i][j];
//								state[i - 1][j] = (map[i - 1][j] * state1) % 4 + 1;
//							}
//						}
//						if (i < 5) {
//							if (map[i + 1][j] * state[i][j] <= p && visit[i + 1][j] == 0) {
//								p = map[i + 1][j] * state[i][j];
//								ni = i + 1;
//								nj = j;
//
//							}
//							if (map[i + 1][j] * state[i][j] + price[i][j] < price[i + 1][j]) {
//								price[i + 1][j] = map[i + 1][j] * state[i][j] + price[i][j];
//								state[i + 1][j] = (map[i + 1][j] * state[i][j]) % 4 + 1;
//							}
//							if (map[i + 1][j] * state1+p1 <= p && visit[i + 1][j] == 0) {
//								p = map[i + 1][j] * state1+p1;
//								ni = i + 1;
//								nj = j;
//
//							}
//							if (map[i + 1][j] * state1 + p1+ price[i][j] < price[i + 1][j]) {
//								price[i + 1][j] = map[i + 1][j] * state1 + p1+ price[i][j];
//								state[i + 1][j] = (map[i + 1][j] * state1) % 4 + 1;
//							}
//						}
//						if (j > 1) {
//							if (map[i][j - 1] * state[i][j] <= p && visit[i][j - 1] == 0) {
//								p = map[i][j - 1] * state[i][j];
//
//								ni = i;
//								nj = j - 1;
//								
//							}
//							if (map[i][j-1] * state[i][j] + price[i][j] < price[i][j - 1]) {
//								price[i][j-1] = map[i][j-1] * state[i][j] + price[i][j];
//								state[i][j-1] = (map[i][j-1] * state[i][j]) % 4 + 1;
//							}
//							if (map[i][j - 1] * state1 +p1<= p && visit[i][j - 1] == 0) {
//								p = map[i][j - 1] * state1;
//
//								ni = i;
//								nj = j - 1;
//
//							}
//							if (map[i][j - 1] * state1 + p1+ price[i][j] < price[i][j - 1]) {
//								price[i][j - 1] = map[i][j - 1] * state1 + p1+ price[i][j];
//								state[i][j - 1] = (map[i][j - 1] * state1) % 4 + 1;
//							}
//						}
//						if (j < 5) {
//							if (map[i][j + 1] * state[i][j] <= p && visit[i][j + 1] == 0) {
//								p = map[i][j + 1] * state[i][j];
//									ni = i;
//									nj = j + 1;
//								
//							}
//							if (map[i][j + 1] * state[i][j] + price[i][j] < price[i][j + 1]) {
//								price[i][j + 1] = map[i][j + 1] * state[i][j] + price[i][j];
//								state[i][j + 1] = (map[i][j + 1] * state[i][j]) % 4 + 1;
//							}
//							if (map[i][j + 1] * state1 +p1<= p && visit[i][j + 1] == 0) {
//								p = map[i][j + 1] * state1;
//								ni = i;
//								nj = j + 1;
//
//							}
//							if (map[i][j + 1] * state1 + p1+ price[i][j] < price[i][j + 1]) {
//								price[i][j + 1] = map[i][j + 1] * state1 + p1+price[i][j];
//								state[i][j + 1] = (map[i][j + 1] * state1) % 4 + 1;
//							}
//						}
//					}
//				}
//			}
//			//cout << ni << nj << endl;
//			visit[ni][nj] = 1;
//			cnt++;
//			//cout << "visit" << endl;
//			//for (int i = 0; i < 6; i++) {
//			//	for (int j = 0; j < 6; j++) {
//			//		cout << visit[i][j] << " ";
//			//	}
//			//	cout << endl;
//			//}
//			//cout << "price" << endl;
//			//for (int i = 0; i < 6; i++) {
//			//	for (int j = 0; j < 6; j++) {
//			//		cout << price[i][j]<<" ";
//			//	}
//			//	cout << endl;
//			//}
//			//cout << "state" << endl;
//			//for (int i = 0; i < 6; i++) {
//			//	for (int j = 0; j < 6; j++) {
//			//		cout << state[i][j]<<" ";
//			//	}
//			//	cout << endl;
//			//}
//		}
//		cout << price[ei][ej] << endl;
//	}
//
//}

#include <iostream>
#include <cstring>
using namespace std;
int di[4] = { 1, 0, -1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int map[6][6];
int visit[6][6];
int ans = 0;
int si, sj, ei, ej;
int n;

void dfs(int x, int y, int ei, int ej, int price, int state, int& minp) {
    if (x == ei && y == ej) {//到达终点则停止
        minp = min(price, minp);
        return;
    }
    for (int k = 0; k < 4; ++k) {//遍历上下左右四个点
        int newi = x + di[k];
        int newj = y + dj[k];
        if (!visit[newi][newj] && newi >= 0 && newi < 6 && newj >= 0 && newj < 6) {
            visit[x][y] = 1;
            dfs(newi, newj, ei, ej, price + map[newi][newj] * state, (map[newi][newj] * state) % 4 + 1, minp);
            visit[x][y] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int _ = 0; _ < n; ++_) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                cin >> map[i][j];
                visit[i][j] = 0;
            }
        }
        cin >> si >> sj >> ei >> ej;
        visit[si][sj] = 1;
        int minp = 2147483647;
        dfs(si, sj, ei, ej, 0, 1, minp);
        cout << minp << endl;
    }
    return 0;
}