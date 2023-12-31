#include<iostream>
#define MAXN 100010
using namespace std;
struct linklistwithorder {
	int* data;
	int* order;
	int len;
	int maxlen;
	linklistwithorder() {
		data = new int[16];
		order = new int[16];
		len = 0;
		maxlen = 16;

	}
	~linklistwithorder() {
		delete[] data;
		delete[] order;
	}
	void db() {
		int* temp = data;
		maxlen *= 2;
		data = new int[maxlen];
		for (int i = 0; i < len; i++)data[i] = temp[i];
		delete[] temp;
		temp = order;
		order = new int[maxlen];
		for (int i = 0; i < len; i++)order[i] = temp[i];
		delete[] temp;
	}
	void add(int a,int b) {
		if (len >= maxlen-1)db();
		data[len] = a;
		order[len] = b;
		len++;
	}

};

int* fa, * ancestor, * dis_to_root;//储存每个元素的父节点、祖先节点、到第一个点的距离
linklistwithorder* tree;//存储每个元素的链接点（邻接表）
linklistwithorder* queries;//存要查询哪些
bool vis[MAXN];//存储访问状态，1表示已经被访问过了
bool marked[MAXN];//代表一个节点和它的子节点被处理过了
int* answer;

inline void init(int n)//将父节点初始化为自己
{
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	dis_to_root[1] = 0;
}

int find(int x)//查询x所在的集合的祖先
{
	if (x == fa[x])//集合祖先：自己是自己的祖先
		return x;
	else {//否则递归往上找祖先
		fa[x] = find(fa[x]);  
		return fa[x];         
	}
}

inline void merge(int i, int j)//合并ij所在的集合：就是把i所在集合的祖先的祖先，定位j的
{
	fa[find(i)] = find(j);
}

void tar_lca(int u) {
	vis[u] = true;
	ancestor[find(u)] = u;//把u所在集合的共同祖先都变成u
	for (int i = 0; i < tree[u].len; ++i) {//遍历u结点所有没有被访问过的子节点
		if (!vis[tree[u].data[i]]) {
			dis_to_root[tree[u].data[i]] = dis_to_root[u] + tree[u].order[i];
			tar_lca(tree[u].data[i]);
			merge(u, tree[u].data[i]);//合并u和他的子节点所在集合
			ancestor[find(u)] = u;//把u所在集合的共同祖先都变成u
			//cout << tree[u].data[i] << " to root" << " : " << dis_to_root[u] + distances[u][tree[u].data[i]] << endl;;
		}
	}
	marked[u] = true;//代表一个节点和它的子节点被处理过了～

	for (int i = 0; i < queries[u].len; ++i) {//遍历以u为一端的所有询问，找出另一端已经处理过的，给出他们的共同祖先
		if (marked[queries[u].data[i]]) {
			//cout << u << "and" << queries[u].data[i] << ':' << ancestor[find(queries[u].data[i])] << ' ';
			//cout << "dis " << u << " and " << queries[u].data[i] << " : " << dis << endl;
			answer[queries[u].order[i]] = dis_to_root[u] + dis_to_root[queries[u].data[i]] - 2 * dis_to_root[ancestor[find(queries[u].data[i])]];
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int m, n, x, y, k;
	cin >> n;
	tree = new linklistwithorder[n+1];
	fa = new int[n+1];
	ancestor= new int[n+1]; 
	dis_to_root= new int[n+1];

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> k;

		tree[x].add(y,k);
		tree[y].add(x,k);
		vis[i + 1] = false;//设置所有点的访问状态

	}
	init(n);
	cin >> m;
	queries = new linklistwithorder[n+1];//存储所有的询问
	answer = new int[m];

	for (int i = 0; i < m; ++i) {
		cin >> x >> y;	
		if (x == y) {
			answer[i] = 0;
		}
		else {
			queries[x].add(y,i);
			queries[y].add(x,i);
		}
	}
	tar_lca(1);
	for (int t = 0; t < m; t++) {
		cout << answer[t] << endl;
	}

	delete[] tree;
	delete[] fa;
	delete[] ancestor;
	delete[] dis_to_root;
	delete[] queries;
	delete[] answer;
}