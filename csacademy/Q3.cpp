#include<iostream>
#include<algorithm>
using namespace std;

struct catalog{
	int c, f, v;
}com[2004], task[2004];

bool f(catalog x, catalog y) {
	return x.f < y.f;
}

bool g(catalog x, catalog y) {
	return x.v < y.v;
}

int n, m, a[10005], b[10005];
bool c[10005];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &com[i].c, &com[i].f, &com[i].v);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &task[i].c, &task[i].f, &task[i].v);
	}
	sort(com, com + n, g);
	sort(task, task + m, g);
	reverse(task, task + m);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", com[i].c, com[i].f, com[i].v);
	}
	for (int i = 0; i < m; i++) {
		printf("%d %d %d\n", task[i].c, task[i].f, task[i].v);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!c[j] && com[j].f >= task[i].f && task[i].v > com[j].v) {
				ans += task[i].v - com[j].v;
				c[j] = true;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
