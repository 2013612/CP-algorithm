#include<iostream>
#include<vector>
using namespace std;

int n, x, t[1000007];
int LIS(int s[]){
    vector<int> v;
    v.push_back(s[0]);
    for (int i = 1; i < n; i++)
    {
        int temp = s[i];
        if (temp > v.back()) {
        	v.push_back(temp);
        } else {
        	*lower_bound(v.begin(), v.end(), temp) = temp;
        }
    }
    return v.size();
}

int main(){
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	printf("%d\n", LIS(t));
	return 0;
}
