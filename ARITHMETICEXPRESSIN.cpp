#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

// Function to determine operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to perform arithmetic operations
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);  // Use int casting for result
        default: return 0;
    }
}

// Function to convert infix to postfix expression
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";
    int i = 0;

    while (i < infix.length()) {
        char ch = infix[i];

        // If character is a digit (part of a multi-digit number)
        if (isdigit(ch)) {
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' '; // space to separate numbers
        }
        // If character is '(' push to stack
        else if (ch == '(') {
            operators.push(ch);
            i++;
        }
        // If character is ')'
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // pop '(' from stack
            i++;
        }
        // If the character is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
            i++;
        }
    }

    // Pop all remaining operators in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> operands;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            operands.push(stoi(token)); // Convert string to integer
        } else {
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            int result = applyOperation(a, b, token[0]);
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string infix;
    cout << "Enter an arithmetic expression in infix form (e.g., 3 + 5 * (2 - 8)): ";
    getline(cin, infix);  // Read the entire line for the expression

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}

