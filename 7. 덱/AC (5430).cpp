//https://www.acmicpc.net/problem/5430
#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	int num1, num2, error;
	cin >> num1;
	int ten = 10;
	int hundred = 100;
	char a;
	for (int i = 0; i < num1; i++) {
		cin >> s1;
		cin >> num2;
		if (num2 == 0) {
			cout << "error" << "\n";
			continue;
		}
		cin >> s2;
		int v=0;
		deque<int> DQ;
		error = 0;
		for (int i = 1; i < s2.size(); i++)
		{
			if (s2[i] == ',' || s2[i] == ']') {
				DQ.push_back(v);
				v = 0;
			}
			else v = 10 * v + (s2[i] - '0');
		}
		/*while(num2 !=0){
			cin >> a;
			if (int(a) >= 48 && int(a) < 58) {
				v.push_back(a - '0');
			}
			else if (a == ',' || a == ']') {
				if (v.size() == 3) {
					v[0] = v[0]*hundred + v[1]*ten + v[2];
				}
				else if (v.size() == 2) v[0] = v[0] * ten + v[1];
				DQ.push_back(v[0]);
				v.clear();
				num2--;
			}
		}*/

		for (char c : s1) {
			if (c == 'R') reverse(DQ.begin(), DQ.end());
			else if (c == 'D') {
				if (DQ.empty()) {
					cout << "error" << "\n";
					error = 1;
					break;
				}
				DQ.pop_front();
			}
		}
		if (error) continue;

		cout << "[";
		int count = 0;
		for (int e : DQ) {
			if (count+1 == (int)DQ.size()) cout << e;
			else cout << e << ",";
			count++;
		}
		cout << "]" << "\n";
	}
}