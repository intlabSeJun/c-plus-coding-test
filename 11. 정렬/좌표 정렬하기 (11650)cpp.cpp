#include<iostream>
using namespace std;

int N;

struct coord {
	int x;
	int y;
};

coord coordinate[100005];
coord tmp[100005];

void merge_sort(int st, int en) {
	if (st + 1 == en) return;

	int mid = (st + en) / 2;

	merge_sort(st, mid);
	merge_sort(mid, en);

	int L = st;
	int R = mid;

	for (int i = st; i < en; i++) {
		if (L == mid) tmp[i] = coordinate[R++];
		else if (R == en) tmp[i] = coordinate[L++];
		else if (coordinate[L].y < coordinate[R].y) tmp[i] = coordinate[L++];
		else if (coordinate[L].y > coordinate[R].y) tmp[i] = coordinate[R++];
		else { // x좌표 동일시 수행
			if(coordinate[L].x <= coordinate[R].x) tmp[i] = coordinate[L++];
			else tmp[i] = coordinate[R++];
		}
	}

	for (int i = st; i < en; i++) coordinate[i] = tmp[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> coordinate[i].x >> coordinate[i].y;

	merge_sort(0, N);

	for (int i = 0; i < N; i++) cout << coordinate[i].x << " " << coordinate[i].y << "\n";
}