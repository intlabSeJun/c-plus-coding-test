/*
문제
두 양의 정수가 주어졌을 때, 두 수 사이에 있는 정수를 모두 출력하는 프로그램을 작성하시오.

입력
두 정수 A와 B가 주어진다.

출력
첫째 줄에 두 수 사이에 있는 수의 개수를 출력한다.

둘째 줄에는 두 수 사이에 있는 수를 오름차순으로 출력한다.

서브태스크
번호	배점	제한
1	30
1 ≤ A, B ≤ 1000.

2	70
1 ≤ A, B ≤ 1015, A와 B의 차이는 최대 100,000.

예제 입력 1
8 14
예제 출력 1
5
9 10 11 12 13
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<long long> v(2);

	cin >> v[0] >> v[1];
	sort(v.begin(), v.end());
	
	if (v[0] == v[1] || v[1] - v[0] == 1) cout << 0;
	else {
		cout << v[1] - v[0] - 1 << "\n";
		for (long long i = v[0] + 1; i < v[1]; i++) cout << i << " ";
	}
}
