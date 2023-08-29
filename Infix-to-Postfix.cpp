#include <iostream>
using namespace std;
int len = 100;
char stack[100];
int top = -1;
void push(char ch)
{
    if (top == len - 1)
    {
        cout << "Stack overflow" << endl;
        return;
    }Q
    else
    {
        top++;
        stack[top] = ch;
    }
}
char pop()
{
    if (top == -1)
    {
        cout << "stack underflow" << endl;
        return 'x';
    }
    else
    {Pp
        char c = stack[top];
        top--;
        return c;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string InfixtoPost(string pre)
{
    string post;
    for (int i = 0; i < pre.length(); i++)
    {
        char c = pre[i];
        switch (c)
        {
        case '(':
            push('(');
            break;
        case ')':
            while (stack[top] != '(')
            {
                post = post + stack[top];
                pop();
            }
            pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(c) <= precedence(stack[top]))
            {
                post = post + stack[top];
                pop();
            }
            push(c);
            break;
        default:
            post = post + c;
            break;
        }
    }
    while (!isEmpty())
    {
        post = post + stack[top];
        pop();
    }
    return post;
}
int main()
{
    string pre;
    cout << "Enter infix expression " << endl;
    cin >> pre;
    cout << InfixtoPost(pre);
    return 0;
}
