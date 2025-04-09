#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string S;
  getline(cin, S);
  vector<int> stack;
  int N = S.length();
  //cout << string(S) << endl;
  for (int i = 0; i < N; i++) {
  	if (S[i] == ' ') {
  		continue;
  	}
  	/*for (auto a: stack) {
    	cout << a << " ";
    }
    cout << endl;*/
    if (S[i] >= '0' && S[i] <= '9') {
    	int k = S[i] - '0';
    	for (int j = i + 1; j < N; j++) {
    		if (S[j] >= '0' && S[j] <= '9') {
    			k = k*10 + S[j] - '0';
    		} else {
    			i = j;
    			break;
    		}
    	}
      stack.push_back(k);
    } else {
      if (S[i] == '-') {
        if (stack.size() < 2) {
          cout << "invalid" << endl;
          return 0;
        } else {
          int temp1 = stack.back();
          stack.pop_back();
          int temp2 = stack.back();
          stack.pop_back();
          stack.push_back(temp2 - temp1);
        }
      } else if (S[i] == '*') {
        if (stack.size() < 2) {
          cout << "invalid" << endl;
          return 0;
        } else {
          int temp1 = stack.back();
          stack.pop_back();
          int temp2 = stack.back();
          stack.pop_back();
          stack.push_back(temp1 * temp2);
        }
      } else if (S[i] == '@') {
        if (stack.size() < 3) {
          cout << "invalid" << endl;
          return 0;
        } else {
          int temp1 = stack.back();
          stack.pop_back();
          int temp2 = stack.back();
          stack.pop_back();
          int temp3 = stack.back();
          stack.pop_back();
          stack.push_back(temp1 * temp2 + temp2 * temp3 + temp3 * temp1);
        }
      } else {
        if (i != N - 1) {
          if (S[i + 1] == '+') {
            if (stack.empty()) {
              cout << "invalid" << endl;
              return 0;
            } else {
              int temp = stack.back();
              stack.pop_back();
              stack.push_back(temp + 1);
              i++;
            }
          } else {
            if (stack.size() < 2) {
              cout << "invalid" << endl;
              return 0;
            } else {
              int temp1 = stack.back();
              stack.pop_back();
              int temp2 = stack.back();
              stack.pop_back();
              stack.push_back(temp1 + temp2); 
            }
          }
        } else {
          if (stack.size() < 2) {
            cout << "invalid" << endl;
            return 0;
          } else {
            int temp1 = stack.back();
            stack.pop_back();
            int temp2 = stack.back();
            stack.pop_back();
            stack.push_back(temp1 + temp2); 
          }
        }
      }
    }
  }
  if (stack.size() == 1) {
    cout << stack.back() << endl;
  } else {
    cout << "invalid" << endl;
  }
  return 0;
}

