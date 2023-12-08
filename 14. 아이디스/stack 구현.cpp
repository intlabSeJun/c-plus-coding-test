//#include<iostream>
//using namespace std;
//
//
//struct stack {
//	int arr[10000];
//	int last = -1;
//
//	void init() {
//		last = -1;
//	}
//
//	void push(int data) {
//		arr[++last] = data;
//	}
//	
//	bool empty() {
//		return last < 0;
//	}
//
//	int pop() {
//		if (empty()) {
//			return -1;
//		}
//		return arr[last--];
//	}
//
//	int size() {
//		return last + 1;
//	}
//
//	int top() {
//		if (empty()) {
//			return -1;
//		}
//		return arr[last];
//	}
//};
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	stack s;
//
//	s.init();
//	s.push(3);
//	cout << s.top() << "\n";  // 3
//	cout << s.size() << "\n";  // 1
//	s.pop();
//	cout << s.size();  // 0
//}
#include<iostream>
using namespace std;

template <typename T>

class stack {
private:
	T data[1000] = {};
	int cur_point;
public:
	stack(){
		cur_point = -1;
	}
	~stack(){}

	void push(T new_data) {
		cur_point++;
		data[cur_point] = new_data;
	}

	bool empty() {
		return cur_point < 0;
	}

	T pop() {
		return data[cur_point--];
	}

	T top() {
		return data[cur_point];
	}

	int size() {
		return cur_point+1;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;

	s.push(3);
	cout << s.top() << "\n";  // 3
	cout << s.size() << "\n";  // 1
	cout << s.empty() << "\n";  // 0

	s.pop();
	cout << s.size() << "\n";  // 0
}