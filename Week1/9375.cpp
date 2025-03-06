#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int T;  // 테스트 케이스의 수
    cin >> T;
    while (T--) {
        int n;  // 의상의 수
        cin >> n;
        unordered_map<string, int> clothes;  // 의상 종류별 개수 저장
        for (int i = 0; i < n; ++i) {
            string name, category;
            cin >> name >> category;
            clothes[category]++;  // 해당 의상 종류의 개수 증가
        }
        int result = 1;
        for (auto& c : clothes) {
            result *= (c.second + 1);  // 의상 종류마다 입을 수 있는 경우는 (개수 + 1)
        }
        cout << result - 1 << endl;  // 알몸인 경우 제외하고 출력
    }
    return 0;
}