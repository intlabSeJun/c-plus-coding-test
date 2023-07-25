#include<iostream>
using namespace std;


int const arr_size = 3;
int const size = 4; // size라는 이름 때문인지 "모호하다" 에러가 남.

void change_arr_value(int arr[], int *arr2) { // 원본 배열 값에 접근.
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
	//int arr[size] = {}; // size라는 이름 때문인지 "모호하다" 에러가 남.

	print_arr(arr); // 0 0 0
	change_arr_value(arr, arr);
	print_arr(arr);  // -1 -2 0


	// 배열의 모든 값을 특정 값으로 초기화 하기 위해서.
	// 1. 반복문으로 값 모두 할당. 
	set_arr(arr, 3);
	print_arr(arr);  // 3 3 3

	// 2. fill(arr, arr+len, value) 이용.
	fill(arr, arr + arr_size, 10);
	print_arr(arr);  // 10 10 10
}