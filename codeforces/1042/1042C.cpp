#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[200006], neg, max_neg[2];
vector<int> zero;
int main() {
	scanf("%d", &N);
	max_neg[0] = -2e9;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			zero.push_back(i + 1);
		} else if (a[i] < 0) {
			neg++;
			if (max_neg[0] < a[i]) {
				max_neg[0] = a[i];
				max_neg[1] = i + 1;
			}
		}
	}
	if (zero.size() > 0) {
		for (int i = 1; i < zero.size(); i++) {
			printf("1 %d %d\n", zero[i - 1], zero[i]);
		}
		if (neg % 2 == 1) {
			printf("1 %d %d\n", max_neg[1], zero.back());
		}
		if (zero.size() == N || (zero.size() == N - 1 && neg == 1)) {
			return 0;
		}
		printf("2 %d\n", zero.back());
	} else {
		if (neg % 2 == 1) {
			printf("2 %d\n", max_neg[1]);
		}
	}
	for (int i = 1; i < N; i++) {
		if ((neg % 2 == 1 && i == max_neg[1]) || (zero.size() > 0 && binary_search(zero.begin(), zero.end(), i))) continue;
		if ((neg % 2 == 1 && i + 1 == max_neg[1]) || (zero.size() > 0 && binary_search(zero.begin(), zero.end(), i + 1))) {
			int temp = i + 2;
			while((neg % 2 == 1 && temp == max_neg[1]) || (zero.size() > 0 && binary_search(zero.begin(), zero.end(), temp))) {
				temp++;
			}
			if (temp > N) break;
			printf("1 %d %d\n", i, temp);
			i = temp - 1;
		} else {
			printf("1 %d %d\n", i, i + 1);
		}
	}
	return 0;
} 
