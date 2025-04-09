#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, K, TEMP;
char c[3004][3004];
vector<int> v;
string ans;

int find_a (int x, int y, int count, int step) {
	if (c[x][y] != 'a' && count == 0) {
		return step;
	} else if (c[x][y] != 'a') {
		return max(find_a (x + 1, y, count - 1, step + 1), find_a (x, y + 1, count - 1, step + 1));
	} else {
		return max(find_a (x + 1, y, count, step + 1), find_a (x, y + 1, count, step + 1));
	}
}

void find (int x, int y, int count, int step) {
	if (step == TEMP) {
		v.push_back(x);
		v.push_back(y);
		return;
	}
	if (c[x][y] != 'a' && count == 0) {
		return;
	} else if (c[x][y] != 'a') {
		find(x + 1, y, count - 1, step + 1);
		find(x, y + 1, count - 1, step + 1);
	} else {
		find(x + 1, y, count, step + 1);
		find(x, y + 1, count, step + 1);
	}
}

string f (int x, int y, string k) {
	if (x == N - 1 && y == N - 1) {
		return k;
	} else if (x == N - 1) {
		return f(x, y + 1, k + c[x][y + 1]);
	} else if (y == N - 1) {
		return f(x + 1, y, k + c[x + 1][y]);
	}
	if (c[x + 1][y] > c[x][y + 1]) {
		k.push_back(c[x][y + 1]);
		return f(x, y + 1, k);
	} else if (c[x + 1][y] < c[x][y + 1]) {
		k.push_back(c[x + 1][y]);
		return f(x + 1, y, k);
	} else {
		return min(f(x, y + 1, k + c[x][y + 1]), f(x + 1, y, k + c[x + 1][y]));
	}
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s", c[i]);
	}
	int temp = find_a(0, 0, K, 1);
	TEMP = temp;
	find(0, 0, K, 1);
	for (int i = 0; i < temp - 1; i++) {
		ans.push_back('a');
	}
	string t;
	t.push_back(c[v[0]][v[1]]);
	string d;
	d.push_back('z' + 1);
	for (int i = 0; i < v.size(); i += 2) {
		t = c[v[i]][v[i + 1]];
		string dd = f(v[i], v[i + 1], t);
		if (dd < d) {
			d = dd;
		}
	}
	printf("%s%s", ans.c_str(), d.c_str());
	return 0;
}
