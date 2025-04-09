#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, K, a[300006], ans;

bool bin(int x) {
	int count = 0;
	for (int i = 1; i < 200006; i++) {
		if (a[i] >= x) {
			count += a[i]/x;
		}
	}
	return count >= K;
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
	}
	int l = 0;
	int r = 300006;
	while (r - l > 1) {
		//cout << l << " " << r << endl;
		int mid = (l + r) / 2;
		if (bin(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	//cout << l << " " << r << endl;
	if (l == r) {
		for (int i = 1; i < 200006; i++) {
			if (a[i] >= l) {
				int t = a[i]/l;
				for (int j = 0; j < t; j++) {
					if (K == 0) {
						break;
					}
					printf("%d ", i);
					K--;
				}
			}
		}
	} else {
		if (l > r) {
			int p = l;
			l = r;
			r = p;
		}
		if (bin(r)) {
			//cout << "!" << endl;
			for (int i = 1; i < 200006; i++) {
				if (a[i] >= r) {
					int t = a[i]/r;
					for (int j = 0; j < t; j++) {
						if (K == 0) {
							break;
						}
						printf("%d ", i);
						K--;
					}
				}
			}
		} else {
			//cout << "@" << endl;
			for (int i = 1; i < 200006; i++) {
				if (a[i] >= l) {
					int t = a[i]/l;
					for (int j = 0; j < t; j++) {
						if (K == 0) {
							break;
						}
						printf("%d ", i);
						K--;
					}
				}
			}
		}
	}
	return 0;
}
