#include <iostream>
using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;

    int year = 1; // 첫 해는 (1,1,1)
    int a = 1, b = 1, c = 1; // 현재 (E, S, M) 값

    while (true) {
        if (a == e && b == s && c == m) break; // 원하는 값 찾으면 종료
        
        year++; // 1년 증가
        a = (a % 15) + 1; // 15 넘으면 1로
        b = (b % 28) + 1; // 28 넘으면 1로
        c = (c % 19) + 1; // 19 넘으면 1로
    }

    cout << year << "\n";
    return 0;
}
