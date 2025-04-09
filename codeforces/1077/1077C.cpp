#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, a[300006], ans, maxi, num, maxi2;
int main(){
	scanf("%d", &N);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		if (a[i] > maxi) {
			maxi2 = maxi;
			maxi = a[i];
			num = 1;
		} else if (a[i] == maxi) {
			num++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (a[i] != maxi) {
			maxi2 = max(maxi2, a[i]);
		}
	}
	//cout << maxi << " " << maxi2 << endl;
	if (num > 1) {
		//cout << "!";
		if (sum == maxi*3) {
			printf("%d\n", num);
			for (int i = 0; i < N; i++) {
				if (a[i] == maxi) {
					printf("%d ", i + 1);
				}
			}
		} else {
			printf("0\n");
		}
	} else {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			if (a[i] != maxi) {
				if (sum - a[i] == 2 * maxi) {
					v.push_back(i + 1);
				}
			} else {
				if (sum - a[i] == 2 * maxi2) {
					v.push_back(i + 1);
				}
			}
		}
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
	}
	return 0;
}
