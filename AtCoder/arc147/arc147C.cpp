#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

int n;
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;
pii a[300006];

void insert(int x) {
	if (l.size() == 0) {
		l.push(x);
	} else if (r.size() == 0) {
		r.push(x);
	} else {
		if (x < r.top()) {
			l.push(x);
		} else {
			r.push(x);
		}
	}
	
	if (l.size() > 1 + r.size()) {
		r.push(l.top());
		l.pop();
	} else if (r.size() > 1 + l.size()) {
		l.push(r.top());
		r.pop();
	}
}

bool f(pii a, pii b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second < b.second;
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	int t1, t2;
    	scanf("%d %d", &t1, &t2);
    	a[i] = {t1, t2};
	}
	sort(a, a + n, f);
	
	insert(a[0].second);
	for (int i = 1; i < n; i++) {
		if ((i + 1) & 1) {
			int m1 = l.top();
			int m2 = r.top();
			
			if (a[i].first <= m1) {
				insert(m1);
			} else {
				insert(a[i].first);
			}
		} else {
			int m1;
			if (l.size() > r.size()) {
				m1 = l.top();
			} else {
				m1 = r.top();
			}
			
			if (a[i].first <= m1) {
				insert(m1);
			} else {
				insert(a[i].first);
			}
		}
	}
	vector<int> v;
	while (!l.empty()) {
		v.push_back(l.top());
		l.pop();
	}
	while (!r.empty()) {
		v.push_back(r.top());
		r.pop();
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	long long diff = 0;
	for (int i = 1; i < v.size(); i++) {
		diff += (v[i] - v[i - 1]) * i;
		ans += diff;
	}
	
	printf("%lld\n", ans);
    return 0;
}