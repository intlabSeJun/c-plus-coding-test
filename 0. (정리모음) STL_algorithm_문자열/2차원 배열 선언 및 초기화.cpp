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
	int arr[row][column] = {};  // �ʱ�ȭ�� 0���� ���õ�. 

	change_arr(arr, arr); // Ư�� �� �ʱ�ȭ
	print_arr(arr); // [[1 2 0] [0 0 0]]

	// 2���� �迭�� ��� ������ Ư�������� �����
	// 1. ���� �ݸ����� ������ �� �Ҵ� (����)
	
	// 2. fill()�� ����Ͽ� ������ �Ҵ�
	for (int i = 0; i < row; i++) fill(arr[i], arr[i] + column, 9);
	cout << "\n";
	print_arr(arr); // ��� 9�� �Ҵ��. [[9 9 9] [9 9 9]]
}