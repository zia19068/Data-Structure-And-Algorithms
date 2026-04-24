#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return findGCD(b, a % b);
}

int main() {
    int num1, num2, result;
    cout << "RECURSIVE GCD CALCULATOR" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    result = findGCD(num1, num2);
    cout << "Input: " << num1 << ", " << num2 << endl;
    cout << "Output: " << result << endl;
    return 0;
}
