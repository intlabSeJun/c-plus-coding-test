#include<iostream>
using namespace std;

template <typename T>

class queue {
private:
	T data[1000];
	int first_point, last_point;
public:
	queue() { 
		first_point = 0;
		last_point = 0;
	}
	~queue() {}

	void push(T new_data) {
		data[last_point++] = new_data;
	}

	void pop() {
		first_point++;
	}

	bool empty() {
		return last_point < 0;
	}

	T front() {
		return data[first_point];
	}

	int size() {
		return last_point - first_point + 1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;

	Q.push(3);
	Q.push(2);
	cout << Q.front() << "\n";  // 3
	cout << Q.size() << "\n";  // 3
	cout << Q.empty() << "\n";  // 0

	Q.pop();
	cout << Q.front() << "\n";  // 2
	cout << Q.size() << "\n";  // 2
	cout << Q.empty() << "\n";  // 0
}