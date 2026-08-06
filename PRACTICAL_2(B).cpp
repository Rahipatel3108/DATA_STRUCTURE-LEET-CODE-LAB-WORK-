#include <iostream>
using namespace std;


void callByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "\nInside Function (Value): a = " << a << ", b = " << b;

}


void callByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "\nInside Function (Reference): a = " << a << ", b = " << b;

}

int main() {
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "\n--- Call By Value ---";
    cout << "\nBefore Swap: x = " << x << ", y = " << y;
    callByValue(x, y);
    cout << "\nAfter Swap:  x = " << x << ", y = " << y << " (No Change)";

    cout << "\n\n--- Call By Reference ---";
    cout << "\nBefore Swap: x = " << x << ", y = " << y;
    callByReference(x, y);
    cout << "\nAfter Swap:  x = " << x << ", y = " << y << " (Values Swapped!)";

    cout << endl;
    return 0;
}

