#include<iostream>
#include<stack>
using namespace std;

bool check_redundent(string str)
{
    stack<char>s;
    for(int i = 0 ;i < str.length();i++)
    {
        char ch = str[i];
        if((ch == '(') || (ch =='+') || (ch == '-') || (ch == '*') || (ch == '/'))
        {
            s.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                bool is_redundent = true;
                while (s.top() != '(')
                {
                    int top = s.top();
                    if((top == '(') || (top =='+') || (top == '-') || (top == '*') || (top == '/'))
                    {
                        is_redundent = false;
                    }
                    s.pop();
                }

                if(is_redundent == true)
                {
                    return true;
                }
                s.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "(a*(b+c))";
    cout<<check_redundent(str);
}

// 0 if not redundent else 1.