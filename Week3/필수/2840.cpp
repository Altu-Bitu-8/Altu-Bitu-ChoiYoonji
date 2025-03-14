#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> wheel(n, '?');
    vector<bool> used(26, false);
    int currentIndex = 0;

    for (int i = 0; i < k; i++) {
        int s;
        char letter;
        cin >> s >> letter;

        currentIndex = (currentIndex - s % n + n) % n;

        if (wheel[currentIndex] != '?' && wheel[currentIndex] != letter) {
            cout << "!\n";
            return 0;
        }

        if (wheel[currentIndex] == '?' && used[letter - 'A']) {
            cout << "!\n";
            return 0;
        }

        wheel[currentIndex] = letter;
        used[letter - 'A'] = true;
    }

    for (int i = 0; i < n; i++) {
        cout << wheel[(currentIndex + i) % n];
    }
    cout << "\n";

    return 0;
}
