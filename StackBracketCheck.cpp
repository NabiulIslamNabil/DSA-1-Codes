#include<iostream>

using namespace std;

class Stack {
    int last;
    char arr[100];
public:
    Stack() {
        last = -1;
    }

    void push(char ch) {
        if (last + 1 >= 100) {
            cout << "Stack Overflow" << endl;
        }
        else {
            last++;
            arr[last] = ch;
        }
    }

    void pop() {
        if (last == -1) {
            cout << "Stack Underflow" << endl;
        }
        else {
            last--;
        }
    }

    char top() {
        if (last != -1) {
            return arr[last];
        }
    }

    bool isEmpty() {
        return last == -1;
    }

    bool match(char o, char c) {
        return (o == '(' && c == ')') ||
               (o == '[' && c == ']') ||
               (o == '{' && c == '}');
    }
};

int main() {
    Stack s;
    string str;
    cout << "Enter the expression: ";
    cin >> str;

    int balanced = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (s.isEmpty() || !s.match(s.top(), str[i])) {
                balanced = -1;
                break;
            }
            else {
                s.pop();
            }
        }
    }

    if (!s.isEmpty()) {
        balanced = -1;
    }

    if (balanced==1) {
        cout << "Expression has balanced brackets." << endl;
    }
    else {
        cout << "Expression does not have balanced brackets." << endl;
    }

    return 0;
}
