/*
라딕스 소트
- 0~9까지의 리스트 생성
- 1의 자리 값에 따라 각 리스트에 연결 -> 0부터 순차적으로 나열
- 10의 자리 값에 따라 각 리스트에 연결 -> 순차적 나열
- N의 자리까지 수행하면 정렬 완성

- 리스트를 사용하기에 STL이 필요하다고 함.

*/
#include<iostream>
#include<vector>
using namespace std;

int n = 15;  // 비교할 개수
int arr[1000001] = {};  // 값 들어 있는 배열
int d = 3;  // 비교할 자리수 개수
int p10[3];  // 비교할 자리수 1,10,100 저장할 예정

int digitNum(int x, int a) { // 값, 자리수 정보
	return (x / p10[a]) % 10;  // 해당 자리수의 값 구함
}

vector<int> l[10];  // 리스트 0~9까지

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	p10[0] = 1;
	for (int i = 1; i < d; i++) p10[i] = p10[i - 1] * 10; // 10,100 저장
	for (int i = 0; i < d; i++) {  // 각 자리수마다 비교해서 정렬
		for (int j = 0; j < 10; j++) l[j].clear(); // 리스트 비워주고
		for (int j = 0; j < n; j++) // 자리수에 따른 값 리스트에 저장.
			l[digitNum(arr[j], i)].push_back(arr[j]);
		int aidx = 0;
		for (int j = 0; j < 10; j++) { // 다시 원래 배열에 저장
			for (auto x : l[j]) arr[aidx++] = x;  // 리스트에서 순차적으로 저장
		}
	}
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}