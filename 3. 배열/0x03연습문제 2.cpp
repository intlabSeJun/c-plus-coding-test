/*
주어진 길이 N의 int배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을,
존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
arr의 각 수는 0 이상 100 이하이고 N은 1000 이하이다. 

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
