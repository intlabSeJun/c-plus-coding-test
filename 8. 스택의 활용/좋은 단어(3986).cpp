//https://www.acmicpc.net/problem/3986
/*
'좋은 단어'의 정의를 잘 이해해야 함.
- 아치형 곡선으로 짝을 짓는다고 했으므로, 이웃하지 않는 글자가 같을 때 '좋은 단어'이다.

문제를 잘못 이해함.
- 아치형 곡선으로 연결하면서 교차하지 않아야 한다. 
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	cin.ignore();

	string s;
	
	int count = 0;
	for(int i=0; i<num; i++){
		cin >> s;
		stack<char> st;
		for (char a : s) {
			if (st.empty()) st.push(a);
			else if (st.top() == a) st.pop();
			else st.push(a);
		}
		if (st.empty()) count++;
	}
	cout << count;
}