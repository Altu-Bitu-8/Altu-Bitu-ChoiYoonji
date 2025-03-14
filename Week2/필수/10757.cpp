#include <iostream>
#include <string>

using namespace std;

string addLargeNumbers(string a, string b) {
    string result = "";
    int carry = 0, sum;
    int i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }
    
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    
    cout << addLargeNumbers(a, b) << "\n";
    return 0;
}