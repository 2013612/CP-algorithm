#include<bits/stdc++.h>
using namespace std;

int n = 5;
int m = 6;
int a[10];
unordered_map<string, double> um;

struct VectorHasher {
    size_t operator()(const std::vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            seed = seed * 1000 + i;
        }
        return seed;
    }
};

unordered_map<vector<int>, int, VectorHasher> combi[10];

string key(int a, vector<int> &v) {
	string k = "";
	k.push_back('0' + a);
	for (int i = 0; i < n; i++) {
		if (i < v.size()) {
			string p = to_string(v[i]);
			while (p.size() < 3) {
				p = "0" + p;
			}
			k += p;
		} else {
			k += "000";
		}
	}

	return k;
}

void init() {
	combi[0][vector<int>()] = 1;
	for (int i = 0; i < n; i++) {
		for (auto x: combi[i]) {
			for (int k = 0; k < m; k++) {
				vector<int> v = x.first;
				v.push_back(a[k]);
				sort(v.begin(), v.end());
				combi[i + 1][v] += x.second;
			}
		}
	}
}

double cal(int time, vector<int> keep) {
	string str = key(time, keep);
	if (um.count(str)) {
		return um[str];
	}

	int dice = n - keep.size();
	int cnt = 0;

	for (auto x: combi[dice]) {
		cnt += x.second;
	}

	double sum = 0;

	if (time == 1 || dice == 0) {
		for (auto x: combi[dice]) {
			vector<int> t = keep;
			for (int j = 0; j < dice; j++) {
				t.push_back(x.first[j]);	
			}

			sort(t.begin(), t.end());
			t.push_back(0);

			double maxi = 0;
			double p = t[0];
			
			for (int i = 1; i < t.size(); i++) {
				if (t[i] == t[i - 1]) {
					p += t[i];
				} else {
					maxi = max(maxi, p);
					p = t[i];
				}
			}

			sum += maxi * x.second / (double)cnt;
		}
	} else {
		for (auto x: combi[dice]) {
			double maxi = 0;
			for (int j = 0; j < (1 << dice); j++) {
				vector<int> t = keep;
				for (int k = 0; k < dice; k++) {
					if (j & (1 << k)) {
						t.push_back(x.first[k]);
					}
				}

				sort(t.begin(), t.end());
				maxi = max(maxi, cal(time - 1, t));
			}

			sum += maxi * x.second / (double)cnt;
		}
	}

	um[str] = sum;

	return um[str];
}

int main() {
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + m);
	init();

	printf("%.9lf\n", cal(3, vector<int>()));
	
	return 0;
}