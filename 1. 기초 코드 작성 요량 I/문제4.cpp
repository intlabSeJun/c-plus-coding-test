/* ����4
* N������ �� �߿��� ���� ū 2�� �ŵ��������� ��ȯ�ϴ� �Լ� func4(int N)�� �ۼ��϶�
* N�� 10�� ������ �ڿ����̴�.
* 
* ��� ����
* func4(5) = 4,
* func4(97615282) = 67108864,
* func4(1024) = 1024
*/
#include <iostream>
using namespace std;


int func4_official(int N) {  // �ð����⵵�� logN�� �ȴٰ� ��.
	int val = 1;
	while (2 * val <= N) val *= 2;
	return val;
}
int func4(int N) {  // ���� § �ڵ�
	if (N == 1) return 1;
	int out = 1;
	for (int i = 2; i <= N;) {
		if (out * i > N) return out;
		else if (out * i == N) return out * i;
		else out = out * i;
	}
}

int main() {
	int arr[] = { 5, 97615282, 1024 };
	int length_arr = sizeof arr / sizeof arr[0];
	for (int i = 0; i < length_arr; i++) {
		cout << "func4(" << arr[i] << ") = " << func4(arr[i]) << endl;
	}
}