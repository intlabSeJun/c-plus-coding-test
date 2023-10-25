/*
������Ʈ(Merge Sort)
- ��������� ������ ���� ������ �� ��ġ�� ���Ĺ�
- �� �迭�� ���ļ� ���ĵ� �迭�� �����. 
- O(NlogN)

�������� ������Ʈ�� ���
- �� �迭�� ���� ���� �͵鸸 ���ؼ�, ���� ���� �������� �迭�� ä�������� ��.
- ������, �� ���� �� �迭�� ������������ ����� ���� �Ѵ�. 

���� �������� ������Ʈ ����� ������ ����
- �迭�� ���� ����, 1������ ����� 2���� ���ϰ�, �̸� ������Ʈ�� �ݺ��ϸ鼭 �迭�� �ϼ��Ѵ�.
*/

// ���� �ٸ� �� �迭�� ������Ʈ �ϴ� �⺻ ����
// https://www.acmicpc.net/problem/11728
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int N, M;
//int arr1[1000005] = {};
//int arr2[1000005] = {};
//int arr3[1000005] = {};
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) cin >> arr1[i];
//	for (int i = 0; i < M; i++) cin >> arr2[i];
//
//	sort(arr1, arr1 + N);
//	sort(arr2, arr2 + M);
//
//	int k1 = 0, k2 = 0;
//
//	for (int i = 0; i < N + M; i++) {
//		if (k1 >= N) {
//			arr3[i] = arr2[k2++];
//		}
//		else if (k2 >= M) arr3[i] = arr1[k1++];
//		else {
//			if (arr1[k1] < arr2[k2]) arr3[i] = arr1[k1++];
//			else arr3[i] = arr2[k2++];
//		}
//	}
//
//	for (int i = 0; i < N + M; i++) cout << arr3[i] << " ";
//
//}


// �ϳ��� �迭�� ������Ʈ�� �̿��Ͽ� ������ �����ϴ� "������Ʈ ����"
#include<iostream>
using namespace std;

int n = 10;
int arr[1000005] = {};
int tmp[1000005];

void merge(int st, int en) {
	int mid = (st + en) / 2; // �߰����� ����
	int lidx = st; // �߰��������� ���� �迭�� ���� ó��
	int ridx = mid; // �߰��������� ������ �迭�� ���� ó��
	// �� �迭�� merge sort�ϴ� �Ͱ� �����ϴ�
	// ���⼭�� �迭�� 1�� �������� �ɰ��� merge sort�� bottom up ������� ����
	// ����, �߰��������� �迭�� �������� ��, �� ����/������ ������ ������ �Ǿ� �ִ� ������.
	for (int i = st; i < en; i++) { // lidx, ridx�� �������� ���� ���� ������ ���ϸ鼭 tmp�� ����
		if (ridx == en) tmp[i] = arr[lidx++]; // �߰����� ���� ������ �迭 ��� ����Ǿ����Ƿ�, ���� �迭�� �����ϸ� �ȴ�
		else if (lidx == mid) tmp[i] = arr[ridx++]; // �߰����� ���� ���� �迭 ��� ����Ǿ����Ƿ�, ������ �迭�� ����.

		// ���� �迭�� ���� ����(���� �ε���) ���鰣�� �񱳸� ���� ����.
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++]; // ���� �迭�� ���� ���� ���� �� ���� ��
		else tmp[i] = arr[ridx++]; // ������ �迭�� ���� ���� ���� �� ���� ��
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i]; // �ٽ� ���� �迭�� �־���
}

void merge_sort(int st, int en) {
	/*
	arr[st:en]������ ������ �����ϴ� �Լ�. st ~ en-1 ����.
	
	��������� ����Ǵ� �Լ��̸�, ���� ���� ������ 1������ ���ٰ� merge sort�ϸ鼭 bottom up �Ѵ�.
	*/
	if (en == st + 1) return; // ���Ϸ��� ���� 2���϶� return
	int mid = (st + en) / 2;
	merge_sort(st, mid); // ����
	merge_sort(mid, en); // ����
	merge(st, en);  // ���������� ����/������ �迭 ���Ͽ� ������Ʈ�Ѵ�. 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}