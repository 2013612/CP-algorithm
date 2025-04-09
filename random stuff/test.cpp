#include<iostream>
#include<set>
using namespace std;

int main(){
	set<int> myset;
	char temp[3];
	int val;
	freopen("ops-half.txt", "r", stdin);
	freopen("test.txt", "w", stdout);
	while (scanf("%s %d", temp, &val) != EOF) {
		if (temp[0] == 'i') {
			myset.insert(-val);
		} else {
			printf("%d\n", -*myset.lower_bound(-val));
		}
	}
	return 0;
} 
