/*Task # 01:
Write a recursive function to check if a given string is a palindrome.
Input: madam
Output: Yes, it is a palindrome*/
#include <iostream>
#include <string>
using namespace std;

bool Palindromechecker(string str, int start, int end) {
    if (start >= end) {
        return true;
    }
    
    if (str[start] != str[end]) {
        return false;
    }
    
    return Palindromechecker(str, start + 1, end - 1);
}

int main() {
    string word;
    int len;
    cout << "RECURSIVE PALINDROME CHECKER" << endl;

    cout << "Input: ";
    cin >> word;

    len = word.length();

    if (Palindromechecker(word, 0, len - 1)) {
        cout << "Output: Yes, it is a palindrome" << endl;
    } else {
        cout << "Output: No, it is not a palindrome" << endl;
    }

    return 0;
}
