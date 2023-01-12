#include<iostream>
#include<stack>
using namespace std;

bool isvalid_paranthesis(string expression)
{
    stack<char>s;
    for(int i = 0 ; i < expression.length(); i++)
    {
        char ch = expression[i];
        if(ch == '[' || ch == '{' || ch == '(')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty())
            {
                char ele = s.top();
                if((ele == '{' && ch == '}') || (ele == '(' && ch == ')') || (ele == '[' && ch == ']'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    
    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string expr = "[]{}()";
    cout<<isvalid_paranthesis(expr);
}