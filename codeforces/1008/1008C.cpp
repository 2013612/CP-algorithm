#include<iostream>
#include<algorithm>
using namespace std;

int n, a[100006];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int num_of_e_left = n - 1;
	int num_of_rep = 1;
	int ans = 0;
	for (int i = 1; i < n; i++){
		if (a[i] == a[i-1]){
			num_of_rep++;
			num_of_e_left--;
			printf("!%d %d\n", num_of_rep, num_of_e_left);
		} else {
			if (num_of_e_left > num_of_rep) {
				printf("@%d %d\n", num_of_rep, num_of_e_left);
				ans += num_of_rep;
				num_of_e_left = n - i;
				num_of_rep = 1;
				printf("@%d %d %d\n", i, num_of_e_left, ans);
			} else {
				ans += num_of_e_left;
				printf("%d", ans);
				return 0;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
