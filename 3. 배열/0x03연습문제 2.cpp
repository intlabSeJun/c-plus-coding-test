/*
�־��� ���� N�� int�迭 arr���� ���� 100�� ���� �ٸ� ��ġ�� �� ���Ұ� �����ϸ� 1��,
�������� ������ 0�� ��ȯ�ϴ� �Լ� func2(int arr[], int N)�� �ۼ��϶�.
arr�� �� ���� 0 �̻� 100 �����̰� N�� 1000 �����̴�. 

func2({1,52,48}, 3)=1,
func2({50,42},2} = 0,
func2({4,13,63,87},4) =1
*/
#include<iostream>
#include<vector>
using namespace std;


int func2(int arr[], int len) {
	vector<int> v(100, 0);
	int x;
	for (int i = 0; i < len; i++) {
		x = 100 - arr[i];
		if (v[x] == 1) return 1;
		else v[arr[i]] = 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	int arr[] = { 1,52,48 };
	cout << func2(arr, 3) << "\n";

}
