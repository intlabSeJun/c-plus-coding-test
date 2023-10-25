#include<iostream>
#include<string>
using namespace std;

int N;

struct P {
	int age;
	string name;
};

P person_info[100005];
P tmp[100005];

void merge_sort(int st, int en) {
	if (st + 1 == en) return;
	
	int mid = (st + en) / 2;

	merge_sort(st, mid);
	merge_sort(mid, en);

	int L = st;
	int R = mid;
	for (int i = st; i < en; i++) {
		if (L == mid) tmp[i] = person_info[R++];
		else if (R == en) tmp[i] = person_info[L++];
		
		// 부등호 <= 일 경우 stable sort (같은 값이면 들어온 순서대로 정렬)
		else if (person_info[L].age <= person_info[R].age) tmp[i] = person_info[L++];
		else tmp[i] = person_info[R++];
	}

	for (int i = st; i < en; i++) person_info[i] = tmp[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> person_info[i].age >> person_info[i].name;
	}

	merge_sort(0, N);

	for (int i = 0; i < N; i++) {
		cout << person_info[i].age << " " << person_info[i].name << "\n";
	}
}	