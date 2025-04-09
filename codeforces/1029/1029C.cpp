#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, l[300006], r[300006], L, R, length[300006];
bool rem, fail;
int main(){
	scanf("%d", &N);
	R = 1000000009;
	int mini = 1000000009;
	int position = 0;
	int maxi = 0;
	int ans = 0;
	for (int i = 0; i < min(3, N); i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	if (l[0] >= r[1] || r[0] <= l[1]) {
		if (l[0] >= r[2] || r[0] <= l[2]) {
			L = max(max(L, l[1]), l[2]);
			R = min(min(R, r[1]), r[2]);
			maxi = max(max(maxi, r[1] - l[1]), r[2] - l[2]);
			if (r[1] - l[1] > r[2] - l[2]) {
				mini = r[2] - l[2];
				length[0] = 2;
				position = 1;
			} else if (r[1] - l[1] < r[2] - l[2]) {
				mini = r[1] - l[1];
				length[0] = 1;
				position = 1;
			} else {
				mini = r[1] - l[1];
				length[0] = 1;
				length[1] = 2;
				position = 2;
			}
			rem = true;
		} else if (l[1] >= r[2] || r[1] <= l[2]) {
			L = max(max(L, l[0]), l[2]);
			R = min(min(R, r[0]), r[2]);
			maxi = max(max(maxi, r[0] - l[0]), r[2] - l[2]);
			if (r[0] - l[0] > r[2] - l[2]) {
				mini = r[2] - l[2];
				length[0] = 2;
				position = 1;
			} else if (r[0] - l[0] < r[2] - l[2]) {
				mini = r[0] - l[0];
				length[0] = 0;
				position = 1;
			} else {
				mini = r[0] - l[0];
				length[0] = 0;
				length[1] = 2;
				position = 2;
			}
			rem = true;
		}
		if ((l[0] >= r[2] || r[0] <= l[2]) && (l[1] >= r[2] || r[1] <= l[2])) {
			fail = true;
		}
	} else {
		for (int i = 0; i < min(3, N); i++) {
			if (l[i] >= R || r[i] <= L) {
				if (rem) {
					fail = true;
				} else {
					rem = true;
					continue;
				}
			}
			L = max(L, l[i]);
			R = min(R, r[i]);
			maxi = max(maxi, r[i] - l[i]);
			if (mini > r[i] - l[i]) {
				mini = r[i] - l[i];
				length[0] = i;
				position = 1;
			} else if (mini == r[i] - l[i]) {
				length[position] = i;
				position++;
			}
		}
	}
	for (int i = 3; i < N; i++) {
		scanf("%d %d", &l[i], &r[i]);
		if (l[i] >= R || r[i] <= L) {
			if (rem) {
				fail = true;
			} else {
				rem = true;
				continue;
			}
		}
		L = max(L, l[i]);
		R = min(R, r[i]);
		maxi = max(maxi, r[i] - l[i]);
		if (mini > r[i] - l[i]) {
			mini = r[i] - l[i];
			length[0] = i;
			position = 1;
		} else if (mini == r[i] - l[i]) {
			length[position] = i;
			position++;
		}
	}
	if (!rem) {
		for (int i = 0; i < position; i++) {
			//cout << length[i] << " " << ans << endl;
			int L = 0;
			int R = 1000000009;
			for (int j = 0; j < N; j++) {
				if (j != length[i]) {
					L = max(L, l[j]);
					R = min(R, r[j]);
					if (L >= R) {
						break;
					}
				}
			}
			//cout << "!" << L << " " << R << endl;
			if (L < R) {
				ans = max(ans, R - L);
			}
			if (ans == maxi) {
				break;
			}
		}
	} else {
		ans = R - L;
	}
	if (fail) {
		printf("0\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
