#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int M = 1e9 + 7;

int n, a[1000006];

void solve() {
	scanf("%d", &n);

	string s;
	cin >> s;

	int cnt_a = 0, cnt_b = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'A') {
			cnt_a++;
		} else {
			cnt_b++;
		}

		if (cnt_a > cnt_b) {
			printf("Alice\n");
			return;
		}
	}

	printf("Bob\n");
}

int main() {
	freopen("crash_course_input.txt", "r", stdin);
	freopen("crash_course_output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}