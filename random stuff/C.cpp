#include<cstdio>
#include<deque>
#include<vector>

int t, r, c, w;
char grid[102][102];
char tmp[5003];
int ct[102][102];
std::vector<int> hor[102][102], ver[102][102];

struct hash {
	int hash1, hash2;
	int l, lm1, lm2;
	std::deque<char> s;
	static const int m1 = 67458917, m2 = 67458947;
	bool operator == (const hash& H) const {
		return hash1 == H.hash1 && hash2 == H.hash2 && s.size() == H.s.size();
	}
	bool operator += (const char& n) {
		hash1 = (1ll * hash1 * 27 + n - 'A') % m1;
		hash2 = (1ll * hash2 * 27 + n - 'A') % m2;
		if (s.size() == l) {
			hash1 = ((hash1 - 1ll * (s.front() - 'A') * lm1) % m1 + m1) % m1;
			hash2 = ((hash2 - 1ll * (s.front() - 'A') * lm2) % m2 + m2) % m2;
			s.pop_front();
		}
		s.push_back(n);
	}
	hash(int x, int y, int z) {
		hash1 = hash2 = 0;
		s.clear();
		l = x;
		lm1 = y;
		lm2 = z;
	}
	hash() {}
} h[3];

struct frac {
	int x, y;
	int gcd(int a, int b) {
		if (a % b == 0) {
			return b;
		} else {
			return gcd(b, a % b);
		}
	}
	frac(int a, int b) {
		int c = gcd(a, b);
		x = a / c;
		y = b / c;
	}
	bool operator == (const frac& F) const {
		return x == F.x && y == F.y;
	}
	bool operator < (const frac& F) const {
		return 1ll * x * F.y < 1ll * y * F.x;
	}
};

void solve(int i) {
	scanf("%d %d %d", &r, &c, &w);
	for (int i = 0; i < r; i++) {
		scanf("%s", grid[i]);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			hor[i][j].clear();
			ver[i][j].clear();
		}
	}
	for (int i = 0; i < w; i++) {
		scanf("%s", tmp);
		int l, lm1 = 1, lm2 = 1;
		for (l = 0; tmp[l]; l++) {
			lm1 = 1ll * lm1 * 27 % hash::m1;
			lm2 = 1ll * lm2 * 27 % hash::m2;
		}
		h[0] = hash(l, lm1, lm2);
		h[1] = hash(l, lm1, lm2);
		for (int j = 0; j < l; j++) {
			h[0] += tmp[j];
			h[1] += tmp[l - j - 1];
		}
		for (int j = 0; j < r; j++) {
			h[2] = hash(l, lm1, lm2);
			for (int k = 0; k < c; k++) {
				h[2] += grid[j][k];
				if (h[0] == h[2]) {
					hor[j][k - l + 1].push_back(l);
				}
				if (h[1] == h[2]) {
					hor[j][k - l + 1].push_back(l);
				}
			}
		}
		for (int k = 0; k < c; k++) {
			h[2] = hash(l, lm1, lm2);
			for (int j = 0; j < r; j++) {
				h[2] += grid[j][k];
				if (h[0] == h[2]) {
					ver[j - l + 1][k].push_back(l);
				}
				if (h[1] == h[2]) {
					ver[j - l + 1][k].push_back(l);
				}
			}
		}
	}
	frac ans1 = frac(0, 1);
	int ans2 = 0;
	for (int x1 = 0; x1 < r; x1++) {
		for (int y1 = 0; y1 < c; y1++) {
			for (int x2 = x1; x2 < r; x2++) {
				for (int y2 = y1; y2 < c; y2++) {
					ct[x2][y2] = 0;
				}
			}
			for (int x2 = x1; x2 < r; x2++) {
				for (int y2 = y1; y2 < c; y2++) {
					for (auto l: hor[x2][y2]) {
						ct[x2][y2 + l - 1] += l;
					}
					for (auto l: ver[x2][y2]) {
						ct[x2 + l - 1][y2] += l;
					}
				}
			}
			for (int x2 = x1; x2 < r; x2++) {
				for (int y2 = y1 + 1; y2 < c; y2++) {
					ct[x2][y2] += ct[x2][y2 - 1];
				}
			}
			for (int x2 = x1 + 1; x2 < r; x2++) {
				for (int y2 = y1; y2 < c; y2++) {
					ct[x2][y2] += ct[x2 - 1][y2];
				}
			}
			for (int x2 = x1; x2 < r; x2++) {
				for (int y2 = y1; y2 < c; y2++) {
					frac tt = frac(ct[x2][y2], x2 - x1 + 1 + y2 - y1 + 1);
					if (ans1 < tt) {
						ans1 = tt;
						ans2 = 1;
					} else if (ans1 == tt) {
						ans2++;
					}
				}
			}
		}
	}
	printf("Case #%d: %d/%d %d\n", i, ans1.x, ans1.y, ans2);
}

int main() {
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}
