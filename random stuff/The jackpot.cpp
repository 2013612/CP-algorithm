#include<iostream>
using namespace std;

int N, a[10005];
struct mss{
	int mprefix, msuffix, array_sum, msum;
};

mss max_subarray(int l, int r){
	int mid = (l + r)/2;
	if (l == r){
		return {a[mid], a[mid], a[mid], a[mid]};
	}
	mss ls = max_subarray(l, mid);
	mss rs = max_subarray(mid+1, r);
	mss maximum;
	maximum.array_sum = ls.array_sum + rs.array_sum;
	maximum.msum = max(max(ls.msum, rs.msum), ls.msuffix + rs.mprefix);
	maximum.mprefix = max(ls.mprefix, ls.array_sum + rs.mprefix);
	maximum.msuffix = max(rs.msuffix, ls.msuffix + rs.array_sum);
	return maximum;
}

int main() {
	cin >> N;
	while (N != 0){
		for (int i = 0; i < N; i++){
			cin >> a[i];
		}
		int ans = max_subarray(0, N-1).msum;
		if (ans >= 0){
			cout << "The maximum winning streak is " << ans << "." << endl;
		} else {
			cout << "Losing streak." << endl;
		}
		cin >> N;
	}
	return 0;
}
