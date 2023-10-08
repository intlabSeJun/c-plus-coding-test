/*
재귀적으로 DFS 수행, 트리 한쪽의 끝까지 도달한 후 return하면서 수행한다.
- check[] 배열로 현재 트리의 상태를 체크한다.
- 트리의 가장 깊은 곳까지 도달시 return한다
- 현재 상태의 트리의 sum() == S 맞는지 확인하여 count.
- 현재 상태 i의 check[i]=0으로 만들어주고 return.
- 이전 트리의 상태에서 또 다시 sum() == S 여부 확인 및 count.
- 모든 트리를 탐색한다 (완전탐색).
*/
#include<iostream>
using namespace std;

int N, S;
int arr[22];
bool check[22] = {};
int cnt = 0;

void sum() { //현재까지의 수를 더해서 맞는지 확인
	int total = 0;
	for (int i = 0; i < N; i++) 
		if (check[i]) total += arr[i];

	if (total == S) cnt++;
}

void func(int x) { 
	if (x == N) // 재귀 브래킹 포인트
		return;

	for (int i = x; i < N; i++) { 
		// x부터 반복해서 재귀적으로 DFS 수행
		// 트리의 가장 깊은 곳부터 차례로 return하면서 sum구함
		check[i] = 1; 
		func(i+1);
		sum();
		check[i] = 0;
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++) cin >> arr[i];

	func(0);

	cout << cnt;
}