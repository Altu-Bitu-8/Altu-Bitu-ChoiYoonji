#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    string S;
    cin >> S;
    set<string> substrings;
    int length = S.length();
    for (int i = 0; i < length; ++i) {
        for (int j = 1; j <= length - i; ++j) {
            substrings.insert(S.substr(i, j));
        }
    }
    cout << substrings.size() << endl;
    return 0;
}