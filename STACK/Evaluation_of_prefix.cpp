#include <bits/stdc++.h>
using namespace std;

int evaluate(string prefix)
{
    stack<int> st;

    //adding this step

    reverse(prefix.begin(),prefix.end());

    for (char ch : prefix)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');   //ASCII VALUE-'0'.
        }
        else
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            int solve;

            switch (ch)
            {
                case '+':
                    solve = a + b;
                    break;

                case '-':
                    solve = a - b;
                    break;

                case '*':
                    solve = b * a;
                    break;

                case '/':
                    solve = a / b;
                    break;

                case '^':
                    solve = pow(a,b);
                    break;

                default:
                    cout << "Invalid operator!" << endl;
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

    cout << "Enter any prefix expression: ";
    cin >> s;

    int output = evaluate(s);

    cout << "Answer: " << output << endl;

    return 0;
}