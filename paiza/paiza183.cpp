#include<iostream>
#include<string>
using namespace std;

string find(long long size, long long l, long long r) {
	if (l > r) {
		return "";
	}
	if (size == 1) {
		string str = "ABC";
		string ret = "";
		for (int i = l; i <= r; i++) {
			ret += str[i];
		}
		return ret;
	}
	long long mid = 3 * ((1 << (size - 1)) - 1);
	string ans = "";
	if (l == 0){
		ans = "A";
		l++;
	}
	if (r <= mid) {
		ans += find(size - 1, l - 1, r - 1);
	} else {
		if (l <= mid) {
			ans += find(size - 1, l - 1, mid - 1);
			ans += "B";
			if (r == 2 * mid + 2) {
				ans += find(size - 1, 0, mid - 1) + "C";
			} else {
				ans += find(size - 1, 0, r - mid - 2);
			}
		} else {
			if (l == mid + 1) {
				ans += "B";
				l++;
			}
			if (r == 2 * mid + 2) {
				ans += find(size - 1, l - mid - 2, mid - 1) + "C";
			} else {
				ans += find(size - 1, l - mid - 2, r - mid - 2);
			}
		}		
	}
	return ans;
}

int main() {
	long long k, s, t;
	scanf("%lld %lld %lld", &k, &s, &t);
	cout << find(k, s - 1, t - 1) << endl;
}
