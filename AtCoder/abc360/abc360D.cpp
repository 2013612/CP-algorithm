#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

long long n, t, x[200006];
pair<pair<long long, long long>, int> fir[200006], sec[200006];
string s;
set<pair<long long, long long>> front, back;
long long ans;
vector<long long> points;

bool f(pair<pair<long long, long long>, int> a, pair<pair<long long, long long>, int> b) {
	return a.first.second < b.first.second;
}

int main() {
	scanf("%lld %lld", &n, &t);
	t *= 2;
	cin >> s;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
		x[i] *= 2;
		long long st, en;
		if (s[i] == '0') {
			st = x[i] - t;
			en = x[i];
		} else {
			st = x[i];
			en = x[i] + t;
		}
		fir[i] = {{st, en}, s[i] - '0'};
		sec[i] = {{st, en}, s[i] - '0'};
		points.push_back(st);
		points.push_back(en);
	}
	sort(fir, fir + n);
	sort(sec, sec + n, f);
	sort(points.begin(), points.end());
	points.resize(unique(points.begin(), points.end()) - points.begin());
	
	int j = 0;
	int k = 0;
	for (int i = 0; i < points.size(); i++) {
		while (j < n && fir[j].first.first == points[i]) {
			if (!fir[j].second) {
				ans += front.size();
				back.insert(fir[j].first);
			} else {
				ans += back.size();
				front.insert(fir[j].first);
			}
			j++;
		}
		
		while (k < n && sec[k].first.second == points[i]) {
			if (!sec[k].second) {
				back.erase(sec[k].first);
			} else {
				front.erase(sec[k].first);
			}
			k++;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}