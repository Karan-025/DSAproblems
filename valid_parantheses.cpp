#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char stack[10000];
        int top = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack[++top] = s[i];  // Push opening bracket
            } else {
                if (top == -1) return false;  // Stack empty, but found closing

                char ele_top = stack[top];
                // Check if top of stack matches the current closing bracket
                if ((s[i] == ')' && ele_top == '(') ||
                    (s[i] == '}' && ele_top == '{') ||
                    (s[i] == ']' && ele_top == '[')) {
                    top--;  // Valid pair found, pop from stack
                } else {
                    return false;  // Mismatched closing bracket
                }
            }
        }

        return top == -1;  // If stack is empty at end, it's valid
    }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter the bracket string: ";
    cin >> input;

    if (sol.isValid(input)) {
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Invalid parentheses" << endl;
    }

    return 0;
}
