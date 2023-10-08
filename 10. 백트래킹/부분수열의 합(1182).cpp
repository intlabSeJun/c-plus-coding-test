/*
��������� DFS ����, Ʈ�� ������ ������ ������ �� return�ϸ鼭 �����Ѵ�.
- check[] �迭�� ���� Ʈ���� ���¸� üũ�Ѵ�.
- Ʈ���� ���� ���� ������ ���޽� return�Ѵ�
- ���� ������ Ʈ���� sum() == S �´��� Ȯ���Ͽ� count.
- ���� ���� i�� check[i]=0���� ������ְ� return.
- ���� Ʈ���� ���¿��� �� �ٽ� sum() == S ���� Ȯ�� �� count.
- ��� Ʈ���� Ž���Ѵ� (����Ž��).
*/
#include<iostream>
using namespace std;

int N, S;
int arr[22];
bool check[22] = {};
int cnt = 0;

void sum() { //��������� ���� ���ؼ� �´��� Ȯ��
	int total = 0;
	for (int i = 0; i < N; i++) 
		if (check[i]) total += arr[i];

	if (total == S) cnt++;
}

void func(int x) { 
	if (x == N) // ��� �귡ŷ ����Ʈ
		return;

	for (int i = x; i < N; i++) { 
		// x���� �ݺ��ؼ� ��������� DFS ����
		// Ʈ���� ���� ���� ������ ���ʷ� return�ϸ鼭 sum����
		check[i] = 1; 
		func(i+1);
		sum();
		check[i] = 0;
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++) cin >> arr[i];

	func(0);

	cout << cnt;
}