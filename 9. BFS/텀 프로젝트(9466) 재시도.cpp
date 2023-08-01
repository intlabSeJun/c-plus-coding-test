//https://www.acmicpc.net/problem/9466

#include<iostream>
using namespace std;

int map[100005];
int map_check[100005];

const int Not_visit = 0;
const int Group = -1;

void run(int i) {
	int x = i;
	while (1) {
		if (map_check[x] != Not_visit) {
			while (map_check[x] != Group && map_check[x] == i) {
				map_check[x] = Group;
				x = map[x];
			}
			return;
		}
		map_check[x] = i;
		x = map[x];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	int n;

	while (T--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> map[i];
			map_check[i] = Not_visit;
		}

		int count = 0;
		for (int i = 1; i <= n; i++) if (map_check[i] == Not_visit) run(i);

		for (int i = 1; i <= n; i++) if (map_check[i] != Group) count++;

		cout << count << "\n";
	}
}