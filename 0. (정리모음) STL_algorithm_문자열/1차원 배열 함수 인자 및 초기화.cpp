#include<iostream>
using namespace std;


int const arr_size = 3;
int const size = 4; // size��� �̸� �������� "��ȣ�ϴ�" ������ ��.

void change_arr_value(int arr[], int *arr2) { // ���� �迭 ���� ����.
	arr[0] = -1;
	arr[1] = 2;
}

void print_arr(int arr[]) {
	for (int i = 0; i < arr_size; i++) cout << arr[i] << " ";
	cout << "\n";
}

void set_arr(int arr[], int value) {
	for (int i = 0; i < arr_size; i++) arr[i] = value;
}

int main() {
	int arr[arr_size] = {};
	//int arr[size] = {}; // size��� �̸� �������� "��ȣ�ϴ�" ������ ��.

	print_arr(arr); // 0 0 0
	change_arr_value(arr, arr);
	print_arr(arr);  // -1 -2 0


	// �迭�� ��� ���� Ư�� ������ �ʱ�ȭ �ϱ� ���ؼ�.
	// 1. �ݺ������� �� ��� �Ҵ�. 
	set_arr(arr, 3);
	print_arr(arr);  // 3 3 3

	// 2. fill(arr, arr+len, value) �̿�.
	fill(arr, arr + arr_size, 10);
	print_arr(arr);  // 10 10 10
}