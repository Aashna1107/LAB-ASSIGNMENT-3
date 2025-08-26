#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> st; 
    long long minElement;

public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            minElement = x;
        }
        else if (x >= minElement) {
            st.push(x);
        }
        else {
           
            st.push(2LL * x - minElement);
            minElement = x;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < minElement) {
          
            minElement = 2LL * minElement - top;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long top = st.top();
        return (top < minElement) ? minElement : top;
    }

    int getMin() {
        if (st.empty()) return -1;
        return minElement;
    }

    bool empty() {
        return st.empty();
    }
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << "Min: " << s.getMin() << endl; 
    s.push(2);
    s.push(1);
    cout << "Min: " << s.getMin() << endl; 
    s.pop();
    cout << "Min: " << s.getMin() << endl; 
    s.pop();
    cout << "Top: " << s.top() << endl;    
    cout << "Min: " << s.getMin() << endl; 
}

