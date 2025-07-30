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
                stack[++top] = s[i];  
            } else {
                if (top == -1) return false; 

                char ele_top = stack[top];
              
                if ((s[i] == ')' && ele_top == '(') ||
                    (s[i] == '}' && ele_top == '{') ||
                    (s[i] == ']' && ele_top == '[')) {
                    top--;  
                } else {
                    return false; 
                }
            }
        }

        return top == -1;  
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
