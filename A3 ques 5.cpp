#include <iostream>
#include <stack>
#include <cctype> 
using namespace std;

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; 
    }
    return 0;
}

int evaluatePostfix(string expr) {
    stack<int> st;
    
    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0');  
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = applyOperation(a, b, ch);
            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter Postfix Expression (e.g. 231*+9-): ";
    cin >> expr;

    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}

