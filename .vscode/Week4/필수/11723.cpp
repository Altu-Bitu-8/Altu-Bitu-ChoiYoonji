#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    int S = 0; // 비트마스크 집합
    while (m--) {
        string cmd;
        int x;
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1)); // x번째 비트를 1로 설정
        }
        else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1)); // x번째 비트를 0으로 설정
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << "\n"; // x번째 비트가 1인지 확인
        }
        else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1)); // x번째 비트를 반전
        }
        else if (cmd == "all") {
            S = (1 << 20) - 1; // 20개의 비트를 모두 1로 설정
        }
        else if (cmd == "empty") {
            S = 0; // 모든 비트를 0으로 설정 (공집합)
        }
    }
    return 0;
}
