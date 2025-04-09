#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> lamp;
int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i += 2) {
		lamp.push_back(i);
	}
	int re = 0;
	if (N <= 3) {
		printf("0\n");
		return 0;
	}
	while (re != -1) {
		if (lamp.size() == 1) {
			printf("0\n");
			break;
		}
		printf("2 ");
		printf("%d ", lamp.back());
		lamp.pop_back();
		printf("%d \n", lamp.back());
		lamp.pop_back();
		fflush(stdout);
		scanf("%d", &re);
		if (re % 2 == 0) {
			re++;
		}
		re = re % N;
		lamp.push_back(re);
	}
	int k = lamp.back() + 3;
	k = k % N;
	
	for (int i = k; ; ) {
		if (k == (lamb.back() - 1 + N) % N || k == lamb.back() || k == (lamb.back() + 1 + N) % N) break;
		printf("%d ", k);
		k += 4;
		k = k % N;
	}
	return 0;
}
