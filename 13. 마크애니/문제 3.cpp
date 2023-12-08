#include<iostream>
#include<vector>
using namespace std;

#include <string>

using namespace std;
int arr2[20] = {};
int K, T, N, cnt = 0;
int check[20];


void print_arr() {
    for (int j = 0; j < N; j++) {
        cout << check[j] << " ";
    }
    cout << "\n";
}

void summation() {
    int sum_x = 0;
    for (int j = 0; j < N; j++) {
        if (check[j] == 1) {
            sum_x += arr2[j];
        }
    }
    if (sum_x <= T) {
        cnt++;
        print_arr();
    }
}

void func(int k, int n) {
    if (k == N) {
        summation();
        return;
    }
    if (k >= K) {
        summation();
    }
    
    for (int i = n; i < N; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            func(k + 1, i);
            check[i] = 0;
        }

    }
}

int solution(vector<int> arr, int k, int t) {
    for (int i = 0; i < arr.size(); i++)
        arr2[i] = arr[i];
    K = k;
    T = t;
    N = arr.size();

    func(0, 0);
    return cnt;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr;

    int x;
    for (int i = 0; i < 4; i++) {
        cin >> x;
        arr.push_back(x);
    }

    int k, t;
    cin >> k >> t;
    
    int ans;
    ans = solution(arr, k, t);
    cout << ans; 
}