//https://www.acmicpc.net/problem/4949
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;

	while (1) {
		getline(cin, s);
		if (s[0] == '.') break;

		stack<char> st;
		for (char a : s) {
			if (a == '(' || a=='[') st.push(a);
			else if (a == ')')
			{
				if (st.empty() || st.top()=='[') {
					cout << "no" << "\n";
					break;
				}
				st.pop();
			}
			else if (a == ']')
			{
				if (st.empty() || st.top() =='(') {
					cout << "no" << "\n";
					break;
				}
				st.pop();
			}
			else if (a == '.') {
				if (st.empty()) cout << "yes" << "\n";
				else cout << "no\n";  // st에 '(' or '['만 들어있을 경우, 즉, 닫히지 않았을 경우
			}
		}
	}
}