#include<iostream>
using namespace std;

int n, k, weight, a;
bool stage[26];

int main(){
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%c", &a);
		stage[a - 'a'] = true;
	}
	for (int i = 0; i < 26; i++){
		if (stage[i]){
			if (i == 0 || !stage[i-1]){
				weight += i + 1;
				k--;
			} else {
				stage[i] = false;
			}
		}
		if (k == 0){
			break;
		}
	}
	if (k == 0){
		printf("%d\n", weight);
	} else {
		printf("-1\n");
	}
	return 0;
}
