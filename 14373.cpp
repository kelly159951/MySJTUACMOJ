#include<iostream>
using namespace std;
class circle_queue {
private:
	int size;
	int top;//队首
	int end;//队尾（从最后一个元素后面开始算起）
	int maxsize;

	void doublespace() {
		maxsize *= 2;
		top = 0;
		end = size;
	}
public:
	circle_queue(int s) {
		size = 0;
		top = 0;
		end = 0;
		maxsize = s;
	}

	void enQueue(int x) {//入队，输出入队后队尾的下标值以及队内元素个数
		if (size >= maxsize-1)doublespace();
		end = (end + 1) % maxsize;
		size++;
		cout << end << " " << size << endl;
	}
	void deQueue() {//出队，输出出队后队首的下标值以及队内元素个数
		if(size==0)cout << top << " " << 0 << endl;
		else{
			top = (top + 1) % maxsize;
			size--;
			cout << top << " " << size << endl;
		}
	}
};

int main() {
	int s, n;
	cin >> s >> n;
	circle_queue que=circle_queue(s);
	int step;
	for (int _ = 0; _ < n; _++) {
		cin >> step;
		if (step == 0) {
			cin >> step;
			que.enQueue(step);
		}
		else if (step == 1)que.deQueue();
	}
	return 0;
}
