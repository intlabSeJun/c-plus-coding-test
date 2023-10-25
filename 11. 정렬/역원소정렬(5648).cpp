#include<iostream>
#include<queue>
#include<string>
#include <algorithm>
using namespace std;

int N;
priority_queue<long long> PQ;


int reverse_value(long long x) {
	string s = to_string(x);
	reverse(s.begin(), s.end());
	int pos=0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0') {
			pos = i;
			break;
		}
	}
	
	s = s.substr(pos);

	x = stoi(s);
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	long long x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		x = reverse_value(x);
		PQ.push(-x);
	}
	
	for (int i = 0; i < N; i++) {
		cout << -PQ.top() << "\n";
		PQ.pop();
	}
}