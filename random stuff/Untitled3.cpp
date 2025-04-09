#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	vector<int> set;
	int turns;
	cin >> turns;
	int answers[turns];
	int ans[turns];
	int t=0;
	for (int i =0;i<turns;i++){
		answers[i] = -1;
		ans[i] = -1;
		int type;
		cin >> type;
		if (type ==1){
			int New;
			cin >> New;
			set.push_back(New);
		}
		else {
			int x, k, s;
			cin >> x >> k >> s;
			for (int j=0;j<set.size();j++){
				if (gcd(x,set[j])%k==0 && x+set[j]<=s){
					if (answers[t] == -1 || answers[t] < x^set[j]){
						answers[t] = x^set[j];
						ans[t] = set[j];
					}
				}
			}
			t++;
		}
	}
	for (int i=0;i<t;i++){
			cout << ans[i] << endl;
	}
	return 0;
}
