#include<iostream>
using namespace std;


int const row = 2;
int const column = 3;

void change_arr(int(*arr)[column], int arr2[][column]) {
	arr[0][0] = 1;
	arr2[0][1] = 2;
}
void print_arr(int (*arr)[column]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	int arr[row][column] = {};  // 초기화시 0으로 세팅됨. 

	change_arr(arr, arr); // 특정 값 초기화
	print_arr(arr); // [[1 2 0] [0 0 0]]

	// 2차원 배열의 모든 값들을 특정값으로 변경시
	// 1. 이중 반목문으로 일일이 값 할당 (생략)
	
	// 2. fill()을 사용하여 간단히 할당
	for (int i = 0; i < row; i++) fill(arr[i], arr[i] + column, 9);
	cout << "\n";
	print_arr(arr); // 모두 9로 할당됨. [[9 9 9] [9 9 9]]
}