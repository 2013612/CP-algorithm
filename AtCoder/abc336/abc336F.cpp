#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

int x[4] = {0, 0, 1, 1};
int y[4] = {0, 1, 0, 1};
int h, w, s[10][10], order[100];
string start, target;
unordered_set<string> front[11], back[11];

string rotate(string s, int x, int y) {
	string t = s;
	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w - 1; j++) {
			t[(i + x) * w + j + y] = s[(h - 1 - (i + 1) + x) * w + w - 1 - (j + 1) + y];
		}
	}
	return t;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &s[i][j]);
			target.push_back(i * w + j);
			order[i * w + j] = s[i][j];
		}
	}
	sort(order, order + h * w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int ind = lower_bound(order, order + h * w, s[i][j]) - order;
			start.push_back(ind);
		}
	}
	
	if (start == target) {
		printf("0\n");
		return 0;
	}
	
	front[0].insert(start);
	for (int i = 1; i <= 10; i++) {
		for (string t: front[i - 1]) {
			for (int j = 0; j < 4; j++) {
				string trans = rotate(t, x[j], y[j]);
				if (trans == target) {
					printf("%d\n", i);
					return 0;
				}
				front[i].insert(trans);
			}
		}
	}
	
	back[0].insert(target);
	
	for (int i = 1; i <= 10; i++) {
		for (string t: back[i - 1]) {
			for (int j = 0; j < 4; j++) {
				string trans = rotate(t, x[j], y[j]);
				if (front[10].count(trans)) {
					printf("%d\n", i + 10);
					return 0;
				}
				back[i].insert(trans);
			}
		}
	}
	
	printf("-1\n");
	
	return 0;
}