#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long N, x[2], y[2], ans, dis;
char c[200006];

int abs(int x) {
	return x > 0? x: -x;
}

int main(){
	scanf("%lld %lld", &x[0], &y[0]);
	scanf("%lld %lld", &x[1], &y[1]);
	scanf("%d", &N);
	scanf("%s", c);
	long long temp[2];
	temp[0] = x[0];
	temp[1] = y[0];
	dis = abs(x[0] - x[1]) + abs(y[0] - y[1]);
	if (x[0] == x[1] && y[0] == y[1]) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (c[i] == 'U') {
			temp[1]++;
		} else if (c[i] == 'D') {
			temp[1]--;
		} else if (c[i] == 'R') {
			temp[0]++;
		} else {
			temp[0]--;
		}
		long long temp_dis = abs(temp[0] - x[1]) + abs(temp[1] - y[1]);
		if (temp_dis - i < dis) {
			break;
		}
		if (i == N - 1) {
			printf("-1\n");
			return 0;
		}
	}
	temp[0] = x[0];
	temp[1] = y[0];
	for (int i = 0; i < N; i++) {
		if (c[i] == 'U') {
			temp[1]++;
		} else if (c[i] == 'D') {
			temp[1]--;
		} else if (c[i] == 'R') {
			temp[0]++;
		} else {
			temp[0]--;
		}
	}
	long long temp_change_x = abs(x[1] - x[0]) - abs(x[1] - temp[0]);
	long long temp_change_y = abs(y[1] - y[0]) - abs(y[1] - temp[1]); 
	long long periods = dis/(N + temp_change_x + temp_change_y);
	ans += N*periods;
	temp[0] = x[0] + periods*(temp[0] - x[0]);
	temp[1] = y[0] + periods*(temp[1] - y[0]);
	//dis = abs(temp[0] - x[1]) + abs(temp[1] - y[1]);
	//printf("!%d\n", ans);
	for (int i = 0; i < N; i++) {
		long long temp_dis = abs(temp[0] - x[1]) + abs(temp[1] - y[1]);
		//printf("!%d\n", ans);
		//printf("@%d\n", temp_dis);
		if (temp_dis - ans <= 0) {
			printf("%lld\n", ans);
			return 0;
		}
		if (c[i] == 'U') {
			temp[1]++;
		} else if (c[i] == 'D') {
			temp[1]--;
		} else if (c[i] == 'R') {
			temp[0]++;
		} else {
			temp[0]--;
		}
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
