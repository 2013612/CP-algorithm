#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int V, E, a, b, c;
vector<pair<int, int>> edge[100006];
vector<pair<int, pair<int, int>>> usededge;
bool push[100006];
priority_queue<pair<int, pair<int, int>>> mst;

void build_mst() {
	usededge.push_back(make_pair(c, make_pair(a, b)));
	push[a] = push[b] = true;
	for (auto x:edge[a]) {
		if (!push[x.second]) {
			//printf("%d %d %d\n", a, x.second, x.first);
			mst.push(make_pair(-x.first, make_pair(a, x.second)));
		}
	}
	//cout << endl;
	for (auto x:edge[b]) {
		if (!push[x.second]) {
			//printf("%d %d %d\n", b, x.second, x.first);
			mst.push(make_pair(-x.first, make_pair(b, x.second)));
		}
	}
	//cout << endl;
	while(usededge.size() < V - 1) {
		pair<int, pair<int, int>> k = mst.top();
		mst.pop();
		//printf("%d %d %d\n", k.second.first, k.second.second, k.first);
		if (!push[k.second.second]) {
			for (auto x:edge[k.second.second]) {
				if (!push[x.second]) {
					mst.push(make_pair(-x.first, make_pair(k.second.second, x.second)));
				}
			}
			push[k.second.second] = true;
			k.first = -k.first;
			usededge.push_back(k);
		}
		
		//printf("%d %d %d\n", k.second.first, k.second.second, k.first);
	}
	return;
}

int main() {
	scanf("%d %d", &V, &E);
	c = 2e9;
	for (int i = 0; i < E; i++) {
		int temp1, temp2, temp3;
		scanf("%d %d %d", &temp1, &temp2, &temp3);
		edge[temp1].push_back(make_pair(temp3, temp2));
		edge[temp2].push_back(make_pair(temp3, temp1));
		if (temp3 < c) {
			a = temp1;
			b = temp2;
			c = temp3;
		}
	}
	build_mst();
	cout << endl;
	for (auto x:usededge) {
		printf("%d %d %d\n", x.second.first, x.second.second, x.first);
	}
	return 0;
}
