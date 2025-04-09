#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

long long a, b, ans, ten[20];
int m;
map<int, int> m_std[10][10], m_rev[10][10];
set<long long> l[10], r[10];
unordered_map<int, int> um[20][10][2];

void count(string s) {
	if (s.size() > 8) {
		return;
	}
	
	int start;
	
	if (s.size() == 0) {
		start = 1;
	} else {
		start = s.back() - '0';
	}
	
	for (int i = start; i <= 8; i++) {
		string t = s;
		t.push_back('0' + i);
		count(t);
	}
	
	int si = s.size();
	
	if (si == 0) {
		return;
	}
	
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	
	l[si].insert(stoll(s));
	r[si].insert(stoll(reversed));
	
	int t = stoll(s) % m;
	t = 1ll * t * ten[si + 1] % m;
	m_std[si][s.back() - '0'][t]++;
	int t2 = stoll(reversed) % m;
	m_rev[si][s.back() - '0'][t2]++;
}

long long count_complete(int mid, int len) {
	long long cnt = 0;
	long long t = 1ll * mid * ten[len] % m;
	for (int i = 1; i < mid; i++) {
		for (auto [x, y]: m_rev[len][i]) {
			for (int j = 1; j < mid; j++) {
				cnt += 1ll * y * m_std[len][j][(2 * m - x - t) % m];
			}
		}
	}
	
	return cnt;
}

long long find_x(string t) {
	long long cnt = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 2; k++) {
				um[i][j][k].clear();
			}
		}
	}
	int t_size = t.size();
	
	long long maxi = 0;
	int maxi_len = t_size / 2;
	
	if (t_size == 1) {
		for (int i = 1; i <= stoi(t); i++) {
			if (i % m == 0) {
				cnt++;
			}
		}
	} else if (t_size == 2) {
		for (int i = 1; i <= 9; i++) {
			if (i % m == 0) {
				cnt++;
			}
		}
	} else {
		if (t_size & 1) {
			maxi = stoll(t.substr(0, maxi_len));
		}
	
		for (int i = 1; i <= 9; i++) {
			if (i % m == 0) {
				cnt++;
			}
		}
		
		for (int i = 2; i <= 9; i++) {
			for (int j = 1; j < maxi_len; j++) {
				cnt += count_complete(i, j);
			}
		}
		
		if (t_size & 1) {
			int fd = t.front() - '0';
			for (int i = 1; i < fd; i++) {
				um[1][i][0][i % m]++;
			}
			um[1][fd][1][fd % m]++;
			
			for (int i = 2; i <= maxi_len; i++) {
				for (int j = 1; j <= 9; j++) {
					for (auto [x, y]: um[i - 1][j][0]) {
						for (int k = j; k <= 9; k++) {
							um[i][k][0][(1ll * x * 10 + k) % m] += y;
						}
					}
					
					for (auto [x, y]: um[i - 1][j][1]) {
						int d = t[i - 1] - '0';
						for (int k = j; k <= d; k++) {
							if (k < d) {
								um[i][k][0][(1ll * x * 10 + k) % m] += y;
							} else if (k == d) {
								um[i][k][1][(1ll * x * 10 + k) % m] += y;
							}
						}
					}
				}
			}
			
			for (int j = 1; j <= 9; j++) {
				for (auto [x, y]: um[maxi_len][j][0]) {
					for (int k = j + 1; k <= 9; k++) {
						um[maxi_len + 1][k][0][(1ll * x * 10 + k) % m] += y;
					}
				}
				
				for (auto [x, y]: um[maxi_len][j][1]) {
					int d = t[maxi_len] - '0';
					for (int k = j + 1; k <= d; k++) {
						if (k < d) {
							um[maxi_len + 1][k][0][(1ll * x * 10 + k) % m] += y;
						} else if (k == d) {
							um[maxi_len + 1][k][1][(1ll * x * 10 + k) % m] += y;
						}
					}
				}
			}
			
			for (int j = 1; j <= 9; j++) {
				for (auto [x, y]: um[maxi_len + 1][j][0]) {
					for (int k = j - 1; k >= 1; k--) {
						um[maxi_len + 2][k][0][(1ll * x * 10 + k) % m] += y;
					}
				}
				
				for (auto [x, y]: um[maxi_len + 1][j][1]) {
					for (int k = j - 1; k >= 1; k--) {
						int d = t[maxi_len + 1] - '0';
						if (k < d) {
							um[maxi_len + 2][k][0][(1ll * x * 10 + k) % m] += y;
						} else if (k == d) {
							um[maxi_len + 2][k][1][(1ll * x * 10 + k) % m] += y;
						}
					}
				}
			}
			
			for (int i = maxi_len + 3; i <= t_size; i++) {
				for (int j = 1; j <= 9; j++) {
					for (auto [x, y]: um[i - 1][j][0]) {
						for (int k = j; k >= 1; k--) {
							um[i][k][0][(1ll * x * 10 + k) % m] += y;
						}
					}
					
					for (auto [x, y]: um[i - 1][j][1]) {
						for (int k = j; k >= 1; k--) {
							int d = t[i - 1] - '0';
							if (k < d) {
								um[i][k][0][(1ll * x * 10 + k) % m] += y;
							} else if (k == d) {
								um[i][k][1][(1ll * x * 10 + k) % m] += y;
							}
						}
					}
				}
			}
			
			for (int i = 1; i <= 9; i++) {
				for (int j = 0; j <= 1; j++) {
					cnt += um[t_size][i][j][0];
				}
			}
		}
	}
	
	return cnt;
}


void solve() {
	scanf("%lld %lld %d", &a, &b, &m);
	ten[0] = 1;
	for (int i = 1; i <= 10; i++) {
		ten[i] = (ten[i - 1] * 10) % m;
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			m_std[i][j].clear();
			m_rev[i][j].clear();
			l[i].clear();
			r[i].clear();
		}
	}
	count("");
	ans = 0;
	
	string t = to_string(b);
	ans += find_x(t);
	
	if (a > 1) {
		t = to_string(a - 1);
		ans -= find_x(t);
	}

	printf("%lld\n", ans);
}

int main() {
	freopen("cottontail_climb_part_2_input.txt", "r", stdin);
	freopen("cottontail_climb_part_2_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}