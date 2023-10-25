/*
코테에서는 stl sort를 사용하라는데,
경우에 따라 메모리, 시간에 따라서 merge sort를 사용하는게 좋아보이기도 한다.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[5] = { 3,2,15,0,9 };

bool cmp(int a, int b) {
	if (a != b) return a > b;
}

bool cmp(const string& a, const string& b) { // const 참조로 불러오는게 메모리 효율에 좋다
	return a.back() < b.back();
}

void print_arr() {
	for (int i = 0; i < 5; i++) cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	sort(arr, arr + 5); // 오름차순
	print_arr();
	sort(arr, arr + 5, cmp); // 내림차순 
	print_arr();
}