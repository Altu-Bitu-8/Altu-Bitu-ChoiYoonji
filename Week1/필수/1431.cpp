#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// 숫자 합 구하기 함수
int getDigitSum(const string& serial) {
    int sum = 0;
    for (char ch : serial) {
        if (isdigit(ch)) {
            sum += ch - '0';
        }
    }
    return sum;
}

// 정렬 조건 정의
bool serialComparator(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    int sumA = getDigitSum(a);
    int sumB = getDigitSum(b);
    if (sumA != sumB) {
        return sumA < sumB;
    }
    return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<string> serials(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> serials[i];
    }
    
    sort(serials.begin(), serials.end(), serialComparator);
    
    for (const string& serial : serials) {
        cout << serial << "\n";
    }
    
    return 0;
}
