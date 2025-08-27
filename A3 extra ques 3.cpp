#include <iostream>
#include <stack>

using namespace std;

void nextGreaterElement(int arr[], int n) {
    vector<int> result(n, -1); 
    stack<int> st; 

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Next Greater Elements: ";
    nextGreaterElement(arr, n);

    return 0;
}


