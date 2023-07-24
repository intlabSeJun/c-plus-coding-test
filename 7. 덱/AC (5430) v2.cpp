//https://www.acmicpc.net/problem/5430
#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string command, arr_values;
	int Test_case_num, arr_num, error;
	cin >> Test_case_num;

	for (int i = 0; i < Test_case_num; i++) {
		cin >> command;
		cin >> arr_num;
		cin >> arr_values;

		if (arr_num == 0 && arr_values == "[]") {
			cout << "error\n";
			continue;
		}
		int v = 0, rev=0;
		deque<int> DQ;
		error = 0;
		for (int i = 1; i < arr_values.length(); i++)
		{
			if (arr_values[i] == ',' || arr_values[i] == ']') {
				DQ.push_back(v);
				v = 0;
			}
			else v = 10 * v + (arr_values[i] - '0');
		}

		for (char c : command) {
			if (c == 'R') rev = 1-rev;
			else if (c == 'D') {
				if (DQ.empty()) {
					cout << "error\n";
					error = 1;
					break;
				}
				if (rev) DQ.pop_back();
				else DQ.pop_front();
			}
		}
		if (error) continue;

		if (rev && !DQ.empty()) reverse(DQ.begin(), DQ.end());

		if (DQ.empty()) cout << "[]";
		else {
			if (DQ.front() == 0) cout << "[]";
			else {
				cout << "[";
				int count = 0;
				for (int e : DQ) {
					if (count + 1 == (int)DQ.size()) cout << e;
					else cout << e << ",";
					count++;
				}
				cout << "]\n";
			}
		}
	}
}