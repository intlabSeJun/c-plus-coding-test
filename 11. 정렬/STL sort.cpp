/*
���׿����� stl sort�� ����϶�µ�,
��쿡 ���� �޸�, �ð��� ���� merge sort�� ����ϴ°� ���ƺ��̱⵵ �Ѵ�.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[5] = { 3,2,15,0,9 };

bool cmp(int a, int b) {
	if (a != b) return a > b;
}

bool cmp(const string& a, const string& b) { // const ������ �ҷ����°� �޸� ȿ���� ����
	return a.back() < b.back();
}

void print_arr() {
	for (int i = 0; i < 5; i++) cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	sort(arr, arr + 5); // ��������
	print_arr();
	sort(arr, arr + 5, cmp); // �������� 
	print_arr();
}