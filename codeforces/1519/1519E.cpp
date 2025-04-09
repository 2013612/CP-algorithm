#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
#include<vector>
using namespace std;

typedef pair<pair<pair<int, int>, pair<int, int>>, int> point;
typedef pair<pair<int, int>, pair<int, int>> point_no_index;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

bool f(point p, point q) {
	point_no_index a = p.first;
	point_no_index b = q.first;
	__int128 temp1 = a.first.first;
	temp1 = temp1 * a.second.second;
	temp1 = temp1 * b.first.second;
	temp1 = temp1 * b.second.first;
	__int128 temp2 = b.first.first;
	temp2 = temp2 * b.second.second;
	temp2 = temp2 * a.first.second;
	temp2 = temp2 * a.second.first;
	return temp1 > temp2;
}

int N;
point a[200006];
bool used[200006];
map<point_no_index, vector<int>> check;
vector<pair<int, int>> ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
		int temp = gcd(x1, x2);
		x1 /= temp;
		x2 /= temp;
		temp = gcd(y1, y2);
		y1 /= temp;
		y2 /= temp;
		point_no_index b = make_pair(make_pair(x1, x2), make_pair(y1, y2));
		a[i] = make_pair(b, i + 1);
		b.first.first += b.first.second;
		if (check.count(b) == 0) {
			check[b] = vector<int>(1, i + 1);
		} else {
			check[b].push_back(i + 1);
		}
		b = a[i].first;
		b.second.first += b.second.second;
		if (check.count(b) == 0) {
			check[b] = vector<int>(1, i + 1);
		} else {
			check[b].push_back(i + 1);
		}
	}
	//cout << endl;
	sort(a, a + N, f);
//	for (int i = 0; i < N; i++) {
//		point_no_index temp = a[i].first;
//		printf("%d %d %d %d\n", temp.first.first, temp.first.second, temp.second.first, temp.second.second);
//	}
//	cout << endl;
	for (int i = 0; i < N; i++) {
		if (used[i + 1]) {
			continue;
		}
		point_no_index temp = a[i].first;
		temp.first.first += temp.first.second;
		while (check[temp].size() > 0) {
			int k = check[temp].back();
			check[temp].pop_back();
			if (!used[k] && k != a[i].second) {
				//printf("%d %d %d %d\n", temp.first.first, temp.first.second, temp.second.first, temp.second.second);
				ans.push_back(make_pair(a[i].second, k));
				used[k] = true;
				used[a[i].second] = true;
				break;
			}
		}
		check[temp].push_back(a[i].second);
	}
	
	printf("%d\n", ans.size());
	for (auto x:ans) {
		printf("%d %d\n", x.first, x.second);
	}
	return 0;
}
