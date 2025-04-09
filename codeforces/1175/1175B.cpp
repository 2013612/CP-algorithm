#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, b[100006], c[100006];
string a[100006];
long long ans, MAX;
vector<int> num;

long long foo(int x, int y, long long z) {
	//cout << x << " " << y << " " << z << endl;
	if (z >= MAX) {
		return -1;
	}
	if (a[x][0] == 'a') {
		z++;
		foo(x + 1, y, z);
	} else if (a[x][0] == 'f') {
		z += foo(x + 1, b[x], 0);
		foo(c[x] + 1, y, z);
	} else {
		//cout << 1ll*y*z << endl;
		return 1ll*y*z;
	}
}

int main(){
	scanf("%d", &N);
	MAX = 1;
	for (int i = 0; i < 32; i++) {
		MAX *= 2;
	}
	for (int i = 0; i < N; i++) {
		//cout << i << endl;
		cin >> a[i];
		if (a[i][0] == 'f') {
			cin >> b[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (a[i][0] == 'f') {
			num.push_back(i);
		} else if (a[i][0] == 'e') {
			c[num.back()] = i;
			num.pop_back();
		}
	}
	for (int i = 0; i < N; i++) {
		if (a[i][0] == 'a') {
			ans++;
		} else if (a[i][0] == 'f') {
			long long temp = 0;
			temp = foo(i + 1, b[i], 0);
			if (temp == -1) {
				printf("OVERFLOW!!!\n");
				return 0;
			}
			ans += temp;
			i = c[i];
		}
		if (ans >= MAX) {
			printf("OVERFLOW!!!\n");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
} 
