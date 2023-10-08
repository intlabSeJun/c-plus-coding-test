#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 순열
	// 주의 사항, 입력으로는 배열 혹은 벡터여야 하고, 
	//            오름차순으로 정렬되어 있어야 모든 순열을 출력함
	int a[3] = { 0,2,3 };
	do {
		for (int i = 0; i < 3; i++)
			cout << a[i];
		cout << "\n";
	} while (next_permutation(a, a + 3));

	int a4[4] = { 3,2,1,0 };
	sort(a4, a4 + 4); // 간단히 정렬 가능
	for (int e : a4)cout << e << " ";
	cout << "\n\n";

	// 조합
	// 연속된 수에서의 특정 개수의 순열 출력
	int b[4] = { 0,0,1,1 };
	do {
		for (int i = 0; i < 4; i++) {
			if (b[i] == 0)
				cout << i + 1;
		}
		cout << "\n";
	} while (next_permutation(b, b + 4));
	cout << "\n";

	// 연속되지 않은 수에서의 특정 개수의 순열 출력
	int c[4] = { 0,0,1,1 };
	int d[4] = { -2,-1,1,2 };
	do {
		for (int i = 0; i < 4; i++) {
			if (c[i] == 0)
				cout << d[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(c, c + 4));
}