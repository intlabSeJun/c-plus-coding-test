// https://www.acmicpc.net/problem/18258
#include<iostream>
#include<string>
#include<queue>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long num;
	cin >> num;
	queue<long long> Q;
	string s;
	long long x;
	for (int i = 0; i < num; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			Q.push(x);
		}
		else if (s == "pop") {
			if (Q.empty()) cout << -1 << "\n";
			else {
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if (s == "size") cout << Q.size() << "\n";
		else if (s == "empty") {
			if (Q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (Q.empty()) cout << -1 << "\n";
			else cout << Q.front() << "\n";
		}
		else if (s == "back") {
			if (Q.empty()) cout << -1 << "\n";
			else cout << Q.back() << "\n";
		}
	}
}