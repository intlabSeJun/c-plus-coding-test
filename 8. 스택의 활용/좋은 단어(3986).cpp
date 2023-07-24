//https://www.acmicpc.net/problem/3986
/*
'���� �ܾ�'�� ���Ǹ� �� �����ؾ� ��.
- ��ġ�� ����� ¦�� ���´ٰ� �����Ƿ�, �̿����� �ʴ� ���ڰ� ���� �� '���� �ܾ�'�̴�.

������ �߸� ������.
- ��ġ�� ����� �����ϸ鼭 �������� �ʾƾ� �Ѵ�. 
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