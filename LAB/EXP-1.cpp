#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

// Function to check operator precedence
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Convert Infix to Postfix
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Evaluate Postfix Expression
int evaluatePostfix(string postfix)
{
    stack<int> s;

    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '^':
                s.push(pow(a, b));
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    int N;
    cout << "Enter stack size: ";
    cin >> N;

    int stackArr[100];
    int top = -1;

    int choice, value;

    do
    {
        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. Display Stack";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (top == N - 1)
            {
                cout << "Stack Overflow\n";
            }
            else
            {
                cout << "Enter value: ";
                cin >> value;
                stackArr[++top] = value;
            }
            break;

        case 2:
            if (top == -1)
            {
                cout << "Stack Underflow\n";
            }
            else
            {
                cout << "Deleted element: " << stackArr[top--] << endl;
            }
            break;

        case 3:
            if (top == -1)
            {
                cout << "Stack is Empty\n";
            }
            else
            {
                cout << "Stack Contents: ";
                for (int i = top; i >= 0; i--)
                {
                    cout << stackArr[i] << " ";
                }
                cout << endl;
            }
            break;
        }
    } while (choice != 4);

    // Infix to Postfix Conversion
    string infix;
    cout << "\nEnter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    // Postfix Evaluation
    string exp;
    cout << "\nEnter Postfix Expression with single-digit operands: ";
    cin >> exp;

    cout << "Evaluated Result: " << evaluatePostfix(exp) << endl;

    return 0;
}