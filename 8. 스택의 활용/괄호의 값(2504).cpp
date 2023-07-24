// https://www.acmicpc.net/problem/2504

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<char> st;
	stack<int> st2;
	int total_count = 0, buf=0;
	int plus_or_multi=0;

	for (char a : s) {
		if (a == '(' || a == '[') {
			st.push(a);
			plus_or_multi = 0;
		}
		else if (a == ')' && st.top() != '[') {
			st.pop();
			if (!plus_or_multi) st2.push(1);
			st2.push(2);
			plus_or_multi = 1;
		}
		else if (a == ']' && st.top() != '(') {

		}
		else {
			total_count = 0;
			break;
		}
	}
	cout << total_count;
}