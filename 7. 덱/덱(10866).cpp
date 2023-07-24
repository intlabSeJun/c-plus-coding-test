//https://www.acmicpc.net/problem/10866
 // 1. STL<deque>를 이용한 구현
#include<iostream>
#include<deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;  
	cin >> num;

	string s;

	deque<int> dat;
	int x;

	for (int i = 0; i < num; i++) {
		cin >> s;
		if (s == "push_front") {
			cin >> x;
			dat.push_front(x);
		}
		else if (s == "push_back") {
			cin >> x;
			dat.push_back(x);
		}
		else if (s == "pop_front") {
			if (dat.size() == 0) cout << -1 << "\n";
			else {
				cout << dat.front() << "\n";
				dat.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dat.size() == 0) cout << -1 << "\n";
			else {
				cout << dat.back() << "\n";
				dat.pop_back();
			}
		}
		else if (s == "size") cout << dat.size() << "\n";
		else if (s == "empty") {
			if (dat.size() == 0) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (dat.size() == 0) cout << -1 << "\n";
			else cout << dat.front() << "\n";
		}
		else if (s == "back") {
			if (dat.size() == 0) cout << -1 << "\n";
			else cout << dat.back() << "\n";
		}
	}
}

// 2. 배열을 이용한 구현
#include<iostream>
#include<string>
using namespace std;

const int MX = 100005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;

	string s;
	int x;

	for (int i = 0; i < num; i++) {
		cin >> s;
		if (s == "push_front") {
			cin >> x;
			dat[--head] = x;
		}
		else if (s == "push_back") {
			cin >> x;
			dat[tail++] = x;
		}
		else if (s == "pop_front") {
			if (head == tail) cout << -1 << "\n";
			else cout << dat[head++] << "\n";

		}
		else if (s == "pop_back") {
			if (head == tail) cout << -1 << "\n";
			else cout << dat[--tail] << "\n";
		}
		else if (s == "size") cout << tail-head << "\n";
		else if (s == "empty") {
			if (head == tail) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "front") {
			if (head == tail) cout << -1 << "\n";
			else cout << dat[head] << "\n";
		}
		else if (s == "back") {
			if (head == tail) cout << -1 << "\n";
			else cout << dat[tail-1] << "\n";
		}
	}
}