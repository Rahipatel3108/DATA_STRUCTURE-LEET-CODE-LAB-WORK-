#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {

        // Skip spaces
        if (ch == ' ') continue;

        // If operand (digit), push to stack
        if (isdigit(ch)) {
            st.push(ch - '0'); // convert char to int
        }

        // If operator, pop two operands and apply
        else {
            if (st.size() < 2) {
                cout << "Invalid postfix expression!" << endl;
                return -1;
            }

            int b = st.top(); st.pop(); // second operand
            int a = st.top(); st.pop(); // first operand

            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Error: Division by zero!" << endl;
                        return -1;
                    }
                    st.push(a / b);
                    break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < b; i++) result *= a;
                    st.push(result);
                    break;
                }
                default:
                    cout << "Unknown operator: " << ch << endl;
                    return -1;
            }
        }
    }

    // Final result should be the only element left
    if (st.size() != 1) {
        cout << "Invalid postfix expression!" << endl;
        return -1;
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    if (result != -1)
        cout << "Result: " << result << endl;

    return 0;
}
