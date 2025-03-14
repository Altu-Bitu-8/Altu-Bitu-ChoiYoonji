#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string &s) {
    stack<char> st;
    
    for (char ch : s) {
        if (ch == '(' || ch == '[') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
        } else if (ch == ']') {
            if (st.empty() || st.top() != '[') return false;
            st.pop();
        }
    }
    
    return st.empty();
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == ".") break;
        
        cout << (isBalanced(line) ? "yes" : "no") << "\n";
    }
    
    return 0;
}
