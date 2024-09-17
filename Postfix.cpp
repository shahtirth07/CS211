#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if(op == '*') {
        return 2;
    }
    else if(op == '/') {
        return 3;
    }
    return -1;
}

bool isOperator(char op) {
    return op=='+' || op=='-' || op=='*' || op=='/';
}

int evaluatePostfix(string postfix) {
    stack<int> s1;
    for (char c:postfix) {
        if (isspace(c)) {
            continue;
        }
        if (!isOperator(c)) {
            s1.push(c-'0');
        }
        else {
            int operand2 = s1.top(); s1.pop();
            int operand1 = s1.top(); s1.pop();
            switch (c) {
                case '+':
                s1.push(operand2 + operand1);
                break;
                case '-':
                s1.push(operand1 - operand2);
                break;
                case '*':
                s1.push(operand2 * operand1);
                break;
                case '/':
                s1.push(operand1 / operand2);
                break;
            }
        }
    }
    return s1.top();
}

string infixToPostfix(string infix) {
    stack<char> s1;
    string postfix;
    for(char c:infix) {
        if(isOperator(c)) {
            while(!s1.empty() && precedence(s1.top()) >= precedence(c)) {
                postfix = postfix + s1.top();
                s1.pop();
            }
            s1.push(c);
        }
        else {
            postfix = postfix + c;
        }
        // return postfix;
    }
    while(!s1.empty()) {
        postfix = postfix + s1.top();
        s1.pop();
    }
    return postfix;
}

int main() {
    string infix = "6+4*8-3/3";
    string postfix = infixToPostfix(infix);
    int res = evaluatePostfix(postfix);
    cout << "The Result is " << res << endl;
    return 1;
}