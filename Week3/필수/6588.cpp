#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void goldbach(int n) {
    for (int a = 3; a <= n / 2; a += 2) {
        int b = n - a;
        if (is_prime[a] && is_prime[b]) {
            cout << n << " = " << a << " + " << b << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(); // 소수 미리 계산

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        goldbach(n);
    }

    return 0;
}
