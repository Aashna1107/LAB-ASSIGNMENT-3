#include <iostream>
#include <stack>
#include <string>
using namespace std;


string reverseString(const string& str) {
    stack<char> st;

   
    for (size_t i = 0; i < str.size(); ++i) {
        st.push(str[i]);
    }

   
    string reversed;
    reversed.reserve(str.size());
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

int main() {
    string s;
    cout << "Enter a string: ";
    
    getline(cin, s);

    cout << "Reversed string: " << reverseString(s) << "\n";
    return 0;
}

