#include<iostream>
#include<stack>
using namespace std;

bool success = true;
int N;
stack<char> mystack;
int main(){
	cin >> N;
	if (N%2==1){
		success = false;
	}
	else {
		for (int i=0;i<N;i++){
		char a;
		cin >> a;
		if (a == '('||a=='{'||a=='['){
			mystack.push(a);
		}
		else {
			if (mystack.empty()){
				success = false;
				break;
			}
			else {
				if (a==')'&&mystack.top()=='('){
					mystack.pop();
				}
				else if (a=='}'&&mystack.top()=='{'){
					mystack.pop();
				}
				else if (a==']'&&mystack.top()=='['){
					mystack.pop();
				}
				else {;
					success = false;
					break;
				}
			}
		}
	}
	}
	if (success == false || !mystack.empty()){
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	return 0;
}
