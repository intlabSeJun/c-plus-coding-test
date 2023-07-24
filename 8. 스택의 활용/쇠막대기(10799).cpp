// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<char> st;
	
	int total_count = 0;
	int layzer=1;
	for (char c : s) {
		if (c == '(') {
			st.push(c);
			layzer = 1;
		}
		else {
			st.pop();
			if (layzer) {
				layzer = 0;
				total_count += st.size();
			}
			else total_count += 1;
		}
	}
	cout << total_count;
}