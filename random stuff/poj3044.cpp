#include<cstdio>
#include<stack>
using namespace std;

int N, W, ans;
stack<int> con;
int main() {
	scanf("%d %d", &N, &W);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (con.empty() || con.top() < b) {
			if (b != 0) {
				con.push(b);
			}
		} else {
			while (!con.empty() && con.top() > b) {
				con.pop();
				ans++;
			}
			if (b != 0 && (con.empty() || con.top() != b)) {
				con.push(b);
			}
		}
	}
	
	printf("%d\n", ans + con.size());
	return 0;
}
