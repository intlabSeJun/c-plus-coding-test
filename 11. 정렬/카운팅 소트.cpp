/*
수가 등장한 개수를 카운트하여, 출력하는 방법

수의 범위가 한정적인 경우에만 사용할 수 있음. 

*/

#include<iostream>
using namespace std;

int freq[200001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		freq[a + 1000000]++;
	}
	for (int i = 0; i <= 2000000; i++) {
		while (freq[i]--) {
			cout << i - 1000000 << "\n";
		}
	}
}