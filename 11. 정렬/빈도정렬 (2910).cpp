#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int N, C;
vector<pair<int, int>> V;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
	return a.first > b.first;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		bool chk = false;
		for (auto& a : V) {
			if (a.second == x) {
				chk = true;
				a.first++;
				break;
			}
		}
		if (!chk) V.push_back({ 1,x });
	}
	stable_sort(V.begin(), V.end(), cmp);

	for (auto b : V)
		while (b.first--) cout << b.second << " ";
}