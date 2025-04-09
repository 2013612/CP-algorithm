#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, layer[200006], num[200006], seq[200006];
vector<int> a[200006];
queue<int> c;
bool success = true;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		a[A].push_back(B);
	}
	c.push(1);
	int depth = 1;
	layer[1] = 1;
	num[1] = 1;
	while(c.size() > 0) {
		int x = c.front();
		c.pop();
		for (int i = 0; i < a[x].size(); i++) {
			c.push(a[x][i]);
			layer[a[x][i]] = layer[x] + 1;
			num[layer[a[x][i]]]++;
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}
	int pos = 1;
	for (int i = 0; i < N; i++) {
		if (layer[seq[i]] != pos) {
			success = false;
			break;
		}
		num[pos]--;
		if (num[pos] == 0) {
			pos++;
		}
	}
	if (success) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
