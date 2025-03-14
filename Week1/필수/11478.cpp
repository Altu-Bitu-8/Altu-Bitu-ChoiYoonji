#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    set<string> substrings;
    
    int length = s.length();
    for (int i = 0; i < length; ++i) {
        for (int j = 1; j <= length - i; ++j) {
            substrings.insert(s.substr(i, j));
        }
    }
    
    cout << substrings.size() << endl;
    return 0;
}
