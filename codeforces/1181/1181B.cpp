#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

class BigInteger{
private:
	string s;
	string subtraction(string s1, string s2){
		if (s1 == s2)
			return "0";
		while (s1.length() < s2.length())
			s1 = '0' + s1;
		while (s2.length() < s1.length())
			s2 = '0' + s2;
		s1 = '0' + s1;
		s2 = '0' + s2;
		for (size_t i = 1; i < s1.length(); i++){
			if (s1[i] > s2[i])
				s1[i] = s1[i] - s2[i] + '0';
			else{
				s1[i] = s1[i] + 10 - s2[i] + '0';
				s1[i - 1]--;
			}
		}
		return clearZero(s1);
		return s1;
	}
	void strToInt(int *a, string b){
		int length = b.length();
		for (int i = 0; i < length; i++){
			a[length - i - 1] = b[i] - '0';
		}
	}
	string intToStr(int *a, int length){
		string b;
		for (int i = 0; i < length; i++){
			b = char(a[i] + '0') + b;
		}
		return b;
	}
	string clearZero(string a){
		while (a.size() > 1 && a[0] == '0')
			a.erase(a.begin());
		return a;
	}
	bool Compare(string first, string second){
		first = clearZero(first);
		second = clearZero(second);
		if (first.size() < second.size())
			return false;
		if (first.size() == second.size() && first < second)
			return false;
		return true;
	}
public:
	BigInteger(){
		s = "";
	}
	BigInteger(string a) :s(a){}
	void setInteger(string integer){
		this->s = integer;
	}
 
	string getInteger(){
		return this->s;
	}
 
	BigInteger operator+(const BigInteger& other){
		string s2 = other.s;
		string s1 = this->s;
		while (s1.length() < s2.length())
			s1 = '0' + s1;
		while (s1.length() > s2.length())
			s2 = '0' + s2;
		s1 = '0' + s1;
		s2 = '0' + s2;
 
		for (int i = s1.length() - 1; i > 0; i--){
			s1[i] = s1[i] + s2[i] - '0';
			if (s1[i] > '9'){
				s1[i] -= 10;
				s1[i - 1] += 1;
			}
		}
		return clearZero(s1);
	}
 
	BigInteger operator-(const BigInteger& other){
		string s2 = clearZero(other.s);
		string s1 = clearZero(this->s);
 
		if (s1 == s2)
			return BigInteger("0");
		else if (s1.length() > s2.length()){
			return subtraction(s1, s2);
		}
		else if (s1.length() < s2.length()){
			return '-' + subtraction(s2, s1);
		}
		else if (s1 > s2){
			return subtraction(s1, s2);
		}
		else{
			return '-' + subtraction(s2, s1);
		}
	}
 
	BigInteger operator*(const BigInteger& other){
		string s1 = this->s;
		string s2 = other.s;
		const int MAX = 100;
		int a[MAX]; 
		int b[MAX]; 
		int c[MAX]; 
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		strToInt(a, s1);
		strToInt(b, s2);
		for (int i = 0; i < MAX; i++){ 
			for (int j = 0; j < MAX; j++){
				c[i + j] += (a[i] * b[j]);
			}
		}
		for (int i = 0; i < MAX - 1; i++){
			c[i + 1] += (c[i] / 10);
			c[i] = c[i] % 10;
		}
		return clearZero(intToStr(c, MAX));
	}
 
	BigInteger operator/(const BigInteger& other){
		string first = clearZero(this->s);
		string second = clearZero(other.s);
		if ("0" == second){
			return BigInteger("Error, divisor can no be zero.");
		}
		if (!Compare(first, second))
			return BigInteger("0");
		string result = "", remain = "";
		for (int i = 0; i < first.length(); i++){
			remain += first[i];
			result += '0';
			while (Compare(remain, second)){
				result[result.length() - 1] += 1;
				remain = subtraction(remain, second);
			}
		}
 
		return clearZero(result);
	}
	
	bool operator<(const BigInteger& other) {
		string first = clearZero(this->s);
		string second = clearZero(other.s);
		return first < second;
	}
 
	friend ostream& operator<<(ostream &out, const BigInteger & b){
		out << b.s;
		return out;
	}
	friend istream& operator>>(istream &in, BigInteger &b){
		in >> b.s;
		return in;
	}
};

int N;
string a;
BigInteger  ans;
int main(){
	scanf("%d", &N);
	cin >> a;
	if (N % 2 == 0) {
		string fir = a.substr(0, N/2);
		string sec = a.substr(N/2, N/2);
		if (sec[0] == '0') {
			int temp1 = -1;
			for (int i = N/2 - 1; i >= 0; i--) {
				if (fir[i] != '0') {
					temp1 = i;
					break;
				}
			}
			int temp2 = -1;
			for (int i = 0; i < N/2; i++) {
				if (sec[i] != '0') {
					temp2 = i;
					break;
				}
			}
			if (temp2 == -1) {
				fir = a.substr(0, temp1);
				sec = a.substr(temp1, N - temp1);
				BigInteger tempa(fir), tempb(sec);
				ans = tempa + tempb;
			} else {
				string b, c, d, e;
				b = a.substr(0, N/2 + temp2 + 1);
				c = a.substr(N/2 + temp2 + 1, N - (N/2 + temp2 + 1));
				d = a.substr(0, temp1);
				e = a.substr(temp1, N - temp1);
				BigInteger tempb(b), tempc(c), tempd(d), tempe(e);
				if (tempb + tempc < tempd + tempe) {
					ans = tempb + tempc;
				} else {
					ans = tempd + tempe;
				}
			}
		} else {
			BigInteger temp1(fir);
			BigInteger temp2(sec);
			ans = temp1 + temp2;
		}
	} else {
		if (a[N/2] != '0') {
			string b, c, d, e;
			b = a.substr(0, N/2 + 1);
			c = a.substr(N/2 + 1, N - (N/2 + 1));
			d = a.substr(0, N/2);
			e = a.substr(N/2, N - N/2);
			BigInteger tempb(b), tempc(c), tempd(d), tempe(e);
			if (tempb + tempc < tempd + tempe) {
				ans = tempb + tempc;
			} else {
				ans = tempd + tempe;
			}
		} else if (a[N/2 + 1] != '0') {
			string b, c, d, e;
			b = a.substr(0, N/2 + 1);
			c = a.substr(N/2 + 1, N - (N/2 + 1));
			BigInteger tempb(b), tempc(c);
			ans = tempb + tempc;
		} else {
			string fir = a.substr(0, N/2);
			string sec = a.substr(N/2 + 1, N/2);
			int temp1 = -1;
			for (int i = N/2 - 1; i >= 0; i--) {
				if (fir[i] != '0') {
					temp1 = i;
					break;
				}
			}
			int temp2 = -1;
			for (int i = 0; i < N/2; i++) {
				if (sec[i] != '0') {
					temp2 = i;
					break;
				}
			}
			if (temp2 == -1) {
				fir = a.substr(0, temp1);
				sec = a.substr(temp1, N - temp1);
				BigInteger tempa(fir), tempb(sec);
				ans = tempa + tempb;
			} else {
				string b, c, d, e;
				b = a.substr(0, N/2 + temp2 + 2);
				c = a.substr(N/2 + temp2 + 2, N - (N/2 + temp2 + 2));
				d = a.substr(0, temp1);
				e = a.substr(temp1, N - temp1);
				BigInteger tempb(b), tempc(c), tempd(d), tempe(e);
				if (tempb + tempc < tempd + tempe) {
					ans = tempb + tempc;
				} else {
					ans = tempd + tempe;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
