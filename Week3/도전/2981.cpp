#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수 구하는 함수 (유클리드 호제법)
int getGcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // 숫자들의 차이 구하기
    vector<int> diffs;
    for (int i = 1; i < n; i++) {
        diffs.push_back(abs(numbers[i] - numbers[i - 1]));
    }

    // 차이들의 최대공약수 구하기
    int gcd = diffs[0];
    for (int i = 1; i < diffs.size(); i++) {
        gcd = getGcd(gcd, diffs[i]);
    }

    // GCD의 약수 찾기
    vector<int> result;
    for (int i = 2; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            result.push_back(i);
            if (i != gcd / i) {
                result.push_back(gcd / i);
            }
        }
    }
    result.push_back(gcd); // GCD 자체도 M이 될 수 있음

    // 정렬 후 출력
    sort(result.begin(), result.end());
    for (int m : result) {
        cout << m << " ";
    }
    cout << "\n";

    return 0;
}
