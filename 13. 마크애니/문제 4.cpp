#include<iostream>
using namespace std;

int min_iter = 9999999;
int N, N_scope;
int square_table[320];
int count_nums[320] = {};

int find_scope() {
    for (int i = 1; i < N; i++) {
        if (i * i > N) return i - 1;
    }
}

void make_square_table() {
    for (int i = 0; i < 320; i++) {
        square_table[i] = i * i;
    }
}

void func(int k, int value) {
    int value_buf = 0;
    for (int i = 1; i <= N_scope; i++) {

        if (count_nums[i] == 3) {
            return;
        }
        count_nums[i]++;

        value_buf = value + square_table[i];
        //cout << k << " " << value_buf << "\n";
        if (value_buf == N && k < min_iter) {
            min_iter = k;
            count_nums[i]--;
            return;
        }
        else if (value_buf > N) {
            count_nums[i]--;
            return;
        }
        func(k + 1, value_buf);
        count_nums[i]--;
    }
}

int solution(int n)
{
    N = n;
    N_scope = find_scope();
    make_square_table();

    func(1, 0);

    return min_iter;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;
    solution(x);
    cout << min_iter;
}