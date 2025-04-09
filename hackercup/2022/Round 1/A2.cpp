#include<iostream>
#include<vector>
using namespace std;

vector<int> pos;

/**************************************
              LPS function
***************************************/          
void lps_func(vector<int> txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.size()){
        if(txt[i]==txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len-1];
                continue;
            }
        }
    }
}
/**************************************
              KMP Function
***************************************/  
void KMP(vector<int> pattern,vector<int> text){
    int n = text.size();
    int m = pattern.size();
    vector<int>Lps(m);
    
    lps_func(pattern,Lps); // This function constructs the Lps array.
    
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} // If there is a match continue.
        if (j == m) { 
        
        	pos.push_back(i - m); // if j==m it is confirmed that we have found the pattern and we output the index
                                  // and update j as Lps of last matched character.
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {  // If there is a mismatch
            if (j == 0)          // if j becomes 0 then simply increment the index i
                i++;
            else
                j = Lps[j - 1];  //Update j as Lps of last matched character
        }
    }
}

int t;
int n, k;
int a[500006], b[500006];

void solve() {
	scanf("%d %d", &n, &k);
	vector<int> temp1, temp2;
	pos.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		temp1.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		temp2.push_back(b[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		temp2.push_back(b[i]);
	}
	KMP(temp1, temp2);
	if (n == 2) {
		if (a[0] != a[1]) {
			if (k % 2 == 0 && a[0] != b[0]) {
				printf("NO\n");
			} else if (k % 2 == 1 && a[0] == b[0]) {
				printf("NO\n");
			} else {
				printf("YES\n");
			}
		} else {
			printf("YES\n");
		}
		return;
	}
	if (k == 0 && !pos.empty()) {
		if (pos[0] == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else if (k == 1 && pos.empty()) {
		printf("YES\n");
	} else if (k == 1 && !pos.empty()) {
		if (pos[0] != 0 || pos.size() > 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else if (!pos.empty()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	freopen("consecutive_cuts_chapter_2_input.txt", "r", stdin);
	freopen("consecutive_cuts_chapter_2_output.txt", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	
	return 0;
}