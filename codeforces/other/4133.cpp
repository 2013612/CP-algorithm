#include<iostream>
#include<algorithm>

int N, a[100006]; 

long long inv(int l, int r){
	int mid = (l+r)/2;
	if (l == r){
		return 0;
	}
	long long left = inv(l, mid);
	long long right = inv(mid+1, r);
	long long num = 0;
	for (int i = l, j = mid + 1; i <= mid;){
		if (j > r){
			num += (mid - i + 1)*(r - mid);
			break;
		}
		if (a[i] > a[j]){
			j++;
		} else {
			num += j - mid -1;
			i++;
		}
	}
	num += left + right;
	std::inplace_merge(a + l, a + mid + 1, a + r + 1);
	return num;
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	printf("%lld\n", inv(0,N-1));
}
