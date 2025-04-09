#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long T;
int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		long long c, h, t;
		long long ans = 0;
		scanf("%lld %lld %lld", &h, &c, &t);
		if (6*t >= 5*h + c || h == c) {
			ans = 1;
		} else if (2*t <= h + c) {
			ans = 2;
		} else if (3*t > 2*h + c) {
			ans = 3;
		} else {
			long long temp = (h - c)/(2*t - h - c);
			if (temp % 2 == 0) {
				temp++;
			}
			long long t1, t2, t3;
			t1 = (temp - 2) * t - (((temp - 1)/2)*h + (temp - 2 - (temp - 1)/2)*c);
			t2 = temp * t - ((temp + 1)/2*h + (temp - (temp + 1)/2)*c);
			t3 = (temp + 2) * t - ((temp + 3)/2*h + (temp + 2 - (temp + 3)/2)*c);
			t1 = t1*temp*(temp + 2);
			t2 = t2*(temp - 2)*(temp + 2);
			t3 = t3*(temp - 2)*temp;
			//cout << t1 << " " << t2 << " " << t3 << endl;
			t1 = abs(t1);
			t2 = abs(t2);
			t3 = abs(t3);
			//cout << t1 << " " << t2 << " " << t3 << endl;
			//cout << temp << endl;
			long long mini = min(t1, min(t2, t3));
			//cout << mini << endl;
			if (t1 == mini) {
				ans = temp - 2;
			} else if (t2 == mini) {
				ans = temp;
			} else {
				ans = temp + 2;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
