#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s,int element)
{
   
        if(s.empty())
        {
            s.push(element);
            return;
        }

        int x = s.top();
        s.pop();
        solve(s,element);
        s.push(x);



    
}
int main()
{
    stack<int>s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);
    cout<<"size="<<s.size();
    cout<<endl;
    int element = 10;
    solve(s,element);
    cout<<"size="<<s.size();
}