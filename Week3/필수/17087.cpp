#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 두 수의 최대 공약수를 구하는 함수
int getGcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    // 수빈이와 각 동생들의 거리 차이를 저장하는 배열
    vector<int> distances(n);
    for (int i = 0; i < n; i++) {
        distances[i] = abs(positions[i] - s);
    }

    // 모든 거리의 최대 공약수를 구함
    int maxD = distances[0];
    for (int i = 1; i < n; i++) {
        maxD = getGcd(maxD, distances[i]);
    }

    cout << maxD << "\n";
    return 0;
}
