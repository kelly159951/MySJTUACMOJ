#include <iostream>
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf_s("%d", &n);
	if (n <= 1 || n>100000000) {
		printf("%d \n", 0);
		return 0;
	}
	//用素数筛
	int* c = new int[n];
	int* p = new int[n];
	int point = 0;
	for (int i = 0; i < n; i++) {
		c[i] = 0;
	}
	c[0] = 1;
	for (int i = 1; i < n; i++) {
		if (c[i] == 0) {
			p[point++] = i + 1;
		}
		for (int j = 0; j < point; j++) {//往上构成合数
			if (p[j] * (i + 1) <= n)c[p[j] * (i + 1) - 1] = 1;
			else break;
		}
	}
	printf("%.16lf \n", 2.0 * point / n / n);
	delete[] c;
	return 0;
}
