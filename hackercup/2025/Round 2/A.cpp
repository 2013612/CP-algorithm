#include<iostream>
using namespace std;

int n, m;

void solve() {
	scanf("%d %d", &n, &m);
	
    if (m > n) {
        printf("NO\n");
        return;
    }

    if (n & 1) {
        if (m - (n - m) < 2) {
            printf("NO\n");
            return;
        }
    }
	

	printf("YES\n");
}

int main() {
	freopen("deciding_points_input.txt", "r", stdin);
	freopen("deciding_points_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}