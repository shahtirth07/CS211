//calc.cpp
//shah, tirth
//tshah

#include <cmath>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "dstack.h"

using namespace std;

//this function checks that input provided is valid number format or not.
bool isValidNumber(const string &input) {
    if (count(input.begin(), input.end(), '.') > 1) {
        return false;
    }
    if (input.empty() || (input == ".")) {
        return false;
    }
    return true;
}

Dstack dstack;

//main function
int main() {

    while (cin.peek() != EOF) {
        if (isspace(cin.peek())) {
            cin.ignore();
        } 
        else if (isdigit(cin.peek()) || cin.peek() == '.') { //checks for a digit or a '.' and allows if it is a floating point number.
            string input;
            while (isdigit(cin.peek()) || cin.peek() == '.') { // Read until whitespace or operator
                input += cin.get();
            }
            if (!isValidNumber(input)) { // Validate the number
                cerr << "Error: Invalid expression." << endl;
                return 1;
            }
            double number = stod(input); // Convert to double and push onto the stack
            dstack.push(number);
        } else if (strchr("+-*/^", cin.peek())) { //checks with peek method if the top of the stack contains any of the operators.
            char op;
            cin >> op;

            if (dstack.size() < 2) {
                cerr << "Error: Invalid expression." << endl;
                return 1;
            }
            double right = dstack.top();
            dstack.pop(&right);
            double left = dstack.top();
            dstack.pop(&left);
            double result;

            switch (op) { // performs all the arithmetic required.
                case '+': result = left + right; break;
                case '-': result = left - right; break;
                case '*': result = left * right; break;
                case '/':
                    if (right == 0) {
                        cerr << "Error: Invalid expression." << endl;
                        return 1;
                    }
                    result = left / right;
                    break;
                case '^': result = pow(left, right); break;
                default:
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
            }
            dstack.push(result); // pushes the result back into the stack.
        } else {
            cerr << "Error: Invalid expression." << endl;
            return 1;
        }
    }

    if (dstack.size() == 1) { // befor printing the result checks whether the stack has only single element. else throws error.
        double result = dstack.top();
        cout << result << endl;
        dstack.pop(&result);
    } else {
        cerr << "Error: Invalid expression." << endl;
        return 1;
    }
    return 0;
}