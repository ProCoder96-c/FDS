#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char a) {
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) 
     {
        char c = s[i];

        // If operand, add to result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            res += c;

        // If '(', push to stack
        else if (c == '(')
            st.push(c);

        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) 
            {
                st.pop();
            }
             // pop '('
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string expr = "(a-b/c)*(a/k-l)";
    cout << "Infix Expression: " << expr << endl;
    cout << "Postfix Expression: " << infixToPostfix(expr) << endl;
    return 0;
}
