#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 소수 판별 (에라토스테네스의 체)
vector<bool> getPrimeList(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// 각 자리수의 제곱합 구하기
int getSquareSum(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

// 상근수 판별
bool isSanggeun(int num) {
    unordered_set<int> visited;
    while (num != 1 && visited.find(num) == visited.end()) {
        visited.insert(num);
        num = getSquareSum(num);
    }
    return num == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> isPrime = getPrimeList(n);

    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && isSanggeun(i)) {
            cout << i << "\n";
        }
    }

    return 0;
}
