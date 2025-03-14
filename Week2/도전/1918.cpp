#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string &expr) {
    string result;
    stack<char> st;
    
    for (char ch : expr) {
        if (isalpha(ch)) {
            result += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        } else { // Operator
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    string expr;
    cin >> expr;
    cout << infixToPostfix(expr) << "\n";
    return 0;
}
