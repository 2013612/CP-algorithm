#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<map>
using namespace std;

int N, M, Start;
vector<pair<int, int>> E[100006], spdist;
bool count[100006];
map<int, int> V;
priority_queue<pair<int, int>> pq;

void find() {
	while(!V.empty()) {
		pair<int, int> k = pq.top();
		pq.pop();
		//cout << k.first << " " << k.second << endl;
		k.first = -k.first;
		if (!count[k.second]) {
			count[k.second] = true;
			for (auto x:E[k.second]) {
				if (!count[x.second]) {
					V[x.second] = min(V[x.second], V[k.second] + x.first);
					pq.push(make_pair(-V[x.second], x.second)); 
				}
			}
			spdist.push_back(make_pair(k.second, V[k.second]));
			V.erase(k.second);
		}
	}
	return;
}

int main() {
	scanf("%d %d %d", &N, &M, &Start);
	for (int i = 0; i < M; i++) {
		int temp1, temp2, temp3;
		scanf("%d %d %d", &temp1, &temp2, &temp3);
		E[temp1].push_back(make_pair(temp3, temp2));
	}
	for (int i = 1; i <= N; i++) {
		if (i != Start) {
			V[i] = 1e9;
		} else {
			V[i] = 0;
		}
		pq.push(make_pair(-V[i], i));
	}
	find();
	for (auto x:spdist) {
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}
