#include<iostream>

using namespace std;
const char g = '.', w = '#', u = '?';

int main() {
	int m, n, unkn = 0, cnt = 0, ground = 0, water = 0;//未知点个数,计数
	char tp;
	cin >> n >> m;
	char** map = new char* [n];
	int* ui = new int[m * n];//存储未知点位置
	int* uj = new int[m * n];
	int* stack = new int[m * n];//存储访问状态
	int* to_be_visit = new int[m * n];
	int visit_index = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {
		map[i] = new char[m];
		for (int j = 0; j < m; j++) {
			cin >> tp;
			if (tp == u) {
				//ui[unkn] = i;
				//uj[unkn] =j;
				unkn++;
			}
			else if (tp == g)ground++;
			else water++;
			map[i][j] = tp;
		}
	}

	int x, y, temp;
	for (int i = 0; i < m * n; i++)stack[i] = 0;
	start = 0;
	cnt = 0;
	int number = 0;
	int* stk = new int[m * n];
	int stks = 0;
	int f;
	//cout << unkn << endl;
	int liua = unkn;
	while (cnt < liua) {
		stks = 0;
		f = 0;
		while (start < m * n) {
			if (stack[start] != 0) {
				start++;
				continue;
			}
			x = start / m;
			y = start % m;
			stack[start] = 1;
			if (map[x][y] == u) {
				to_be_visit[visit_index] = start;
				visit_index++;
				cnt++;
				break;
			}
			start++;
			//cout << "s"<<start << endl;
		}
		//cout << start << endl;
		stk[stks] = start;
		stks++;
		while (visit_index > 0) {
			temp = to_be_visit[visit_index - 1];
			visit_index--;
			x = temp / m;
			y = temp % m;
			if (x - 1 >= 0) {
				if (map[x - 1][y] == g)f = 1;
				if (stack[temp - m] != 1) {
					stack[temp - m] = 1;
					if (map[x - 1][y] == u) {
						to_be_visit[visit_index] = temp - m;
						visit_index++;
						cnt++;
						stk[stks] = temp - m;
						stks++;
					}
				}
			}
			if (x + 1 < n) {
				if (map[x + 1][y] == g)f = 1;
				if (stack[temp + m] != 1) {
					stack[temp + m] = 1;
					if (map[x + 1][y] == u) {
						to_be_visit[visit_index] = temp + m;
						visit_index++;
						cnt++;
						stk[stks] = temp + m;
						stks++;
					}
				}
			}
			if (y - 1 >= 0) {
				if (map[x][y - 1] == g)f = 1;
				if (stack[temp - 1] != 1) {
					stack[temp - 1] = 1;
					if (map[x][y - 1] == u) {
						to_be_visit[visit_index] = temp - 1;
						visit_index++;
						cnt++;
						stk[stks] = temp - 1;
						stks++;
					}
				}
			}
			if (y + 1 < m) {
				if (map[x][y + 1] == g)f = 1;
				if (stack[temp + 1] != 1) {
					stack[temp + 1] = 1;
					if (map[x][y + 1] == u) {
						to_be_visit[visit_index] = temp + 1;
						visit_index++;
						cnt++;
						stk[stks] = temp + 1;
						stks++;
					}
				}
			}
		}
		//cout <<"f"<< f << endl;
		//cout << cnt << endl;
		if (f == 0) {
			for (int r = 0; r < stks; r++) {
				map[stk[r] / m][stk[r] % m] = w;
				water++;
				unkn--;
			}

		}
	}


	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << map[i][j];
	//	}
	//	cout << endl;
	//}
	int alsd = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == u) {
				ui[alsd] = i;
				uj[alsd] = j;
				alsd++;
			}
		}
	}
	//判断连通性
	//初始化

	for (int i = 0; i < m * n; i++)stack[i] = 0;
	start = 0;
	cnt = 0;
	number = 0;
	visit_index = 0;
	while (cnt < unkn + ground) {
		number++;
		while (start < m * n) {//未被访问+能走
			if (stack[start] != 0) {
				start++;
				continue;
			}
			x = start / m;
			y = start % m;
			stack[start] = 1;
			if (map[x][y] != w) {
				to_be_visit[visit_index] = start;
				visit_index++;
				cnt++;
				break;
			}
			start++;
		}
		while (visit_index > 0) {
			temp = to_be_visit[visit_index - 1];
			visit_index--;
			x = temp / m;
			y = temp % m;
			if (x - 1 >= 0) {
				if (stack[temp - m] != 1) {
					stack[temp - m] = 1;
					if (map[x - 1][y] != w) {
						to_be_visit[visit_index] = temp - m;
						visit_index++;
						cnt++;
					}
				}
			}
			if (x + 1 < n) {
				if (stack[temp + m] != 1) {
					stack[temp + m] = 1;
					if (map[x + 1][y] != w) {
						to_be_visit[visit_index] = temp + m;
						visit_index++;
						cnt++;
					}
				}
			}
			if (y - 1 >= 0) {
				if (stack[temp - 1] != 1) {
					stack[temp - 1] = 1;
					if (map[x][y - 1] != w) {
						to_be_visit[visit_index] = temp - 1;
						visit_index++;
						cnt++;
					}
				}
			}
			if (y + 1 < m) {
				if (stack[temp + 1] != 1) {
					stack[temp + 1] = 1;
					if (map[x][y + 1] != w) {
						to_be_visit[visit_index] = temp + 1;
						visit_index++;
						cnt++;
					}
				}
			}
		}
	}
	if (number > 1) {
		cout << "Impossible" << endl;
		for (int i = 0; i < n; i++) {
			delete[] map[i];
		}
		delete[] map;
		delete[] ui;
		delete[] uj;
		delete[] stack;
		delete[] to_be_visit;
		return 0;
	}
	else {
		for (int k = 0; k < unkn; k++) {
			for (int i = 0; i < m * n; i++)stack[i] = 0;
			start = 0;
			cnt = 0;
			number = 0;
			visit_index = 0;
			stack[ui[k] * m + uj[k]] = 1;
			while (cnt < unkn + ground - 1) {
				number++;
				while (start < m * n) {//未被访问+能走
					if (stack[start] != 0) {
						start++;
						continue;
					}
					x = start / m;
					y = start % m;
					stack[start] = 1;
					if (map[x][y] != w) {
						to_be_visit[visit_index] = start;
						visit_index++;
						cnt++;
						break;
					}
					start++;
				}
				//cout << start << endl;
				//cout << visit_index << endl;
				while (visit_index > 0) {
					temp = to_be_visit[visit_index - 1];
					//cout << "now" << temp << endl;
					visit_index--;
					x = temp / m;
					y = temp % m;
					if (x - 1 >= 0) {
						if (stack[temp - m] != 1) {
							stack[temp - m] = 1;
							if (map[x - 1][y] != w) {
								to_be_visit[visit_index] = temp - m;
								visit_index++;
								cnt++;
								//cout << "above" << endl;
							}
						}
					}
					if (x + 1 < n) {
						if (stack[temp + m] != 1) {
							stack[temp + m] = 1;
							if (map[x + 1][y] != w) {
								to_be_visit[visit_index] = temp + m;
								visit_index++;
								cnt++;
								//cout << "down" << endl;
							}
						}
					}
					if (y - 1 >= 0) {
						if (stack[temp - 1] != 1) {
							stack[temp - 1] = 1;
							if (map[x][y - 1] != w) {
								to_be_visit[visit_index] = temp - 1;
								visit_index++;
								cnt++;
								//cout << "left" << endl;
							}
						}
					}
					if (y + 1 < m) {
						if (stack[temp + 1] != 1) {
							stack[temp + 1] = 1;
							if (map[x][y + 1] != w) {
								to_be_visit[visit_index] = temp + 1;
								visit_index++;
								cnt++;
								//cout << "right" << endl;
							}
						}
					}
				}
			}
			if (number == 1) {
				cout << "Ambiguous" << endl;
				for (int i = 0; i < n; i++) {
					delete[] map[i];
				}
				delete[] map;
				delete[] ui;
				delete[] uj;
				delete[] stack;
				delete[] to_be_visit;
				return 0;
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == u)cout << g;
			else cout << map[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] map[i];
	}
	delete[] map;
	delete[] ui;
	delete[] uj;
	delete[] stack;
	delete[] to_be_visit;
}