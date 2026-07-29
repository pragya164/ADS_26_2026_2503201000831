#include <bits/stdc++.h>
using namespace std;

int evaluate(string postfix)
{
    stack<int> st;

    for(char ch : postfix)
    {
        if(isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            int solve;

            switch(ch)
            {
                case '+':
                    solve = b + a;
                    break;

                case '-':
                    solve = b - a;
                    break;

                case '*':
                    solve = b * a;
                    break;

                case '/':
                    solve = b / a;
                    break;

                case '^':
                    solve = pow(b, a);
                    break;

                default:
                    cout << "Invalid Operator!" << endl;
                    return -1;
            }

            st.push(solve);
        }
    }

    return st.top();
}

int main()
{
    string s;

    cout << "Enter postfix expression: ";
    cin >> s;

    cout << "Answer: " << evaluate(s) << endl;

    return 0;
}