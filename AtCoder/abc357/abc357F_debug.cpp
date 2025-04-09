#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

const int sqrt = 48;

int n, q;
mint a[2][200006];
vector<mint> sum[2], up[2], sum_mul, cnt;

vector<int> ans[2];

int qq[200006][10];
int B[2][200006];

void update(int t, int l, int r, int x) {
	int start = l / sqrt;
	int end = r / sqrt;
	
//	printf("## %d %d\n", start, end);
	for (int i = start; i <= end; i++) {
		if (i == start || i == end) {
			mint temp = 0;
//			printf("stop %d %d\n", t, i);
			sum[0][i] = 0;
			sum[1][i] = 0;
//			printf("stop\n");
			for (int j = i * sqrt; j < (i + 1) * sqrt && j < n; j++) {
//				printf("fxxk!! %d %d\n", i, j);
				if (j >= l && j <= r) {
					a[t][j] += x;
				}
				a[0][j] += up[0][i];
				a[1][j] += up[1][i];
				sum[0][i] += a[0][j];
				sum[1][i] += a[1][j];
				temp += a[0][j] * a[1][j];
			}
			sum_mul[i] = temp;
			up[0][i] = 0;
			up[1][i] = 0;
		} else {
			sum_mul[i] += 1ll * x * sum[1 - t][i];
			sum[t][i] += 1ll * x * cnt[i];
			up[t][i] += x;
		}
	}
}

int find(int l, int r) {
	update(0, l, r, 0);
	update(1, l, r, 0);
	
	mint ans = 0;
	
	int start = l / sqrt;
	int end = r / sqrt;
	
	for (int i = start; i <= end; i++) {
		if (i == start || i == end) {
			for (int j = i * sqrt; j < (i + 1) * sqrt && j < n; j++) {
				if (j >= l && j <= r) {
					ans += a[0][j] * a[1][j];
				}
//				if (l == 8 && r == 18) {
//					printf("#%d %d %d %d %d\n", i, j, a[0][j], a[1][j], ans);
//				}
			}
		} else {
			ans += sum_mul[i];
//			if (l == 8 && r == 18) {
//				printf("$%d %d %d\n", i, sum_mul[i], ans);
//			}
		}
	}
	
	return ans.val();
}

//int main() {
//	scanf("%d %d", &n, &q);
//	
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &a[0][i]);
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &a[1][i]);
//	}
//	
//	for (int i = 0; i < n; i++) {
//		if (i % sqrt == 0) {
//			sum[0].push_back(0);
//			sum[1].push_back(0);
//			up[0].push_back(0);
//			up[1].push_back(0);
//			sum_mul.push_back(0);
//			cnt.push_back(0);
//		}
//		
//		sum[0].back() += a[0][i];
//		sum[1].back() += a[1][i];
//		sum_mul.back() += a[0][i] * a[1][i];
//		cnt.back()++;
//	}
//	
//	for (int i = 0; i < q; i++) {
//		int t;
//		scanf("%d", &t);
//		if (t == 3) {
//			int l, r;
//			scanf("%d %d", &l, &r);
////			printf("%d\n", find(l - 1, r - 1));
//			ans[0].push_back(find(l - 1, r - 1));
//		} else {
//			int l, r, x;
//			scanf("%d %d %d", &l, &r, &x);
//			update(t - 1, l - 1, r - 1, x);
//		}
//	}
//	
//	return 0;
//}

void solve1() {
	for (int i = 0; i < n; i++) {
		a[0][i] = B[0][i];
	}
	for (int i = 0; i < n; i++) {
		a[1][i] = B[1][i];
	}
	
	for (int i = 0; i < n; i++) {
		if (i % sqrt == 0) {
			sum[0].push_back(0);
			sum[1].push_back(0);
			up[0].push_back(0);
			up[1].push_back(0);
			sum_mul.push_back(0);
			cnt.push_back(0);
		}
		
		sum[0].back() += a[0][i];
		sum[1].back() += a[1][i];
		sum_mul.back() += a[0][i] * a[1][i];
		cnt.back()++;
	}
//	printf("finish step 1\n");
	
	for (int i = 0; i < q; i++) {
		int t = qq[i][0];
		int l = qq[i][1];
		int r = qq[i][2];
//		printf("fxxk %d %d %d %d\n", i, t, l, r);
		if (t == 3) {
			ans[0].push_back(find(l - 1, r - 1));
		} else {
			int x = qq[i][3];
			update(t - 1, l - 1, r - 1, x);
		}
	}
}

void solve2() {
	for (int i = 0; i < n; i++) {
		a[0][i] = B[0][i];
	}
	for (int i = 0; i < n; i++) {
		a[1][i] = B[1][i];
	}
	
	for (int i = 0; i < q; i++) {
		int t = qq[i][0];
		int l = qq[i][1] - 1;
		int r = qq[i][2] - 1;
		if (t == 3) {
			mint temp = 0;
//			printf("! %d %d\n", l, r);
			for (int j = l; j <= r; j++) {
				temp += a[0][j] * a[1][j];
				if (l == 8 && r == 18) {
					printf("@%d %d %d %d\n", j, a[0][j], a[1][j], temp);
				}
			}
			ans[1].push_back(temp.val());
		} else {
			int x = qq[i][3];
			for (int j = l; j <= r; j++) {
				a[t - 1][j] += x;
			}
		}
	}
}



int main() {
	int p;
	scanf("%d", &p);
	if (p == 0) {
		freopen("test.txt", "w", stdout);
		scanf("%d %d", &n, &q);
		printf("%d %d\n", n, q);
		
		for (int i = 0; i < n; i++) {
			B[0][i] = rand() % 10 + 1;
			printf("%d ", B[0][i]);
		}
		printf("\n");
		
		for (int i = 0; i < n; i++) {
			B[1][i] = rand() % 10 + 1;
			printf("%d ", B[1][i]);
		}
		printf("\n");
		
		for (int i = 0; i < q; i++) {
			qq[i][0] = rand() % 3 + 1;
			qq[i][1] = rand() % n + 1;
			while (true) {
				qq[i][2] = rand() % n + 1;
				if (qq[i][2] >= qq[i][1]) {
					break;
				}
			}
			qq[i][3] = rand() % 10 + 1;
			
			if (qq[i][0] == 3) {
				printf("%d %d %d 0\n", qq[i][0], qq[i][1], qq[i][2]);
			} else {
				printf("%d %d %d %d\n", qq[i][0], qq[i][1], qq[i][2], qq[i][3]);
			}
		}
	} else {
		freopen("test.txt", "r", stdin);
		scanf("%d %d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", &B[0][i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &B[1][i]);
		}
		
		for (int i = 0; i < q; i++) {
			int t;
			scanf("%d %d %d %d", &qq[i][0], &qq[i][1], &qq[i][2], &qq[i][3]);
		}
	}
	
	printf("finish read\n");
	
	solve1();
	printf("finish solve 1\n");
	solve2();
	printf("finish solve 2\n");
	
	vector<int> v;
	
	for (int i = 0; i < ans[0].size(); i++) {
		printf("%d %d %d\n", i, ans[0][i], ans[1][i]);
		if (ans[0][i] != ans[1][i]) {
			v.push_back(i);
		}
	}
	
	if (v.size() == 0) {
		printf("SAME\n");
	} else {
		printf("ERROR\n");
		for (auto x: v) {
			printf("%d ", x);
		}
		printf("\n");
	}
	
	return 0;
}