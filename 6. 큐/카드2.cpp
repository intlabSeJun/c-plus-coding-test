//https://www.acmicpc.net/problem/2164

#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;

	queue<int> Q; 
	for (int i = 0; i < num; i++) Q.push(i + 1);

	while (Q.size() != 1) {
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}
	cout << Q.front();
}