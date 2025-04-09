#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

struct pi {
	int s, r;
}a[100006];

bool f(pi x, pi y) {
	return x.s < y.s;
}

bool g(pi x, pi y) {
	return x.r > y.r;
}

int N, M, ans, b[100006], maxi;
vector <int> v, w, sum[100006];
int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i].s, &a[i].r);
		b[a[i].s]++;
		maxi = max(maxi, b[a[i].s]);
	}
	sort(a, a + N, f);
	v.push_back(a[0].s);
	w.push_back(0);
	for (int i = 1, j = 0; i < N; i++) {
		if (a[i].s != a[i - 1].s) {
			sort(a + j, a + i, g);
			j = i;
			v.push_back(a[i].s);
			w.push_back(i);
		}
		if (i == N - 1) {
			sort(a + j, a + i + 1, g);
		}
	}
	//for (int i = 0; i < N; i++) {
	//	printf("!%d %d\n", a[i].s, a[i].r);
	//}
	//for (int i = 0; i < v.size(); i++) {
	//	printf("!%d %d\n", v[i], w[i]);
	//}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < b[v[i]]; j++) {
			if (j == 0) {
				sum[i].push_back(a[w[i]].r);
			} else {
				int temp = sum[i].back() + a[w[i] + j].r;
				sum[i].push_back(temp);
			}
		}
	}
	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < b[v[i]]; j++) {
			printf("%d ", sum[i][j]);
		}
		printf("!\n");
	}*/
	for (int i = 1; i <= maxi; i++) {
		int temp = 0;
		for (int j = 1; j <= M; j++) {
			if (b[j] >= i) {
				temp += sum[v[j - 1] - 1][i - 1];
				//printf("!%d\n", sum[v[2] - 1][0]);
			}
		}
		ans = max(ans, temp);
	}
	printf("%d\n", ans);
	return 0;
}
