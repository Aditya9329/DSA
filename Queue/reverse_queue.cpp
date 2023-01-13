#include<iostream>
using namespace std;
#include<queue>
#include<stack>
int main()
{
    stack<int>s;
    queue<int>q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    cout<<q.front();
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    cout<<q.front();
}