#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int stack[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        stack[++top] = value;
        cout << value << " pushed.\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << stack[top--] << " popped.\n";
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top: " << stack[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Elements: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    while (1) {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Value: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) s.pop();
        else if (choice == 3) s.peek();
        else if (choice == 4) s.display();
        else if (choice == 5) break;
    }
    return 0;
}
