#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

int n, ans, a[200006], cnt;
unordered_set<int> us;
queue<int> q;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			while (us.count(a[i])) {
				us.erase(q.front());
				q.pop();
			}
			
			us.insert(a[i]);
			q.push(a[i]);
			i++;
		} else {
			us.clear();
			q = queue<int>();
			
			if (i != 0 && a[i] == a[i - 1]) {
				q.push(a[i]);
				us.insert(a[i]);
			}
		}
		
		ans = max(ans, (int)us.size() * 2);
	}
	
	printf("%d\n", ans);
	
	return 0;
}